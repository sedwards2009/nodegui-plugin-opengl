import addon from './utils/addon';
import { NativeElement, Component } from '@nodegui/nodegui';

import { OpenGLContextProfile } from './OpenGLContextProfile';


export enum FormatOption {
    StereoBuffers = 0x0001,
    DebugContext = 0x0002,
    DeprecatedFunctions = 0x0004,
    ResetNotification = 0x0008,
}

export class QSurfaceFormat extends Component {
    native: NativeElement;

    constructor(native?: any) {
        super();
        if (native != null) {
            this.native = native;
        } else {
            this.native = new addon.QSurfaceFormat();
        }
    }

    setDepthBufferSize(depth: number): void {
        this.native.setDepthBufferSize(depth);
    }

    setStencilBufferSize(size: number): void {
        this.native.setStencilBufferSize(size);
    }

    profile(): OpenGLContextProfile {
        return this.native.profile();
    }

    setProfile(profile: OpenGLContextProfile): void {
        this.native.setProfile(profile);
    }

    setMajorVersion(version: number): void {
        this.native.setMajorVersion(version);
    }

    setMinorVersion(version: number): void {
        this.native.setMinorVersion(version);
    }

    setOption(option: FormatOption, on=true): void {
        this.native.setOption(option, on);
    }

    static setDefaultFormat(format: QSurfaceFormat): void {
        addon.QSurfaceFormat.setDefaultFormat(format.native);
    }

    static defaultFormat(): QSurfaceFormat {
        return new QSurfaceFormat(addon.QSurfaceFormat.defaultFormat());
    }
}
