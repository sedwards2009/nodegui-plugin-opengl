import { checkIfNativeElement, NativeElement, Component, QObject } from '@nodegui/nodegui';

import addon from './utils/addon';
import { QOpenGLExtraFunctions } from './QOpenGLExtraFunctions';

export class QOpenGLContext extends Component {
    native: NativeElement;

    constructor(arg?: NativeElement | QObject) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLContext();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else if (arg.native) {
                this.native = new addon.QOpenGLContext(arg.native);
            } else {
                this.native = new addon.QOpenGLContext();
            }
        }
    }

    functions(): QOpenGLExtraFunctions {
        return this.extraFunctions();
    }

    extraFunctions(): QOpenGLExtraFunctions {
        return new QOpenGLExtraFunctions(this.native.extraFunctions());
    }

    isOpenGLES(): boolean {
        return this.native.isOpenGLES();
    }

    isValid(): boolean {
        return this.native.isValid();
    }

    /**
    Returns the last context which called makeCurrent in the current thread, or nullptr, if no context is current.
    */
    static currentContext(): QOpenGLContext {
        return new QOpenGLContext(addon.QOpenGLContext.currentContext());
    }
}
