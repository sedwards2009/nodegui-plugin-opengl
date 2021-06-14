import { performance } from 'perf_hooks';
import { mat4 } from 'gl-matrix';
import {
    QColor,
    QGridLayout,
    QImage,
    QLabel,
    QMainWindow,
    QPainter,
    QWidget,
} from '@nodegui/nodegui';

import {
    QOpenGLWidget,
    QOpenGLContext,
    QOpenGLShader,
    QOpenGLShaderProgram,
    QSurfaceFormat,
    OpenGLContextProfile,
    QOpenGLTexture,
    QOpenGLBuffer,
    QOpenGLExtraFunctions,
    FormatOption,
    QOpenGLDebugLogger,
    QOpenGLVertexArrayObject,
} from '..';


const sizeof_GLfloat = 4;

const log = console.log.bind(console);

class GLCubeWidget {
    private _logger: QOpenGLDebugLogger = null;
    private _widget: QOpenGLWidget | null = null;
    private _vertexShader: QOpenGLShader = null;
    private _fragmentShader: QOpenGLShader = null;
    private _program: QOpenGLShaderProgram = null;

    private _vao: QOpenGLVertexArrayObject = null;

    private _frames = 0;
    private _start = 0;
    private _fAngle = 0;
    private _fScale = 1;
    private _texture: QOpenGLTexture = null;
    private _image: QImage = null;
    private _vertexAttr = -1;
    private _normalAttr = -1;
    private _texCoordAttr = -1;
    private _matrixUniform = -1;
    private _textureUniform = -1;
    private _buffer: QOpenGLBuffer = null;
    private _verticesOffset = 0;
    private _texCoordsOffset = 0;
    private _normalsOffset = 0;

    getWidget(): QOpenGLWidget {
        if (this._widget != null) {
            return this._widget;
        }

        const widget = new QOpenGLWidget();
        widget.setMinimumSize(640, 480);
        widget.addEventListener('initializeGL', () => {
            this._initializeGL();
        });
        widget.addEventListener('paintGL', () => {
            this._paintGL();
        });

        this._widget = widget;
        return this._widget;
    }

    private _initializeGL(): void {
        const context = QOpenGLContext.currentContext();
        const gl = context.extraFunctions();

        this._logger = new QOpenGLDebugLogger();
        this._logger.initialize();

        log(`Renderer: ${gl.getString(gl.RENDERER)}`);
        log(`OpenGL version: ${gl.getString(gl.VERSION)}`);
        log(`Context.isOpenGLES: ${context.isOpenGLES()}`);
        log(`Context.isValid: ${context.isValid()}`);
        log(`Has GL_KHR_debug: ${context.hasExtension("GL_KHR_debug")}`);

        this._fAngle = 0;
        this._fScale = 1;

        this._image = new QImage("nodegui.jpg");

        this._texture = new QOpenGLTexture(this._image);

        this._vertexShader = new QOpenGLShader(QOpenGLShader.Vertex);
        if ( ! this._vertexShader.compileSourceCode(`
            attribute highp vec4 vertex;
            attribute highp vec4 texCoord;
            attribute mediump vec3 normal;
            uniform mediump mat4 matrix;
            varying highp vec4 texc;
            varying mediump float angle;
            void main(void)
            {
                vec3 toLight = normalize(vec3(0.0, 0.3, 1.0));
                angle = max(dot(normal, toLight), 0.0);
                gl_Position = matrix * vertex;
                texc = texCoord;
            }
        `)) {
            log('failed to compile vertex shader! ', this._vertexShader.log());
        }

        this._fragmentShader = new QOpenGLShader(QOpenGLShader.Fragment);
        if ( ! this._fragmentShader.compileSourceCode(`
            varying highp vec4 texc;
            uniform sampler2D tex;
            varying mediump float angle;
            void main(void)
            {
                highp vec3 color = texture2D(tex, texc.st).rgb;
                color = color * 0.2 + color * 0.8 * angle;
                gl_FragColor = vec4(clamp(color, 0.0, 1.0), 1.0);
                //gl_FragColor = vec4(1.0, 0.5, 0.0, 1.0);
            }
        `)) {
            log('failed to compile fragment shader! ', this._fragmentShader.log());
        }

        this._program = new QOpenGLShaderProgram();
        this._program.addShader(this._vertexShader);
        this._program.addShader(this._fragmentShader);
        this._program.link();

        this._vertexAttr = gl.getAttribLocation(this._program.programId(), "vertex");
        this._normalAttr = gl.getAttribLocation(this._program.programId(), "normal");
        this._texCoordAttr = gl.getAttribLocation(this._program.programId(), "texCoord");
        this._matrixUniform = gl.getUniformLocation(this._program.programId(), "matrix");
        this._textureUniform = gl.getUniformLocation(this._program.programId(), "tex");

        this._vao = new QOpenGLVertexArrayObject();
        this._vao.create();
        this._vao.bind();

        this._createGeometry();

        this._vao.release();

        log(this._logger.formatLoggedMessages());
    }

    private _createGeometry() {
        const afVertices = Float32Array.from([
            -0.5, 0.5, 0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5,
            0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
            -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, -0.5, 0.5, -0.5,
            0.5, 0.5, -0.5, -0.5, 0.5, -0.5, 0.5, -0.5, -0.5,

            0.5, -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, 0.5, -0.5,
            0.5, 0.5, 0.5, 0.5, 0.5, -0.5, 0.5, -0.5, 0.5,
            -0.5, 0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, -0.5,
            -0.5, -0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5,

            0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, -0.5,
            -0.5, 0.5, 0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5,
            -0.5, -0.5, -0.5, -0.5, -0.5, 0.5, 0.5, -0.5, -0.5,
            0.5, -0.5, 0.5, 0.5, -0.5, -0.5, -0.5, -0.5, 0.5,
        ]);
        const numVertices = afVertices.length;

        const afTexCoords = Float32Array.from([
            0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0,
            1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,

            1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0,
            0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0,

            0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
            1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0
        ]);
        const numTexCoords = afTexCoords.length;

        const afNormals = Float32Array.from([
            0, 0, -1, 0, 0, -1, 0, 0, -1,
            0, 0, -1, 0, 0, -1, 0, 0, -1,
            0, 0, 1, 0, 0, 1, 0, 0, 1,
            0, 0, 1, 0, 0, 1, 0, 0, 1,

            -1, 0, 0, -1, 0, 0, -1, 0, 0,
            -1, 0, 0, -1, 0, 0, -1, 0, 0,
            1, 0, 0, 1, 0, 0, 1, 0, 0,
            1, 0, 0, 1, 0, 0, 1, 0, 0,

            0, -1, 0, 0, -1, 0, 0, -1, 0,
            0, -1, 0, 0, -1, 0, 0, -1, 0,
            0, 1, 0, 0, 1, 0, 0, 1, 0,
            0, 1, 0, 0, 1, 0, 0, 1, 0
        ]);
        const numNormals = afNormals.length;

        const numFloats = numVertices + numTexCoords + numNormals;
        this._verticesOffset = 0;
        this._texCoordsOffset = this._verticesOffset + afVertices.length * sizeof_GLfloat;
        this._normalsOffset = this._texCoordsOffset + afTexCoords.length * sizeof_GLfloat;

        this._buffer = new QOpenGLBuffer();
        this._buffer.create();
        this._buffer.bind();
        this._buffer.allocate(numFloats * sizeof_GLfloat);
        this._buffer.write(this._verticesOffset, afVertices, afVertices.length * sizeof_GLfloat);
        this._buffer.write(this._texCoordsOffset, afTexCoords, afTexCoords.length * sizeof_GLfloat);
        this._buffer.write(this._normalsOffset, afNormals, afNormals.length * sizeof_GLfloat);
        this._buffer.release();
    }

    private _paintGL(): void {
        const painter = new QPainter();
        painter.begin(this._widget);

        painter.beginNativePainting();
        const gl = QOpenGLContext.currentContext().functions();

        gl.clearColor(0.0, 0.0, 0.0, 0.0);
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

        gl.frontFace(gl.CW);
        gl.cullFace(gl.FRONT);
        gl.enable(gl.CULL_FACE);
        gl.enable(gl.DEPTH_TEST);
        gl.depthFunc(gl.LESS);

        const modelView = mat4.create();
        const radAngle = 2 * Math.PI * this._fAngle / 360;
        mat4.rotateY(modelView, modelView, radAngle);
        mat4.rotateX(modelView, modelView, radAngle);
        mat4.rotateZ(modelView, modelView, radAngle);
        mat4.scale(modelView, modelView, [this._fScale, this._fScale, this._fScale]);
        mat4.translate(modelView, modelView, [0, -0.2, 0]);
        this._program.bind();
        this._vao.bind();

        gl.uniformMatrix4fv(this._matrixUniform, 1, false, modelView);

        this._paintTexturedCube(gl);

        this._vao.release();
        this._program.release();

        gl.disable(gl.DEPTH_TEST);
        gl.disable(gl.CULL_FACE);

        painter.endNativePainting();

        const elapsed = performance.now() - this._start;
        painter.setPen(new QColor(0, 255, 0));
        painter.drawText(20, 40, `${Math.round(this._frames / (elapsed / 1000.0))} frames per second`);

        painter.end();

        // log(this._logger.formatLoggedMessages());

        if (!(this._frames % 100)) {
            this._start = performance.now();
            this._frames = 0;
        }
        this._frames++;
        this._fAngle += 1.0;

        this._widget.update();
    }

    private _paintTexturedCube(gl: QOpenGLExtraFunctions): void {
        this._texture.bind();

        gl.uniform1i(this._textureUniform, 0);  // use texture unit 0

        gl.enableVertexAttribArray(this._vertexAttr);
        gl.enableVertexAttribArray(this._normalAttr);
        gl.enableVertexAttribArray(this._texCoordAttr);

        this._buffer.bind();

        const floatsPerVertex = 3;
        const floatsPerTexCoord = 2;
        const floatsPerNormal = 3;
        const totalFloats = floatsPerVertex + floatsPerTexCoord + floatsPerNormal;
        const numTriangles = this._buffer.size() / (totalFloats * sizeof_GLfloat);

        gl.vertexAttribPointer(this._vertexAttr, floatsPerVertex, gl.FLOAT, true, 0, this._verticesOffset);
        gl.vertexAttribPointer(this._texCoordAttr, floatsPerTexCoord, gl.FLOAT, true, 0, this._texCoordsOffset);
        gl.vertexAttribPointer(this._normalAttr, floatsPerNormal, gl.FLOAT, true, 0, this._normalsOffset);


        gl.drawArrays(gl.TRIANGLES, 0, numTriangles);

        gl.disableVertexAttribArray(this._vertexAttr);
        gl.disableVertexAttribArray(this._texCoordAttr);
        gl.disableVertexAttribArray(this._normalAttr);

        this._buffer.release();
    }
}

const format = new QSurfaceFormat();
format.setProfile(OpenGLContextProfile.CoreProfile);
format.setMajorVersion(4);
format.setMinorVersion(1);
format.setOption(FormatOption.DebugContext);


QSurfaceFormat.setDefaultFormat(format);

const win = new QMainWindow();
win.resize(500, 500);
win.setObjectName('win');
win.setWindowTitle('NodeJS OpenGL Cube');

const centralWidget = new QWidget();

const gridLayout = new QGridLayout();
centralWidget.setLayout(gridLayout);

const messageLabel = new QLabel();
messageLabel.setText('NodeJS OpenGL Cube');
gridLayout.addWidget(messageLabel, 0, 0);

const glCubeWidget = new GLCubeWidget();
gridLayout.addWidget(glCubeWidget.getWidget(), 1, 0);

win.setCentralWidget(centralWidget);

win.show();
(global as any).win = win;
