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

    delete(): void {
        this.native.delete();
        this.native = null;
    }

    destroy(): void {
        this.native.destroy();
    }

    isCreated(): boolean {
        return this.native.isCreated();
    }

    objectId(): number {
        return this.native.objectId();
    }

    release(): void {
        this.native.release();
    }
}
