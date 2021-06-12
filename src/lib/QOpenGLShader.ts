import { NativeElement, Component } from '@nodegui/nodegui';

import addon from './utils/addon';


export class QOpenGLShader extends Component {
    native: NativeElement;

    static readonly Vertex = 0x0001;
    static readonly Fragment = 0x0002;
    static readonly Geometry = 0x0004;

    constructor(type: number) {
        super();

        this.native = new addon.QOpenGLShader(type);
    }

    compileSourceCode(source: string): boolean {
        return this.native.compileSourceCode(source);
    }

    log(): string {
        return this.native.log();
    }
}
