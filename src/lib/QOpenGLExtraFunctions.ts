import { NativeElement, Component, checkIfNativeElement } from '@nodegui/nodegui';

import addon from './utils/addon';
import { isTypedArray } from './utils/helpers';
import { QOpenGLContext } from './QOpenGLContext';
import { QOpenGLShaderProgram } from './QOpenGLShaderProgram';
import { QOpenGLBuffer } from './QOpenGLBuffer';

/**

> Access to OpenGL ES 2.0, 3.0, 3.1 and 3.2 functions.

Note: Unlike the C++ `QOpenGLExtraFunctions` class, this version drops the `gl`
prefix for method and constant names to more closely match WebGL.

*/
export class QOpenGLExtraFunctions extends Component {
    native: NativeElement;

    readonly CURRENT_BIT = 0x00000001;
    readonly POINT_BIT = 0x00000002;
    readonly LINE_BIT = 0x00000004;
    readonly POLYGON_BIT = 0x00000008;
    readonly POLYGON_STIPPLE_BIT = 0x00000010;
    readonly PIXEL_MODE_BIT = 0x00000020;
    readonly LIGHTING_BIT = 0x00000040;
    readonly FOG_BIT = 0x00000080;
    readonly ACCUM_BUFFER_BIT = 0x00000200;
    readonly VIEWPORT_BIT = 0x00000800;
    readonly TRANSFORM_BIT = 0x00001000;
    readonly ENABLE_BIT = 0x00002000;
    readonly HINT_BIT = 0x00008000;
    readonly EVAL_BIT = 0x00010000;
    readonly LIST_BIT = 0x00020000;
    readonly TEXTURE_BIT = 0x00040000;
    readonly SCISSOR_BIT = 0x00080000;
    readonly ALL_ATTRIB_BITS = 0xffffffff;

    readonly ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8b8a;
    readonly ACTIVE_ATTRIBUTES = 0x8b89;
    readonly ACTIVE_TEXTURE = 0x84e0;
    readonly ACTIVE_UNIFORM_MAX_LENGTH = 0x8b87;
    readonly ACTIVE_UNIFORMS = 0x8b86;
    readonly ALIASED_LINE_WIDTH_RANGE = 0x846e;
    readonly ALIASED_POINT_SIZE_RANGE = 0x846d;
    readonly ALPHA = 0x1906;
    readonly ALPHA_BITS = 0x0d55;
    readonly ALWAYS = 0x0207;
    readonly ARRAY_BUFFER = 0x8892;
    readonly ARRAY_BUFFER_BINDING = 0x8894;
    readonly ATTACHED_SHADERS = 0x8b85;
    readonly BACK = 0x0405;
    readonly BLEND = 0x0be2;
    readonly BLEND_COLOR = 0x8005;
    readonly BLEND_DST_ALPHA = 0x80ca;
    readonly BLEND_DST_RGB = 0x80c8;
    readonly BLEND_EQUATION = 0x8009;
    readonly BLEND_EQUATION_ALPHA = 0x883d;
    readonly BLEND_EQUATION_RGB = 0x8009;
    readonly BLEND_SRC_ALPHA = 0x80cb;
    readonly BLEND_SRC_RGB = 0x80c9;
    readonly BLUE_BITS = 0x0d54;
    readonly BOOL = 0x8b56;
    readonly BOOL_VEC2 = 0x8b57;
    readonly BOOL_VEC3 = 0x8b58;
    readonly BOOL_VEC4 = 0x8b59;
    readonly BUFFER_SIZE = 0x8764;
    readonly BUFFER_USAGE = 0x8765;
    readonly BYTE = 0x1400;
    readonly CCW = 0x0901;
    readonly CLAMP_TO_EDGE = 0x812f;
    readonly COLOR_ATTACHMENT0 = 0x8ce0;
    readonly COLOR_BUFFER_BIT = 0x00004000;
    readonly COLOR_CLEAR_VALUE = 0x0c22;
    readonly COLOR_WRITEMASK = 0x0c23;
    readonly COMPILE_STATUS = 0x8b81;
    readonly COMPRESSED_TEXTURE_FORMATS = 0x86a3;
    readonly CONSTANT_ALPHA = 0x8003;
    readonly CONSTANT_COLOR = 0x8001;
    readonly CULL_FACE = 0x0b44;
    readonly CULL_FACE_MODE = 0x0b45;
    readonly CURRENT_PROGRAM = 0x8b8d;
    readonly CURRENT_VERTEX_ATTRIB = 0x8626;
    readonly CW = 0x0900;
    readonly DECR = 0x1e03;
    readonly DECR_WRAP = 0x8508;
    readonly DELETE_STATUS = 0x8b80;
    readonly DEPTH_ATTACHMENT = 0x8d00;
    readonly DEPTH_BITS = 0x0d56;
    readonly DEPTH_BUFFER_BIT = 0x00000100;
    readonly DEPTH_CLEAR_VALUE = 0x0b73;
    readonly DEPTH_COMPONENT = 0x1902;
    readonly DEPTH_COMPONENT16 = 0x81a5;
    readonly DEPTH_FUNC = 0x0b74;
    readonly DEPTH_RANGE = 0x0b70;
    readonly DEPTH_TEST = 0x0b71;
    readonly DEPTH_WRITEMASK = 0x0b72;
    readonly DITHER = 0x0bd0;
    readonly DONT_CARE = 0x1100;
    readonly DST_ALPHA = 0x0304;
    readonly DST_COLOR = 0x0306;
    readonly DYNAMIC_DRAW = 0x88e8;
    readonly ELEMENT_ARRAY_BUFFER = 0x8893;
    readonly ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
    readonly EQUAL = 0x0202;
    readonly EXTENSIONS = 0x1f03;
    readonly FALSE = 0;
    readonly FASTEST = 0x1101;
    readonly FIXED = 0x140c;
    readonly FLOAT = 0x1406;
    readonly FLOAT_MAT2 = 0x8b5a;
    readonly FLOAT_MAT3 = 0x8b5b;
    readonly FLOAT_MAT4 = 0x8b5c;
    readonly FLOAT_VEC2 = 0x8b50;
    readonly FLOAT_VEC3 = 0x8b51;
    readonly FLOAT_VEC4 = 0x8b52;
    readonly FRAGMENT_SHADER = 0x8b30;
    readonly FRAMEBUFFER = 0x8d40;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8cd1;
    readonly FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8cd0;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8cd3;
    readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8cd2;
    readonly FRAMEBUFFER_BINDING = 0x8ca6;
    readonly FRAMEBUFFER_COMPLETE = 0x8cd5;
    readonly FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8cd6;
    readonly FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8cd9;
    readonly FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8cd7;
    readonly FRAMEBUFFER_UNSUPPORTED = 0x8cdd;
    readonly FRONT = 0x0404;
    readonly FRONT_AND_BACK = 0x0408;
    readonly FRONT_FACE = 0x0b46;
    readonly FUNC_ADD = 0x8006;
    readonly FUNC_REVERSE_SUBTRACT = 0x800b;
    readonly FUNC_SUBTRACT = 0x800a;
    readonly GENERATE_MIPMAP_HINT = 0x8192;
    readonly GEQUAL = 0x0206;
    readonly GREATER = 0x0204;
    readonly GREEN_BITS = 0x0d53;
    readonly HIGH_FLOAT = 0x8df2;
    readonly HIGH_INT = 0x8df5;
    readonly IMPLEMENTATION_COLOR_READ_FORMAT = 0x8b9b;
    readonly IMPLEMENTATION_COLOR_READ_TYPE = 0x8b9a;
    readonly INCR = 0x1e02;
    readonly INCR_WRAP = 0x8507;
    readonly INFO_LOG_LENGTH = 0x8b84;
    readonly INT = 0x1404;
    readonly INT_VEC2 = 0x8b53;
    readonly INT_VEC3 = 0x8b54;
    readonly INT_VEC4 = 0x8b55;
    readonly INVALID_ENUM = 0x0500;
    readonly INVALID_FRAMEBUFFER_OPERATION = 0x0506;
    readonly INVALID_OPERATION = 0x0502;
    readonly INVALID_VALUE = 0x0501;
    readonly INVERT = 0x150a;
    readonly KEEP = 0x1e00;
    readonly LEQUAL = 0x0203;
    readonly LESS = 0x0201;
    readonly LINEAR = 0x2601;
    readonly LINEAR_MIPMAP_LINEAR = 0x2703;
    readonly LINEAR_MIPMAP_NEAREST = 0x2701;
    readonly LINE_LOOP = 0x0002;
    readonly LINES = 0x0001;
    readonly LINE_STRIP = 0x0003;
    readonly LINE_WIDTH = 0x0b21;
    readonly LINK_STATUS = 0x8b82;
    readonly LOW_FLOAT = 0x8df0;
    readonly LOW_INT = 0x8df3;
    readonly LUMINANCE = 0x1909;
    readonly LUMINANCE_ALPHA = 0x190a;
    readonly MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8b4d;
    readonly MAX_CUBE_MAP_TEXTURE_SIZE = 0x851c;
    readonly MAX_FRAGMENT_UNIFORM_VECTORS = 0x8dfd;
    readonly MAX_RENDERBUFFER_SIZE = 0x84e8;
    readonly MAX_TEXTURE_IMAGE_UNITS = 0x8872;
    readonly MAX_TEXTURE_SIZE = 0x0d33;
    readonly MAX_VARYING_VECTORS = 0x8dfc;
    readonly MAX_VERTEX_ATTRIBS = 0x8869;
    readonly MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8b4c;
    readonly MAX_VERTEX_UNIFORM_VECTORS = 0x8dfb;
    readonly MAX_VIEWPORT_DIMS = 0x0d3a;
    readonly MEDIUM_FLOAT = 0x8df1;
    readonly MEDIUM_INT = 0x8df4;
    readonly MIRRORED_REPEAT = 0x8370;
    readonly NEAREST = 0x2600;
    readonly NEAREST_MIPMAP_LINEAR = 0x2702;
    readonly NEAREST_MIPMAP_NEAREST = 0x2700;
    readonly NEVER = 0x0200;
    readonly NICEST = 0x1102;
    readonly NO_ERROR = 0;
    readonly NONE = 0;
    readonly NOTEQUAL = 0x0205;
    readonly NUM_COMPRESSED_TEXTURE_FORMATS = 0x86a2;
    readonly NUM_SHADER_BINARY_FORMATS = 0x8df9;
    readonly ONE = 1;
    readonly ONE_MINUS_CONSTANT_ALPHA = 0x8004;
    readonly ONE_MINUS_CONSTANT_COLOR = 0x8002;
    readonly ONE_MINUS_DST_ALPHA = 0x0305;
    readonly ONE_MINUS_DST_COLOR = 0x0307;
    readonly ONE_MINUS_SRC_ALPHA = 0x0303;
    readonly ONE_MINUS_SRC_COLOR = 0x0301;
    readonly OUT_OF_MEMORY = 0x0505;
    readonly PACK_ALIGNMENT = 0x0d05;
    readonly POINTS = 0x0000;
    readonly POLYGON_OFFSET_FACTOR = 0x8038;
    readonly POLYGON_OFFSET_FILL = 0x8037;
    readonly POLYGON_OFFSET_UNITS = 0x2a00;
    readonly RED_BITS = 0x0d52;
    readonly RENDERBUFFER = 0x8d41;
    readonly RENDERBUFFER_ALPHA_SIZE = 0x8d53;
    readonly RENDERBUFFER_BINDING = 0x8ca7;
    readonly RENDERBUFFER_BLUE_SIZE = 0x8d52;
    readonly RENDERBUFFER_DEPTH_SIZE = 0x8d54;
    readonly RENDERBUFFER_GREEN_SIZE = 0x8d51;
    readonly RENDERBUFFER_HEIGHT = 0x8d43;
    readonly RENDERBUFFER_INTERNAL_FORMAT = 0x8d44;
    readonly RENDERBUFFER_RED_SIZE = 0x8d50;
    readonly RENDERBUFFER_STENCIL_SIZE = 0x8d55;
    readonly RENDERBUFFER_WIDTH = 0x8d42;
    readonly RENDERER = 0x1f01;
    readonly REPEAT = 0x2901;
    readonly REPLACE = 0x1e01;
    readonly RGB = 0x1907;
    readonly RGB565 = 0x8d62;
    readonly RGB5_A1 = 0x8057;
    readonly RGBA = 0x1908;
    readonly RGBA4 = 0x8056;
    readonly BGRA = 0x80e1;
    readonly SAMPLE_ALPHA_TO_COVERAGE = 0x809e;
    readonly SAMPLE_BUFFERS = 0x80a8;
    readonly SAMPLE_COVERAGE = 0x80a0;
    readonly SAMPLE_COVERAGE_INVERT = 0x80ab;
    readonly SAMPLE_COVERAGE_VALUE = 0x80aa;
    readonly SAMPLER_2D = 0x8b5e;
    readonly SAMPLER_CUBE = 0x8b60;
    readonly SAMPLES = 0x80a9;
    readonly SCISSOR_BOX = 0x0c10;
    readonly SCISSOR_TEST = 0x0c11;
    readonly SHADER_BINARY_FORMATS = 0x8df8;
    readonly SHADER_COMPILER = 0x8dfa;
    readonly SHADER_SOURCE_LENGTH = 0x8b88;
    readonly SHADER_TYPE = 0x8b4f;
    readonly SHADING_LANGUAGE_VERSION = 0x8b8c;
    readonly SHORT = 0x1402;
    readonly SRC_ALPHA = 0x0302;
    readonly SRC_ALPHA_SATURATE = 0x0308;
    readonly SRC_COLOR = 0x0300;
    readonly STATIC_DRAW = 0x88e4;
    readonly STENCIL_ATTACHMENT = 0x8d20;
    readonly STENCIL_BACK_FAIL = 0x8801;
    readonly STENCIL_BACK_FUNC = 0x8800;
    readonly STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
    readonly STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
    readonly STENCIL_BACK_REF = 0x8ca3;
    readonly STENCIL_BACK_VALUE_MASK = 0x8ca4;
    readonly STENCIL_BACK_WRITEMASK = 0x8ca5;
    readonly STENCIL_BITS = 0x0d57;
    readonly STENCIL_BUFFER_BIT = 0x00000400;
    readonly STENCIL_CLEAR_VALUE = 0x0b91;
    readonly STENCIL_FAIL = 0x0b94;
    readonly STENCIL_FUNC = 0x0b92;
    readonly STENCIL_INDEX = 0x1901;
    readonly STENCIL_INDEX8 = 0x8d48;
    readonly STENCIL_PASS_DEPTH_FAIL = 0x0b95;
    readonly STENCIL_PASS_DEPTH_PASS = 0x0b96;
    readonly STENCIL_REF = 0x0b97;
    readonly STENCIL_TEST = 0x0b90;
    readonly STENCIL_VALUE_MASK = 0x0b93;
    readonly STENCIL_WRITEMASK = 0x0b98;
    readonly STREAM_DRAW = 0x88e0;
    readonly SUBPIXEL_BITS = 0x0d50;
    readonly TEXTURE0 = 0x84c0;
    readonly TEXTURE = 0x1702;
    readonly TEXTURE10 = 0x84ca;
    readonly TEXTURE1 = 0x84c1;
    readonly TEXTURE11 = 0x84cb;
    readonly TEXTURE12 = 0x84cc;
    readonly TEXTURE13 = 0x84cd;
    readonly TEXTURE14 = 0x84ce;
    readonly TEXTURE15 = 0x84cf;
    readonly TEXTURE16 = 0x84d0;
    readonly TEXTURE17 = 0x84d1;
    readonly TEXTURE18 = 0x84d2;
    readonly TEXTURE19 = 0x84d3;
    readonly TEXTURE20 = 0x84d4;
    readonly TEXTURE2 = 0x84c2;
    readonly TEXTURE21 = 0x84d5;
    readonly TEXTURE22 = 0x84d6;
    readonly TEXTURE23 = 0x84d7;
    readonly TEXTURE24 = 0x84d8;
    readonly TEXTURE25 = 0x84d9;
    readonly TEXTURE26 = 0x84da;
    readonly TEXTURE27 = 0x84db;
    readonly TEXTURE28 = 0x84dc;
    readonly TEXTURE29 = 0x84dd;
    readonly TEXTURE_2D = 0x0de1;
    readonly TEXTURE30 = 0x84de;
    readonly TEXTURE3 = 0x84c3;
    readonly TEXTURE31 = 0x84df;
    readonly TEXTURE4 = 0x84c4;
    readonly TEXTURE5 = 0x84c5;
    readonly TEXTURE6 = 0x84c6;
    readonly TEXTURE7 = 0x84c7;
    readonly TEXTURE8 = 0x84c8;
    readonly TEXTURE9 = 0x84c9;
    readonly TEXTURE_BINDING_2D = 0x8069;
    readonly TEXTURE_BINDING_CUBE_MAP = 0x8514;
    readonly TEXTURE_CUBE_MAP = 0x8513;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
    readonly TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851a;
    readonly TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
    readonly TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
    readonly TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
    readonly TEXTURE_MAG_FILTER = 0x2800;
    readonly TEXTURE_MIN_FILTER = 0x2801;
    readonly TEXTURE_WRAP_S = 0x2802;
    readonly TEXTURE_WRAP_T = 0x2803;
    readonly TRIANGLE_FAN = 0x0006;
    readonly TRIANGLES = 0x0004;
    readonly TRIANGLE_STRIP = 0x0005;
    readonly TRUE = 1;
    readonly UNPACK_ALIGNMENT = 0x0cf5;
    readonly UNSIGNED_BYTE = 0x1401;
    readonly UNSIGNED_INT = 0x1405;
    readonly UNSIGNED_SHORT = 0x1403;
    readonly UNSIGNED_SHORT_4_4_4_4 = 0x8033;
    readonly UNSIGNED_SHORT_5_5_5_1 = 0x8034;
    readonly UNSIGNED_SHORT_5_6_5 = 0x8363;
    readonly VALIDATE_STATUS = 0x8b83;
    readonly VENDOR = 0x1f00;
    readonly VERSION = 0x1f02;
    readonly VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889f;
    readonly VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
    readonly VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886a;
    readonly VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
    readonly VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
    readonly VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
    readonly VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
    readonly VERTEX_SHADER = 0x8b31;
    readonly VIEWPORT = 0x0ba2;
    readonly ZERO = 0;

    constructor(arg?: NativeElement | QOpenGLContext) {
        super();
        if (!arg) {
            this.native = new addon.QOpenGLExtraFunctions();
        } else {
            if (checkIfNativeElement(arg)) {
                this.native = arg as NativeElement;
            } else if (arg.native) {
                this.native = new addon.QOpenGLExtraFunctions((arg as QOpenGLContext).native);
            } else {
                this.native = new addon.QOpenGLExtraFunctions();
            }
        }
    }

    initializeOpenGLFunctions(): void {
        this.native.initializeOpenGLFunctions();
    }

    bindBuffer(target: number, buffer: QOpenGLBuffer | number): void {
        const bufferId = typeof buffer === 'object' ? buffer.bufferId() : buffer;
        this.native.glBindBuffer(target, bufferId);
    }

    clearColor(red: number, green: number, blue: number, alpha: number): void {
        this.native.glClearColor(red, green, blue, alpha);
    }

    clear(mask: number): void {
        this.native.glClear(mask);
    }

    frontFace(arg: number): void {
        this.native.glFrontFace(arg);
    }

    cullFace(arg: number): void {
        this.native.glCullFace(arg);
    }

    disable(arg: number): void {
        this.native.glDisable(arg);
    }

    enable(arg: number): void {
        this.native.glEnable(arg);
    }

    drawArrays(mode: GLenum, first: number, count: number): void {
        this.native.glDrawArrays(mode, first, count);
    }

    useProgram(program: QOpenGLShaderProgram): void {
        this.native.glUseProgram(program.programId());
    }

    getString(name: number): string {
        return this.native.glGetString(name);
    }

    getUniformLocation(programId: number, name: string): number {
        return this.native.glGetUniformLocation(programId, name);
    }

    getAttribLocation(programId: number, name: string): number {
        return this.native.glGetAttribLocation(programId, name);
    }

    depthFunc(func: number): void {
        this.native.glDepthFunc(func);
    }

    genVertexArrays(numberOfArrays: number): number[] {
        const result: number[] = [];
        for (let i = 0; i < numberOfArrays; i++) {
            result.push(this.native.glGenVertexArray());
        }
        return result;
    }

    bindAttribLocation(programId: number, index: number, name: string): void {
        this.native.glBindAttribLocation(programId, index, name);
    }

    bindVertexArray(vertexArray: number): void {
        this.native.glBindVertexArray(vertexArray);
    }

    enableVertexAttribArray(index: number): void {
        this.native.glEnableVertexAttribArray(index);
    }

    vertexAttribPointer(
        index: number,
        size: number,
        type: number,
        normalized: number | boolean,
        stride: number,
        pointer_offset: number,
    ): void {
        const normalizedBoolean = Boolean(normalized);
        this.native.glVertexAttribPointer(index, size, type, normalizedBoolean, stride, pointer_offset);
    }

    genBuffers(numberOfBuffers: number): number[] {
        const result: number[] = [];
        for (let i = 0; i < numberOfBuffers; i++) {
            result.push(this.native.glGenBuffer());
        }
        return result;
    }

    bufferData(target: number, arrayBuffer: ArrayBuffer | NodeJS.TypedArray, usage: number): void {
        let buffer: ArrayBuffer;
        let size = 0;

        if (isTypedArray(arrayBuffer)) {
            buffer = arrayBuffer.buffer;
            size = arrayBuffer.byteLength;
        } else {
            buffer = arrayBuffer;
            size = arrayBuffer.byteLength;
        }

        this.native.glBufferData(target, size, buffer, usage);
    }

    uniform1f(location: number, data: number): void {
        this.uniform1fv(location, 1, [data]);
    }

    uniform1fv(location: number, count: number, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / Float32Array.BYTES_PER_ELEMENT) {
            throw new Error(
                `Parameter 'count' to uniform1fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform1fv(location, count, data[0]);
    }

    uniform2f(location: number, data1: number, data2: number): void {
        this.uniform2fv(location, 1, [data1, data2]);
    }

    uniform2fv(location: number, count: number, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (2 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform2fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform2fv(location, count, buffer);
    }

    uniform3f(location: number, data1: number, data2: number, data3: number): void {
        this.uniform3fv(location, 1, [data1, data2, data3]);
    }

    uniform3fv(location: number, count: number, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (3 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform3fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform3fv(location, count, buffer);
    }

    uniform4f(location: number, data1: number, data2: number, data3: number, data4: number): void {
        this.uniform4fv(location, 1, [data1, data2, data3, data4]);
    }

    uniform4fv(location: number, count: number, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (4 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform4fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform4fv(location, count, buffer);
    }

    uniform1i(location: number, data: number): void {
        this.uniform1iv(location, 1, [data]);
    }

    uniform1iv(location: number, count: number, data: number[] | Int32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Int32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / Int32Array.BYTES_PER_ELEMENT) {
            throw new Error(
                `Parameter 'count' to uniform1fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform1iv(location, count, buffer);
    }

    uniform2i(location: number, data1: number, data2: number): void {
        this.uniform2iv(location, 1, [data1, data2]);
    }

    uniform2iv(location: number, count: number, data: number[] | Int32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Int32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (2 * Int32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform2fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform2iv(location, count, buffer);
    }

    uniform3i(location: number, data1: number, data2: number, data3: number): void {
        this.uniform3iv(location, 1, [data1, data2, data3]);
    }

    uniform3iv(location: number, count: number, data: number[] | Int32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Int32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (3 * Int32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform3fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform3iv(location, count, buffer);
    }

    uniform4i(location: number, data1: number, data2: number, data3: number, data4: number): void {
        this.uniform4iv(location, 1, [data1, data2, data3, data4]);
    }

    uniform4iv(location: number, count: number, data: number[] | Int32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Int32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (4 * Int32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniform4fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniform4iv(location, count, buffer);
    }
    activeTexture(texture: number): void {
        this.native.glActiveTexture(texture);
    }

    attachShader(program: number, shader: number): void {
        this.native.glAttachShader(program, shader);
    }

    bindFramebuffer(target: number, framebuffer: number): void {
        this.native.glBindFramebuffer(target, framebuffer);
    }

    bindRenderbuffer(target: number, renderbuffer: number): void {
        this.native.glBindRenderbuffer(target, renderbuffer);
    }

    bindTexture(target: number, texture: number): void {
        this.native.glBindTexture(target, texture);
    }

    blendColor(red: number, green: number, blue: number, alpha: number): void {
        this.native.glBlendColor(red, green, blue, alpha);
    }

    blendEquation(mode: number): void {
        this.native.glBlendEquation(mode);
    }

    blendEquationSeparate(modeRGB: number, modeAlpha: number): void {
        this.native.glBlendEquationSeparate(modeRGB, modeAlpha);
    }

    blendFunc(sfactor: number, dfactor: number): void {
        this.native.glBlendFunc(sfactor, dfactor);
    }

    blendFuncSeparate(srcRGB: number, dstRGB: number, srcAlpha: number, dstAlpha: number): void {
        this.native.glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    }

    checkFramebufferStatus(target: number): number {
        return this.native.glCheckFramebufferStatus(target);
    }

    clearDepthf(depth: number): void {
        this.native.glClearDepthf(depth);
    }

    clearStencil(s: number): void {
        this.native.glClearStencil(s);
    }

    colorMask(red: boolean, green: boolean, blue: boolean, alpha: boolean): void {
        this.native.glColorMask(red, green, blue, alpha);
    }

    compileShader(shader: number): void {
        this.native.glCompileShader(shader);
    }

    copyTexImage2D(
        target: number,
        level: number,
        internalformat: number,
        x: number,
        y: number,
        width: number,
        height: number,
        border: number,
    ): void {
        this.native.glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    }

    copyTexSubImage2D(
        target: number,
        level: number,
        xoffset: number,
        yoffset: number,
        x: number,
        y: number,
        width: number,
        height: number,
    ): void {
        this.native.glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    }

    createProgram(): number {
        return this.native.glCreateProgram();
    }

    createShader(type: number): number {
        return this.native.glCreateShader(type);
    }

    deleteProgram(program: number): void {
        this.native.glDeleteProgram(program);
    }

    deleteShader(shader: number): void {
        this.native.glDeleteShader(shader);
    }

    depthMask(flag: boolean): void {
        this.native.glDepthMask(flag);
    }

    depthRangef(zNear: number, zFar: number): void {
        this.native.glDepthRangef(zNear, zFar);
    }

    detachShader(program: number, shader: number): void {
        this.native.glDetachShader(program, shader);
    }

    disableVertexAttribArray(index: number): void {
        this.native.glDisableVertexAttribArray(index);
    }

    finish(): void {
        this.native.glFinish();
    }

    flush(): void {
        this.native.glFlush();
    }

    framebufferRenderbuffer(
        target: number,
        attachment: number,
        renderbuffertarget: number,
        renderbuffer: number,
    ): void {
        this.native.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    }

    framebufferTexture2D(target: number, attachment: number, textarget: number, texture: number, level: number): void {
        this.native.glFramebufferTexture2D(target, attachment, textarget, texture, level);
    }

    generateMipmap(target: number): void {
        this.native.glGenerateMipmap(target);
    }

    getError(): number {
        return this.native.glGetError();
    }

    hint(target: number, mode: number): void {
        this.native.glHint(target, mode);
    }

    isBuffer(buffer: number): boolean {
        return this.native.glIsBuffer(buffer);
    }

    isEnabled(cap: number): boolean {
        return this.native.glIsEnabled(cap);
    }

    isFramebuffer(framebuffer: number): boolean {
        return this.native.glIsFramebuffer(framebuffer);
    }

    isProgram(program: number): boolean {
        return this.native.glIsProgram(program);
    }

    isRenderbuffer(renderbuffer: number): boolean {
        return this.native.glIsRenderbuffer(renderbuffer);
    }

    isShader(shader: number): boolean {
        return this.native.glIsShader(shader);
    }

    isTexture(texture: number): boolean {
        return this.native.glIsTexture(texture);
    }

    lineWidth(width: number): void {
        this.native.glLineWidth(width);
    }

    linkProgram(program: number): void {
        this.native.glLinkProgram(program);
    }

    pixelStorei(pname: number, param: number): void {
        this.native.glPixelStorei(pname, param);
    }

    polygonOffset(factor: number, units: number): void {
        this.native.glPolygonOffset(factor, units);
    }

    releaseShaderCompiler(): void {
        this.native.glReleaseShaderCompiler();
    }

    renderbufferStorage(target: number, internalformat: number, width: number, height: number): void {
        this.native.glRenderbufferStorage(target, internalformat, width, height);
    }

    sampleCoverage(value: number, invert: boolean): void {
        this.native.glSampleCoverage(value, invert);
    }

    scissor(x: number, y: number, width: number, height: number): void {
        this.native.glScissor(x, y, width, height);
    }

    stencilFunc(func: number, ref: number, mask: number): void {
        this.native.glStencilFunc(func, ref, mask);
    }

    stencilFuncSeparate(face: number, func: number, ref: number, mask: number): void {
        this.native.glStencilFuncSeparate(face, func, ref, mask);
    }

    stencilMask(mask: number): void {
        this.native.glStencilMask(mask);
    }

    stencilMaskSeparate(face: number, mask: number): void {
        this.native.glStencilMaskSeparate(face, mask);
    }

    stencilOp(fail: number, zfail: number, zpass: number): void {
        this.native.glStencilOp(fail, zfail, zpass);
    }

    stencilOpSeparate(face: number, fail: number, zfail: number, zpass: number): void {
        this.native.glStencilOpSeparate(face, fail, zfail, zpass);
    }

    texParameterf(target: number, pname: number, param: number): void {
        this.native.glTexParameterf(target, pname, param);
    }

    texParameteri(target: number, pname: number, param: number): void {
        this.native.glTexParameteri(target, pname, param);
    }

    validateProgram(program: number): void {
        this.native.glValidateProgram(program);
    }

    vertexAttrib1f(indx: number, x: number): void {
        this.native.glVertexAttrib1f(indx, x);
    }

    vertexAttrib2f(indx: number, x: number, y: number): void {
        this.native.glVertexAttrib2f(indx, x, y);
    }

    vertexAttrib3f(indx: number, x: number, y: number, z: number): void {
        this.native.glVertexAttrib3f(indx, x, y, z);
    }

    vertexAttrib4f(indx: number, x: number, y: number, z: number, w: number): void {
        this.native.glVertexAttrib4f(indx, x, y, z, w);
    }

    viewport(x: number, y: number, width: number, height: number): void {
        this.native.glViewport(x, y, width, height);
    }

    activeShaderProgram(pipeline: number, program: number): void {
        this.native.glActiveShaderProgram(pipeline, program);
    }

    beginQuery(target: number, id: number): void {
        this.native.glBeginQuery(target, id);
    }

    beginTransformFeedback(primitiveMode: number): void {
        this.native.glBeginTransformFeedback(primitiveMode);
    }

    bindBufferBase(target: number, index: number, buffer: number): void {
        this.native.glBindBufferBase(target, index, buffer);
    }

    bindImageTexture(
        unit: number,
        texture: number,
        level: number,
        layered: boolean,
        layer: number,
        access: number,
        format: number,
    ): void {
        this.native.glBindImageTexture(unit, texture, level, layered, layer, access, format);
    }

    bindProgramPipeline(pipeline: number): void {
        this.native.glBindProgramPipeline(pipeline);
    }

    bindSampler(unit: number, sampler: number): void {
        this.native.glBindSampler(unit, sampler);
    }

    bindTransformFeedback(target: number, id: number): void {
        this.native.glBindTransformFeedback(target, id);
    }

    blendBarrier(): void {
        this.native.glBlendBarrier();
    }

    blendEquationSeparatei(buf: number, modeRGB: number, modeAlpha: number): void {
        this.native.glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
    }

    blendEquationi(buf: number, mode: number): void {
        this.native.glBlendEquationi(buf, mode);
    }

    blendFuncSeparatei(buf: number, srcRGB: number, dstRGB: number, srcAlpha: number, dstAlpha: number): void {
        this.native.glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
    }

    blendFunci(buf: number, src: number, dst: number): void {
        this.native.glBlendFunci(buf, src, dst);
    }

    clearBufferfi(buffer: number, drawbuffer: number, depth: number, stencil: number): void {
        this.native.glClearBufferfi(buffer, drawbuffer, depth, stencil);
    }

    colorMaski(index: number, r: boolean, g: boolean, b: boolean, a: boolean): void {
        this.native.glColorMaski(index, r, g, b, a);
    }

    copyImageSubData(
        srcName: number,
        srcTarget: number,
        srcLevel: number,
        srcX: number,
        srcY: number,
        srcZ: number,
        dstName: number,
        dstTarget: number,
        dstLevel: number,
        dstX: number,
        dstY: number,
        dstZ: number,
        srcWidth: number,
        srcHeight: number,
        srcDepth: number,
    ): void {
        this.native.glCopyImageSubData(
            srcName,
            srcTarget,
            srcLevel,
            srcX,
            srcY,
            srcZ,
            dstName,
            dstTarget,
            dstLevel,
            dstX,
            dstY,
            dstZ,
            srcWidth,
            srcHeight,
            srcDepth,
        );
    }

    copyTexSubImage3D(
        target: number,
        level: number,
        xoffset: number,
        yoffset: number,
        zoffset: number,
        x: number,
        y: number,
        width: number,
        height: number,
    ): void {
        this.native.glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
    }

    disablei(target: number, index: number): void {
        this.native.glDisablei(target, index);
    }

    dispatchCompute(num_groups_x: number, num_groups_y: number, num_groups_z: number): void {
        this.native.glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
    }

    drawArraysInstanced(mode: number, first: number, count: number, instancecount: number): void {
        this.native.glDrawArraysInstanced(mode, first, count, instancecount);
    }

    enablei(target: number, index: number): void {
        this.native.glEnablei(target, index);
    }

    endQuery(target: number): void {
        this.native.glEndQuery(target);
    }

    endTransformFeedback(): void {
        this.native.glEndTransformFeedback();
    }

    framebufferParameteri(target: number, pname: number, param: number): void {
        this.native.glFramebufferParameteri(target, pname, param);
    }

    framebufferTexture(target: number, attachment: number, texture: number, level: number): void {
        this.native.glFramebufferTexture(target, attachment, texture, level);
    }

    framebufferTextureLayer(target: number, attachment: number, texture: number, level: number, layer: number): void {
        this.native.glFramebufferTextureLayer(target, attachment, texture, level, layer);
    }

    getGraphicsResetStatus(): number {
        return this.native.glGetGraphicsResetStatus();
    }

    isEnabledi(target: number, index: number): boolean {
        return this.native.glIsEnabledi(target, index);
    }

    isProgramPipeline(pipeline: number): boolean {
        return this.native.glIsProgramPipeline(pipeline);
    }

    isQuery(id: number): boolean {
        return this.native.glIsQuery(id);
    }

    isSampler(sampler: number): boolean {
        return this.native.glIsSampler(sampler);
    }

    isTransformFeedback(id: number): boolean {
        return this.native.glIsTransformFeedback(id);
    }

    isVertexArray(array: number): boolean {
        return this.native.glIsVertexArray(array);
    }

    minSampleShading(value: number): void {
        this.native.glMinSampleShading(value);
    }

    patchParameteri(pname: number, value: number): void {
        this.native.glPatchParameteri(pname, value);
    }

    pauseTransformFeedback(): void {
        this.native.glPauseTransformFeedback();
    }

    popDebugGroup(): void {
        this.native.glPopDebugGroup();
    }

    primitiveBoundingBox(
        minX: number,
        minY: number,
        minZ: number,
        minW: number,
        maxX: number,
        maxY: number,
        maxZ: number,
        maxW: number,
    ): void {
        this.native.glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
    }

    programParameteri(program: number, pname: number, value: number): void {
        this.native.glProgramParameteri(program, pname, value);
    }

    programUniform1f(program: number, location: number, v0: number): void {
        this.native.glProgramUniform1f(program, location, v0);
    }

    programUniform1i(program: number, location: number, v0: number): void {
        this.native.glProgramUniform1i(program, location, v0);
    }

    programUniform1ui(program: number, location: number, v0: number): void {
        this.native.glProgramUniform1ui(program, location, v0);
    }

    programUniform2f(program: number, location: number, v0: number, v1: number): void {
        this.native.glProgramUniform2f(program, location, v0, v1);
    }

    programUniform2i(program: number, location: number, v0: number, v1: number): void {
        this.native.glProgramUniform2i(program, location, v0, v1);
    }

    programUniform2ui(program: number, location: number, v0: number, v1: number): void {
        this.native.glProgramUniform2ui(program, location, v0, v1);
    }

    programUniform3f(program: number, location: number, v0: number, v1: number, v2: number): void {
        this.native.glProgramUniform3f(program, location, v0, v1, v2);
    }

    programUniform3i(program: number, location: number, v0: number, v1: number, v2: number): void {
        this.native.glProgramUniform3i(program, location, v0, v1, v2);
    }

    programUniform3ui(program: number, location: number, v0: number, v1: number, v2: number): void {
        this.native.glProgramUniform3ui(program, location, v0, v1, v2);
    }

    programUniform4f(program: number, location: number, v0: number, v1: number, v2: number, v3: number): void {
        this.native.glProgramUniform4f(program, location, v0, v1, v2, v3);
    }

    programUniform4i(program: number, location: number, v0: number, v1: number, v2: number, v3: number): void {
        this.native.glProgramUniform4i(program, location, v0, v1, v2, v3);
    }

    programUniform4ui(program: number, location: number, v0: number, v1: number, v2: number, v3: number): void {
        this.native.glProgramUniform4ui(program, location, v0, v1, v2, v3);
    }

    readBuffer(src: number): void {
        this.native.glReadBuffer(src);
    }

    renderbufferStorageMultisample(
        target: number,
        samples: number,
        internalformat: number,
        width: number,
        height: number,
    ): void {
        this.native.glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
    }

    resumeTransformFeedback(): void {
        this.native.glResumeTransformFeedback();
    }

    samplerParameterf(sampler: number, pname: number, param: number): void {
        this.native.glSamplerParameterf(sampler, pname, param);
    }

    samplerParameteri(sampler: number, pname: number, param: number): void {
        this.native.glSamplerParameteri(sampler, pname, param);
    }

    texBuffer(target: number, internalformat: number, buffer: number): void {
        this.native.glTexBuffer(target, internalformat, buffer);
    }

    texStorage2D(target: number, levels: number, internalformat: number, width: number, height: number): void {
        this.native.glTexStorage2D(target, levels, internalformat, width, height);
    }

    texStorage2DMultisample(
        target: number,
        samples: number,
        internalformat: number,
        width: number,
        height: number,
        fixedsamplelocations: boolean,
    ): void {
        this.native.glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
    }

    texStorage3D(
        target: number,
        levels: number,
        internalformat: number,
        width: number,
        height: number,
        depth: number,
    ): void {
        this.native.glTexStorage3D(target, levels, internalformat, width, height, depth);
    }

    texStorage3DMultisample(
        target: number,
        samples: number,
        internalformat: number,
        width: number,
        height: number,
        depth: number,
        fixedsamplelocations: boolean,
    ): void {
        this.native.glTexStorage3DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations,
        );
    }

    uniform1ui(location: number, v0: number): void {
        this.native.glUniform1ui(location, v0);
    }

    uniform2ui(location: number, v0: number, v1: number): void {
        this.native.glUniform2ui(location, v0, v1);
    }

    uniform3ui(location: number, v0: number, v1: number, v2: number): void {
        this.native.glUniform3ui(location, v0, v1, v2);
    }

    uniform4ui(location: number, v0: number, v1: number, v2: number, v3: number): void {
        this.native.glUniform4ui(location, v0, v1, v2, v3);
    }

    uniformBlockBinding(program: number, uniformBlockIndex: number, uniformBlockBinding: number): void {
        this.native.glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
    }

    unmapBuffer(target: number): boolean {
        return this.native.glUnmapBuffer(target);
    }

    validateProgramPipeline(pipeline: number): void {
        this.native.glValidateProgramPipeline(pipeline);
    }

    vertexAttribBinding(attribindex: number, bindingindex: number): void {
        this.native.glVertexAttribBinding(attribindex, bindingindex);
    }

    vertexAttribDivisor(index: number, divisor: number): void {
        this.native.glVertexAttribDivisor(index, divisor);
    }

    vertexAttribFormat(
        attribindex: number,
        size: number,
        type: number,
        normalized: boolean,
        relativeoffset: number,
    ): void {
        this.native.glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
    }

    vertexAttribI4i(index: number, x: number, y: number, z: number, w: number): void {
        this.native.glVertexAttribI4i(index, x, y, z, w);
    }

    vertexAttribI4ui(index: number, x: number, y: number, z: number, w: number): void {
        this.native.glVertexAttribI4ui(index, x, y, z, w);
    }

    vertexAttribIFormat(attribindex: number, size: number, type: number, relativeoffset: number): void {
        this.native.glVertexAttribIFormat(attribindex, size, type, relativeoffset);
    }

    vertexBindingDivisor(bindingindex: number, divisor: number): void {
        this.native.glVertexBindingDivisor(bindingindex, divisor);
    }

    uniformMatrix2fv(location: number, count: number, transpose: boolean, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (2 * 2 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniformMatrix2fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniformMatrix2fv(location, count, transpose, buffer);
    }

    uniformMatrix3fv(location: number, count: number, transpose: boolean, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (3 * 3 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniformMatrix3fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniformMatrix3fv(location, count, transpose, buffer);
    }

    uniformMatrix4fv(location: number, count: number, transpose: boolean, data: number[] | Float32Array): void {
        let buffer: ArrayBuffer;
        if (isTypedArray(data)) {
            buffer = data.buffer;
        } else {
            buffer = Float32Array.from(data).buffer;
        }

        if (count > buffer.byteLength / (4 * 4 * Float32Array.BYTES_PER_ELEMENT)) {
            throw new Error(
                `Parameter 'count' to uniformMatrix4fv() specifies more data than is available in parameter 'data'.`,
            );
        }

        this.native.glUniformMatrix4fv(location, count, transpose, buffer);
    }
}
