import { NativeElement, Component } from '@nodegui/nodegui';

import addon from './utils/addon';


export class QOpenGLVertexArrayObject extends Component {
    native: NativeElement;

    constructor() {
        super();

        this.native = new addon.QOpenGLVertexArrayObject();
    }

    bind(): void {
        this.native.bind();
    }

    create(): boolean {
        return this.native.create();
    }

    release(): void {
        this.native.release();
    }
}
