import { NativeElement, QObject, Component } from '@nodegui/nodegui';

import addon from './utils/addon';
import { QOpenGLShader } from './QOpenGLShader';

/**

> Support for linking and using OpenGL shader programs.

Note: The C++ `QOpenGLShaderProgram` class contains many convenience functions.
These have not been replicated and made accessible via JS. Use the equivalent
functions in `QOpenGLExtraFunctions` instead.

*/
export class QOpenGLShaderProgram extends Component {
    native: NativeElement;

    constructor(arg?: QObject) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLShaderProgram();
        } else {
            this.native = new addon.QOpenGLShaderProgram(arg.native);
        }
    }

    addShader(shader: QOpenGLShader): boolean {
        return this.native.addShader(shader.native);
    }

    addShaderFromSourceCode(type: number, source: string): boolean {
        return this.native.addShaderFromSourceCode(type, source);
    }

    log(): string {
        return this.native.log();
    }

    bind(): boolean {
        return this.native.bind();
    }

    delete(): void {
        this.native.delete();
        this.native = null;
    }

    link(): boolean {
        return this.native.link();
    }

    release(): void {
        this.native.release();
    }

    programId(): number {
        return this.native.programId();
    }
}
