import { performance } from 'perf_hooks';
import {
    QColor,
    QGridLayout,
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
} from '..';


const log = console.log.bind(console);

class GLTestWidget {
    private _widget: QOpenGLWidget | null = null;
    private _vertexShader: QOpenGLShader = null;
    private _fragmentShader: QOpenGLShader = null;
    private _program: QOpenGLShaderProgram = null;
    private _vao = 0;
    private _vbo = 0;
    private _frames = 0;
    private _start = 0;

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

    /*
    OpenGLCubeWidget::~OpenGLCubeWidget() {
      makeCurrent();
      delete m_program;
      delete m_vertexShader;
      delete m_fragmentShader;
      delete m_texture;
      m_buffer.destroy();
      doneCurrent();
    }
*/

    private _initializeGL(): void {
        log('_initializeGL');

        const context = QOpenGLContext.currentContext();
        const gl = context.extraFunctions();

        log(`Renderer: ${gl.getString(gl.RENDERER)}`);
        log(`OpenGL version: ${gl.getString(gl.VERSION)}`);
        log(`Context.isOpenGLES: ${context.isOpenGLES()}`);
        log(`Context.isValid: ${context.isValid()}`);

        gl.enable(gl.DEPTH_TEST);
        gl.depthFunc(gl.LESS);

        const [vbo] = gl.genBuffers(1);
        this._vbo = vbo;
        gl.bindBuffer(gl.ARRAY_BUFFER, vbo);
        const points = Float32Array.from([0, 0.5, 0, 0.5, -0.5, 0, -0.5, -0.5, 0]);
        gl.bufferData(gl.ARRAY_BUFFER, points, gl.STATIC_DRAW);

        const [vao] = gl.genVertexArrays(1);
        this._vao = vao;
        gl.bindVertexArray(this._vao);

        gl.enableVertexAttribArray(0);
        gl.bindBuffer(gl.ARRAY_BUFFER, this._vbo);
        gl.vertexAttribPointer(0, 3, gl.FLOAT, gl.FALSE, 0, 0);

        this._vertexShader = new QOpenGLShader(QOpenGLShader.Vertex);
        if (
            !this._vertexShader.compileSourceCode(`
            #version 410
            in vec3 vp;
            void main () {
              gl_Position = vec4(vp, 1.0);
            }
        `)
        ) {
            log('failed to compile vertex shader! ', this._vertexShader.log());
        }

        this._fragmentShader = new QOpenGLShader(QOpenGLShader.Fragment);
        const fragmentOK = this._fragmentShader.compileSourceCode(`
            #version 410
            out vec4 frag_colour;
            void main () {
              frag_colour = vec4(0.5, 0.0, 0.5, 1.0);
            }
        `);
        if (!fragmentOK) {
            log('failed to compile fragment shader! ', this._vertexShader.log());
        }

        this._program = new QOpenGLShaderProgram();
        this._program.addShader(this._vertexShader);
        this._program.addShader(this._fragmentShader);
        this._program.link();

        this._program.release();
        this._start = performance.now();
    }

    private _paintGL(): void {
        const painter = new QPainter();
        painter.begin(this._widget);

        painter.beginNativePainting();
        const gl = QOpenGLContext.currentContext().functions();

        gl.enable(gl.DEPTH_TEST);
        gl.depthFunc(gl.LESS);

        gl.clearColor(0.0, 0.0, 0.0, 0.0);
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

        gl.useProgram(this._program);
        gl.bindVertexArray(this._vao);

        gl.drawArrays(gl.TRIANGLES, 0, 3);

        gl.disable(gl.DEPTH_TEST);

        painter.endNativePainting();

        const elapsed = performance.now() - this._start;
        painter.setPen(new QColor(0, 255, 0));
        painter.drawText(20, 40, `${Math.round(this._frames / (elapsed / 1000.0))} frames per second`);

        painter.end();

        if (!(this._frames % 100)) {
            this._start = performance.now();
            this._frames = 0;
        }
        this._frames++;

        this._widget.update();
    }
}

console.log('Starting up');

const format = new QSurfaceFormat();
format.setProfile(OpenGLContextProfile.CoreProfile);
format.setMajorVersion(4);
format.setMinorVersion(1);
QSurfaceFormat.setDefaultFormat(format);

const win = new QMainWindow();
win.resize(500, 500);
win.setObjectName('win');
win.setWindowTitle('OpenGL Test');

const centralWidget = new QWidget();

const gridLayout = new QGridLayout();
centralWidget.setLayout(gridLayout);

const messageLabel = new QLabel();
messageLabel.setText('OpenGL test');
gridLayout.addWidget(messageLabel, 0, 0);

const glCubeWidget = new GLTestWidget();
gridLayout.addWidget(glCubeWidget.getWidget(), 1, 0);

win.setCentralWidget(centralWidget);

win.show();
(global as any).win = win;
