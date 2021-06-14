import { EventEmitter } from 'events';
import { checkIfNativeElement, NativeElement, Component, QObject } from '@nodegui/nodegui';

import addon from './utils/addon';
import { QOpenGLExtraFunctions } from './QOpenGLExtraFunctions';

// TODO: Get this from nodegui directly.
function noop() {}
function wrapWithActivateUvLoop<T extends Function>(func: T): T {
    const fn = (...args: any[]): any => {
        const activateUvLoop = (process as any).activateUvLoop || noop;
        activateUvLoop();
        return func(...args);
    };
    return fn as any;
}


export class QOpenGLContext extends Component {
    native: NativeElement;

    private emitter: EventEmitter;

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

        this.emitter = new EventEmitter();
        this.emitter.emit = wrapWithActivateUvLoop(this.emitter.emit.bind(this.emitter));
        this.native.injectNodeEventEmitter(this.emitter.emit);
    }

    addEventListener(eventType: OpenGLContextEventTypes, callback: () => void): void {
        this.emitter.addListener(eventType, callback);
    }

    removeEventListener(eventType: OpenGLContextEventTypes, callback: () => void): void {
        if (callback != null) {
            this.emitter.removeListener(eventType, callback);
        } else {
            this.emitter.removeAllListeners(eventType);
        }
    }

    functions(): QOpenGLExtraFunctions {
        return this.extraFunctions();
    }

    extraFunctions(): QOpenGLExtraFunctions {
        return new QOpenGLExtraFunctions(this.native.extraFunctions());
    }

    hasExtension(name: string): boolean {
        return this.native.hasExtension(name);
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

export enum OpenGLContextEventTypes {
    'AboutToBeDestroyed' = 'AboutToBeDestroyed'
}
