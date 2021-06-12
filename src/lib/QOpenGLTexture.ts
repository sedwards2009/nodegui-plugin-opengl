import addon from './utils/addon';
import { QImage, NativeElement, Component, checkIfNativeElement } from '@nodegui/nodegui';


export enum MipMapGeneration {
    GenerateMipMaps = 0,
    DontGenerateMipMaps = 1,
}

export class QOpenGLTexture extends Component {
    native: NativeElement;

    constructor(arg?: NativeElement | QImage, arg2?: MipMapGeneration) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLTexture();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else {
                if (arg2 === undefined) {
                    arg2 = MipMapGeneration.GenerateMipMaps;
                }
                this.native = new addon.QOpenGLTexture(arg.native, arg2);
            }
        }
    }

    bind(): void {
        this.native.bind();
    }
}
