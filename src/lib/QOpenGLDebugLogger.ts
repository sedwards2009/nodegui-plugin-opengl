import { NativeElement, Component } from '@nodegui/nodegui';

import addon from './utils/addon';


export enum Severity {
    InvalidSeverity = 0x00000000,
    HighSeverity = 0x00000001,
    MediumSeverity = 0x00000002,
    LowSeverity = 0x00000004,
    NotificationSeverity = 0x00000008,
    AnySeverity = 0xffffffff,
}

export enum Source {
    InvalidSource = 0x00000000,
    APISource = 0x00000001,
    WindowSystemSource = 0x00000002,
    ShaderCompilerSource = 0x00000004,
    ThirdPartySource = 0x00000008,
    ApplicationSource = 0x00000010,
    OtherSource = 0x00000020,
    AnySource = 0xffffffff,
}

export enum Type {
    InvalidType = 0x00000000,
    ErrorType = 0x00000001,
    DeprecatedBehaviorType = 0x00000002,
    UndefinedBehaviorType = 0x00000004,
    PortabilityType = 0x00000008,
    PerformanceType = 0x00000010,
    OtherType = 0x00000020,
    MarkerType = 0x00000040,
    GroupPushType = 0x00000080,
    GroupPopType = 0x00000100,
    AnyType = 0xffffffff,
}


export class QOpenGLDebugMessage {
    readonly id: string;
    readonly severity: Severity;
    readonly source: Source;
    readonly type: Type;
    readonly message: string;

    constructor (id: string, severity: Severity, source: Source, type: Type, message: string) {
        this.id = id;
        this.severity = severity;
        this.source = source;
        this.type = type;
        this.message = message;
    }

    format(): string {
        return `id: ${this.id}, Severity: ${Severity[this.severity]}, Source: ${Source[this.source]}, ` +
          `Type: ${Type[this.type]}, Message: ${this.message}`;
    }
}

/**

> Log messages from the OpenGL driver

Access to [QOpenGLDebugLogger](https://doc.qt.io/qt-5/qopengldebuglogger.html)

Note: Not all methods from the C++ version are available.

Just like how the C++ documentation explains, to use this class you first have
to activate the debug logging in the `QSurfaceFormat`:

  `format.setOption(QSurfaceFormat.DebugContext);`

and then when a QOpenGLContext is active, call `initialize()` on the created
`QOpenGLDebugLogger` instance.

Log messages are collected asynchronously and need to regularly collected and
handled. The method `formatLoggedMessages()` provides a quick and easy way
getting log messages in a form which can be easily sent to `console.log()`.

 */
export class QOpenGLDebugLogger extends Component {
    native: NativeElement;

    constructor() {
        super();
        this.native = new addon.QOpenGLDebugLogger();
    }

    /**
     * Initialize the logger.
     *
     * An QOpenGLContext must be current when this method is called. This
     * method must be called before the logger can be used.
     */
    initialize(): boolean {
        return this.native.initialize();
    }

    /**
     * Get any queued log messages.
     *
     * Calling this will also remove the messages from the queue.
     *
     * @return list of new log message objects.
     */
    loggedMessages(): QOpenGLDebugMessage[] {
        const messageBlock: string = this.native.loggedMessages();
        const result: QOpenGLDebugMessage[] = [];
        const lines = messageBlock.split('\n');
        for (const line of lines) {
          const parts = line.split('\t');
          if (parts.length !== 5) {
            continue;
          }
          const id = parts[0];
          const severity = Number.parseInt(parts[1], 10);
          const source = Number.parseInt(parts[2], 10);
          const type = Number.parseInt(parts[3], 10);
          const message = parts[4];
          result.push(new QOpenGLDebugMessage(id, severity, source, type, message));
        }
        return result;
    }

    /**
     * Collect all waiting log messages as human friendly single string.
     *
     * This can be easily sent to `console.log()` or similar.
     *
     * @return A single string containing human readable log messages.
     */
    formatLoggedMessages(): string {
        return this.loggedMessages().map(m => m.format()).join('\n');
    }

    /**
     * Inject a custom log message into the OpenGL log.
     *
     * This is useful when debugging.
     *
     * @param message the message to log.
     * @param severity the severity level to use.
     * @param type the type of message.
     * @param id the ID field for the message.
     */
    logMessage(message: string, severity=Severity.NotificationSeverity, type=Type.OtherType, id=0): void {
        this.native.logMessage(message, severity, type, id);
    }
}
