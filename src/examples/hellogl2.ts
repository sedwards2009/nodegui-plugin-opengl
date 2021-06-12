import { EventEmitter } from 'events';
import { mat3, mat4, vec3 } from 'gl-matrix';
import {
  Direction,
  MouseButton,
  Orientation,
  QBoxLayout,
  QMainWindow,
  QMouseEvent,
  QSlider,
  QWidget,
  TickPosition,
  WidgetEventTypes,
} from '@nodegui/nodegui';

import {
  OpenGLContextProfile,
  QOpenGLBuffer,
  QOpenGLContext,
  QOpenGLShader,
  QOpenGLShaderProgram,
  QOpenGLVertexArrayObject,
  QOpenGLWidget,
  QSurfaceFormat,
} from '..'

const log = console.log.bind(console);

class MainWindow {
  private _qMainWindow: QMainWindow;

  private _glWidget: GLWidget;
  private _xSlider: QSlider;
  private _ySlider: QSlider;
  private _zSlider: QSlider;

  constructor() {
    this._qMainWindow = new QMainWindow();

    this._glWidget = new GLWidget();
    this._glWidget.getWidget().setMinimumSize(400, 400);

    this._xSlider = this._createSlider();
    this._ySlider = this._createSlider();
    this._zSlider = this._createSlider();

    this._xSlider.addEventListener('valueChanged', (value: number) => {
      this._glWidget.setXRotation(value);
    });
    this._ySlider.addEventListener('valueChanged', (value: number) => {
      this._glWidget.setYRotation(value);
    });
    this._zSlider.addEventListener('valueChanged', (value: number) => {
      this._glWidget.setZRotation(value);
    });

    this._glWidget.on('xRotationChanged', (x: number) => {
      this._xSlider.setValue(x);
    });
    this._glWidget.on('yRotationChanged', (y: number) => {
      this._ySlider.setValue(y);
    });
    this._glWidget.on('zRotationChanged', (z: number) => {
      this._zSlider.setValue(z);
    });

    const mainLayout = new QBoxLayout(Direction.TopToBottom);
    const container = new QBoxLayout(Direction.LeftToRight);
    container.addWidget(this._glWidget.getWidget());
    container.addWidget(this._xSlider);
    container.addWidget(this._ySlider);
    container.addWidget(this._zSlider);

    const w = new QWidget();
    w.setLayout(container);
    mainLayout.addWidget(w);

    const top = new QWidget();
    top.setLayout(mainLayout);

    this._xSlider.setValue(15 * 16);
    this._ySlider.setValue(345 * 16);
    this._zSlider.setValue(0 * 16);

    this._qMainWindow.setWindowTitle('Hello GL');

    this._qMainWindow.setCentralWidget(top);
  }

  private _createSlider(): QSlider {
    const slider = new QSlider();
    slider.setOrientation(Orientation.Vertical);
    slider.setRange(0, 360 * 16);
    slider.setSingleStep(16);
    slider.setPageStep(15 * 16);
    slider.setTickInterval(15 * 16);
    slider.setTickPosition(TickPosition.TicksRight);
    return slider;
  }

  show(): void {
    // this._qMainWindow.resize(this._qMainWindow.sizeHint());
    this._qMainWindow.show();
  }
}

const vertexShaderSourceCore =
  '#version 150\n' +
  'in vec4 vertex;\n' +
  'in vec3 normal;\n' +
  'out vec3 vert;\n' +
  'out vec3 vertNormal;\n' +
  'uniform mat4 projMatrix;\n' +
  'uniform mat4 mvMatrix;\n' +
  'uniform mat3 normalMatrix;\n' +
  'void main() {\n' +
  '   vert = vertex.xyz;\n' +
  '   vertNormal = normalMatrix * normal;\n' +
  '   gl_Position = projMatrix * mvMatrix * vertex;\n' +
  '}\n';

const fragmentShaderSourceCore =
  '#version 150\n' +
  'in highp vec3 vert;\n' +
  'in highp vec3 vertNormal;\n' +
  'out highp vec4 fragColor;\n' +
  'uniform highp vec3 lightPos;\n' +
  'void main() {\n' +
  '   highp vec3 L = normalize(lightPos - vert);\n' +
  '   highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n' +
  '   highp vec3 color = vec3(0.39, 1.0, 0.0);\n' +
  '   highp vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);\n' +
  '   fragColor = vec4(col, 1.0);\n' +
  '}\n';

class GLWidget extends EventEmitter {
  private _widget: QOpenGLWidget = null;
  private _xRot = 0;
  private _yRot = 0;
  private _zRot = 0;
  private _program: QOpenGLShaderProgram = null;

  private _projMatrixLoc = -1;
  private _mvMatrixLoc = -1;
  private _normalMatrixLoc = -1;
  private _lightPosLoc = -1;
  private _vao: QOpenGLVertexArrayObject = null;
  private _logoVbo: QOpenGLBuffer = null;
  private _camera: mat4 = null;
  private _proj: mat4 = null;
  private _world: mat4 = null;
  private _logoVertexCount = 0;
  private _verts: number[] = null;

  private _lastMouseX = 0;
  private _lastMouseY = 0;

  constructor() {
    super();
    const core = QSurfaceFormat.defaultFormat().profile() == OpenGLContextProfile.CoreProfile;
    log(`Core profile: ${core}`);

    this._proj = mat4.create();
    this._world = mat4.create();

    (this._widget = new QOpenGLWidget()), this._widget.setMinimumSize(50, 50);
    this._widget.addEventListener('initializeGL', this._initializeGL.bind(this));
    this._widget.addEventListener('paintGL', this._paintGL.bind(this));
    this._widget.addEventListener('resizeGL', this._resizeGL.bind(this));

    this._widget.addEventListener(WidgetEventTypes.MouseButtonPress, (nativeEvent) => {
      this._handleMousePress(nativeEvent);
    });

    this._widget.addEventListener(WidgetEventTypes.MouseMove, (nativeEvent) => {
      this._handleMouseMove(nativeEvent);
    });
  }

  private _handleMousePress(nativeEvent): void {
    const event = new QMouseEvent(nativeEvent);
    this._lastMouseX = event.x();
    this._lastMouseY = event.y();
  }

  private _handleMouseMove(nativeEvent): void {
    const event = new QMouseEvent(nativeEvent);
    const dx = event.x() - this._lastMouseX;
    const dy = event.y() - this._lastMouseY;

    if ((event.buttons() & MouseButton.LeftButton) !== 0) {
      this.setXRotation(this._xRot - 8 * dy);
      this.setYRotation(this._yRot - 8 * dx);
      this.emit('xRotationChanged', this._xRot);
      this.emit('yRotationChanged', this._yRot);
    } else if ((event.buttons() & MouseButton.RightButton) !== 0) {
      this.setXRotation(this._xRot - 8 * dy);
      this.setZRotation(this._zRot + 8 * dx);
      this.emit('xRotationChanged', this._xRot);
      this.emit('zRotationChanged', this._zRot);
    }
    this._lastMouseX = event.x();
    this._lastMouseY = event.y();
  }

  getWidget(): QOpenGLWidget {
    return this._widget;
  }

  setXRotation(angle: number): void {
    angle = GLWidget.qNormalizeAngle(angle);
    if (angle !== this._xRot) {
      this._xRot = angle;
      this._widget.update();
    }
  }

  setYRotation(angle: number): void {
    angle = GLWidget.qNormalizeAngle(angle);
    if (angle !== this._yRot) {
      this._yRot = angle;
      this._widget.update();
    }
  }

  setZRotation(angle: number): void {
    angle = GLWidget.qNormalizeAngle(angle);
    if (angle != this._zRot) {
      this._zRot = angle;
      this._widget.update();
    }
  }

  static qNormalizeAngle(angle: number): number {
    while (angle < 0) {
      angle += 360 * 16;
    }
    while (angle > 360 * 16) {
      angle -= 360 * 16;
    }
    return angle;
  }

  cleanup(): void {
    // if (this._program == null) {
    //     return;
    // }
    // this._widget.makeCurrent();
    // this._logoVbo.destroy();
    // this._program.destroy();
    // this._program = null;
    // this._widget.doneCurrent();
  }

  private _initializeGL(): void {
    // In this example the widget's corresponding top-level window can change
    // several times during the widget's lifetime. Whenever this happens, the
    // QOpenGLWidget's associated context is destroyed and a new one is created.
    // Therefore we have to be prepared to clean up the resources on the
    // aboutToBeDestroyed() signal, instead of the destructor. The emission of
    // the signal will be followed by an invocation of initializeGL() where we
    // can recreate all resources.

    // connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GLWidget::cleanup);
    const gl = QOpenGLContext.currentContext().functions();
    gl.clearColor(0, 0, 0, 1);

    this._program = new QOpenGLShaderProgram();
    const isVertexShaderOk = this._program.addShaderFromSourceCode(QOpenGLShader.Vertex, vertexShaderSourceCore);
    if (!isVertexShaderOk) {
      log('failed to compile vertext shader! ', this._program.log());
    }

    const isFragmentShaderOK = this._program.addShaderFromSourceCode(
      QOpenGLShader.Fragment,
      fragmentShaderSourceCore,
    );
    if (!isFragmentShaderOK) {
      log('failed to compile fragment shader! ', this._program.log());
    }

    this._checkError(gl);

    this._program.bindAttributeLocation('vertex', 0);
    this._program.bindAttributeLocation('normal', 1);
    this._program.link();

    this._checkError(gl);

    this._program.bind();
    this._projMatrixLoc = this._program.uniformLocation('projMatrix');
    this._mvMatrixLoc = this._program.uniformLocation('mvMatrix');
    this._normalMatrixLoc = this._program.uniformLocation('normalMatrix');
    this._lightPosLoc = this._program.uniformLocation('lightPos');

    this._checkError(gl);

    // Create a vertex array object. In OpenGL ES 2.0 and OpenGL 2.x
    // implementations this is optional and support may not be present
    // at all. Nonetheless the below code works in all cases and makes
    // sure there is a VAO when one is needed.
    this._vao = new QOpenGLVertexArrayObject();
    this._vao.create();
    this._vao.bind();

    this._checkError(gl);

    // Setup our vertex buffer object.
    this._logoVbo = new QOpenGLBuffer();
    this._logoVbo.create();
    this._logoVbo.bind();
    this._verts = this._getLogoVertices();
    this._logoVertexCount = this._verts.length / 3 / 2;
    this._logoVbo.allocate(this._verts.length * Float32Array.BYTES_PER_ELEMENT);
    this._logoVbo.write(
      0,
      Float32Array.from(this._verts).buffer,
      this._verts.length * Float32Array.BYTES_PER_ELEMENT,
    );

    this._checkError(gl);

    // Store the vertex attribute bindings for the program.
    this._setupVertexAttribs();

    // Our camera never changes in this example.
    this._camera = mat4.create();
    mat4.identity(this._camera);
    mat4.translate(this._camera, this._camera, [0, 0, -1]);

    this._checkError(gl);

    // Light position is fixed.
    gl.uniform3fv(this._lightPosLoc, 1, [0, 0, 70]);

    this._program.release();
    this._vao.release();
  }

  private _setupVertexAttribs(): void {
    this._logoVbo.bind();
    const gl = QOpenGLContext.currentContext().functions();
    gl.enableVertexAttribArray(0);
    gl.enableVertexAttribArray(1);
    const sizeof_GLfloat = 4;
    gl.vertexAttribPointer(0, 3, gl.FLOAT, gl.FALSE, 6 * sizeof_GLfloat, 0);
    gl.vertexAttribPointer(1, 3, gl.FLOAT, gl.FALSE, 6 * sizeof_GLfloat, 3 * sizeof_GLfloat);
    this._logoVbo.release();

    this._checkError(gl);
  }

  _checkError(gl): void {
    const err = gl.getError();
    if (err != gl.NO_ERROR) {
      throw new Error('GL ERROR!');
    }
  }

  private _paintGL(): void {
    const gl = QOpenGLContext.currentContext().functions();

    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    gl.enable(gl.DEPTH_TEST);
    gl.enable(gl.CULL_FACE);

    this._checkError(gl);

    mat4.identity(this._world);
    mat4.rotateX(this._world, this._world, Math.PI - (2 * Math.PI * this._xRot) / 360 / 16.0);
    mat4.rotateY(this._world, this._world, (2 * Math.PI * this._yRot) / 360 / 16.0);
    mat4.rotateZ(this._world, this._world, (2 * Math.PI * this._zRot) / 360 / 16.0);

    this._checkError(gl);

    this._vao.bind();
    this._program.bind();
    gl.uniformMatrix4fv(this._projMatrixLoc, 1, false, this._proj);

    this._checkError(gl);

    const mvMatrix = mat4.create();
    mat4.multiply(mvMatrix, this._camera, this._world);
    gl.uniformMatrix4fv(this._mvMatrixLoc, 1, false, mvMatrix);

    this._checkError(gl);

    const normalMatrix: mat3 = mat3.create();
    mat3.normalFromMat4(normalMatrix, this._world);
    gl.uniformMatrix3fv(this._normalMatrixLoc, 1, false, normalMatrix);

    this._checkError(gl);

    gl.drawArrays(gl.TRIANGLES, 0, this._logoVertexCount);

    this._program.release();
    this._vao.release();
    this._checkError(gl);
  }

  private _resizeGL(w: number, h: number): void {
    mat4.identity(this._proj);
    mat4.perspective(this._proj, (Math.PI * 2 * 45.0) / 360, w / h, 0.01, 100.0);
  }

  private _getLogoVertices(): number[] {
    const data: number[] = [];

    const x1 = +0.06;
    const y1 = -0.14;
    const x2 = +0.14;
    const y2 = -0.06;
    const x3 = +0.08;
    const y3 = +0.0;
    const x4 = +0.3;
    const y4 = +0.22;

    this._quad(data, x1, y1, x2, y2, y2, x2, y1, x1);
    this._quad(data, x3, y3, x4, y4, y4, x4, y3, x3);

    this._extrude(data, x1, y1, x2, y2);
    this._extrude(data, x2, y2, y2, x2);
    this._extrude(data, y2, x2, y1, x1);
    this._extrude(data, y1, x1, x1, y1);
    this._extrude(data, x3, y3, x4, y4);
    this._extrude(data, x4, y4, y4, x4);
    this._extrude(data, y4, x4, y3, x3);

    const NumSectors = 100;

    for (let i = 0; i < NumSectors; ++i) {
      let angle = (i * 2 * Math.PI) / NumSectors;
      let angleSin = Math.sin(angle);
      let angleCos = Math.cos(angle);
      const x5 = 0.3 * angleSin;
      const y5 = 0.3 * angleCos;
      const x6 = 0.2 * angleSin;
      const y6 = 0.2 * angleCos;

      angle = ((i + 1) * 2 * Math.PI) / NumSectors;
      angleSin = Math.sin(angle);
      angleCos = Math.cos(angle);
      const x7 = 0.2 * angleSin;
      const y7 = 0.2 * angleCos;
      const x8 = 0.3 * angleSin;
      const y8 = 0.3 * angleCos;

      this._quad(data, x5, y5, x6, y6, x7, y7, x8, y8);

      this._extrude(data, x6, y6, x7, y7);
      this._extrude(data, x8, y8, x5, y5);
    }

    return data;
  }

  private _add(data: number[], x: number, y: number, z: number, nx: number, ny: number, nz: number): void {
    data.push(x);
    data.push(y);
    data.push(z);

    data.push(nx);
    data.push(ny);
    data.push(nz);
  }

  private _normal(v1: vec3, v2: vec3): vec3 {
    const normal = vec3.create();
    vec3.cross(normal, v1, v2);
    vec3.normalize(normal, normal);
    return normal;
  }

  private _quad(
    data: number[],
    x1: number,
    y1: number,
    x2: number,
    y2: number,
    x3: number,
    y3: number,
    x4: number,
    y4: number,
  ): void {
    const separation = 0.05;
    let normal = this._normal([x4 - x1, y4 - y1, 0], [x2 - x1, y2 - y1, 0]);

    this._add(data, x1, y1, -separation, normal[0], normal[1], normal[2]);
    this._add(data, x4, y4, -separation, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, -separation, normal[0], normal[1], normal[2]);

    this._add(data, x3, y3, -separation, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, -separation, normal[0], normal[1], normal[2]);
    this._add(data, x4, y4, -separation, normal[0], normal[1], normal[2]);

    normal = this._normal([x1 - x4, y1 - y4, 0], [x2 - x4, y2 - y4, 0]);

    this._add(data, x4, y4, 0.05, normal[0], normal[1], normal[2]);
    this._add(data, x1, y1, 0.05, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, 0.05, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, 0.05, normal[0], normal[1], normal[2]);
    this._add(data, x3, y3, 0.05, normal[0], normal[1], normal[2]);
    this._add(data, x4, y4, 0.05, normal[0], normal[1], normal[2]);
  }

  private _extrude(data: number[], x1: number, y1: number, x2: number, y2: number): void {
    const normal = this._normal([0, 0, -0.1], [x2 - x1, y2 - y1, 0]);

    this._add(data, x1, y1, +0.05, normal[0], normal[1], normal[2]);
    this._add(data, x1, y1, -0.05, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, +0.05, normal[0], normal[1], normal[2]);

    this._add(data, x2, y2, -0.05, normal[0], normal[1], normal[2]);
    this._add(data, x2, y2, +0.05, normal[0], normal[1], normal[2]);
    this._add(data, x1, y1, -0.05, normal[0], normal[1], normal[2]);
  }
}

const format = new QSurfaceFormat();
format.setDepthBufferSize(24);
format.setMajorVersion(3);
format.setMinorVersion(2);
format.setProfile(OpenGLContextProfile.CoreProfile);
QSurfaceFormat.setDefaultFormat(format);

const mainWindow = new MainWindow();
mainWindow.show();

(global as any).win = mainWindow;
