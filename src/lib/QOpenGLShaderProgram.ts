import { NativeElement, QObject, Component } from '@nodegui/nodegui';

import addon from './utils/addon';
import { QOpenGLShader } from './QOpenGLShader';


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

    // Remove, use QOpenGLFunctions
    bindAttributeLocation(name: string, location: number): void {
        this.native.bindAttributeLocation(name, location);
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

    // Remove, use QOpenGLFunctions
    attributeLocation(attribute: string): number {
        return this.native.attributeLocation(attribute);
    }

    release(): void {
        this.native.release();
    }

    // Remove, use QOpenGLFunctions
    uniformLocation(uniform: string): number {
        return this.native.uniformLocation(uniform);
    }

    // Remove, use QOpenGLFunctions
    setUniformValue1i(location: number, value: number): void {
        this.native.setUniformValue1i(location, value);
    }

    // Remove, use QOpenGLFunctions
    disableAttributeArray(location: number): void {
        this.native.disableAttributeArray(location);
    }

    // Remove, use QOpenGLFunctions
    enableAttributeArray(location: number): void {
        this.native.enableAttributeArray(location);
    }

    // Remove, use QOpenGLFunctions
    setUniformMatrix4fv(location: number, data: Float32Array): void {
        this.native.setUniformMatrix4fv(location, data.buffer);
    }

    setAttributeBuffer(location: number, type: number, offset: number, tupleSize: number, stride = 0): void {
        this.native.setAttributeBuffer(location, type, offset, tupleSize, stride);
    }

    programId(): number {
        return this.native.programId();
    }
}
