import { NativeElement, Component } from '@nodegui/nodegui';

import addon from './utils/addon';
import { isTypedArray } from './utils/helpers';

export enum QOpenGLBufferType {
    VertexBuffer = 0x8892,
    IndexBuffer = 0x8893,
    PixelPackBuffer = 0x88eb,
    PixelUnpackBuffer = 0x88ec,
}

export class QOpenGLBuffer extends Component {
    native: NativeElement;

    constructor(arg = QOpenGLBufferType.VertexBuffer) {
        super();
        this.native = new addon.QOpenGLBuffer(arg);
    }

    allocate(bytesCount: number): void {
        this.native.allocate(bytesCount);
    }

    bind(): void {
        return this.native.bind();
    }

    bufferId(): number {
        return this.native.bufferId();
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

    release(): void {
        this.native.release();
    }

    write(offset: number, arrayBuffer: ArrayBuffer | NodeJS.TypedArray, countBytes: number): void {
        let buffer: ArrayBuffer;
        let size = 0;
        if (isTypedArray(arrayBuffer)) {
            buffer = arrayBuffer.buffer;
            size = arrayBuffer.byteLength;
        } else {
            buffer = arrayBuffer;
            size = arrayBuffer.byteLength;
        }
        if (countBytes > size) {
            throw new Error('Argument "count" to QOpenGLBuffer.write() can\'t be bigger than the buffer size.');
        }
        this.native.write(offset, buffer, countBytes);
    }

    size(): number {
        return this.native.size();
    }
}
