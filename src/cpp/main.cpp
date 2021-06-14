#include <napi.h>

#include "QOpenGLBuffer/qopenglbuffer_wrap.h"
#include "QOpenGLContext/qopenglcontext_wrap.h"
#include "QOpenGLDebugLogger/qopengldebuglogger_wrap.h"
#include "QOpenGLExtraFunctions/qopenglextrafunctions_wrap.h"
#include "QOpenGLShader/qopenglshader_wrap.h"
#include "QOpenGLShaderProgram/qopenglshaderprogram_wrap.h"
#include "QOpenGLTexture/qopengltexture_wrap.h"
#include "QOpenGLVertexArrayObject/qopenglvertexarrayobject_wrap.h"
#include "QOpenGLWidget/qopenglwidget_wrap.h"
#include "QSurfaceFormat/qsurfaceformat_wrap.h"


Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QOpenGLBufferWrap::init(env, exports);
  QOpenGLContextWrap::init(env, exports);
  QOpenGLDebugLoggerWrap::init(env, exports);
  QOpenGLExtraFunctionsWrap::init(env, exports);
  QOpenGLShaderWrap::init(env, exports);
  QOpenGLShaderProgramWrap::init(env, exports);
  QOpenGLTextureWrap::init(env, exports);
  QOpenGLVertexArrayObjectWrap::init(env, exports);
  QOpenGLWidgetWrap::init(env, exports);
  QSurfaceFormatWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
