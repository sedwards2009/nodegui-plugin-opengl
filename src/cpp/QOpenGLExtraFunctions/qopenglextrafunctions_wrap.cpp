#include <Extras/Utils/nutils.h>

#include "qopenglextrafunctions_wrap.h"
#include "../QOpenGLContext/qopenglcontext_wrap.h"


Napi::FunctionReference QOpenGLExtraFunctionsWrap::constructor;

Napi::Object QOpenGLExtraFunctionsWrap::init(Napi::Env env,
                                             Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLExtraFunctions";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("glBindBuffer", &QOpenGLExtraFunctionsWrap::glBindBuffer),
       InstanceMethod("glBindVertexArray",
                      &QOpenGLExtraFunctionsWrap::glBindVertexArray),
       InstanceMethod("glBufferData", &QOpenGLExtraFunctionsWrap::glBufferData),
       InstanceMethod("glClear", &QOpenGLExtraFunctionsWrap::glClear),
       InstanceMethod("glClearColor", &QOpenGLExtraFunctionsWrap::glClearColor),
       InstanceMethod("glCullFace", &QOpenGLExtraFunctionsWrap::glCullFace),
       InstanceMethod("glDepthFunc", &QOpenGLExtraFunctionsWrap::glDepthFunc),
       InstanceMethod("glDisable", &QOpenGLExtraFunctionsWrap::glDisable),
       InstanceMethod("glDrawArrays", &QOpenGLExtraFunctionsWrap::glDrawArrays),
       InstanceMethod("glEnable", &QOpenGLExtraFunctionsWrap::glEnable),
       InstanceMethod("glEnableVertexAttribArray",
                      &QOpenGLExtraFunctionsWrap::glEnableVertexAttribArray),
       InstanceMethod("glFrontFace", &QOpenGLExtraFunctionsWrap::glFrontFace),
       InstanceMethod("glGenBuffer", &QOpenGLExtraFunctionsWrap::glGenBuffer),
       InstanceMethod("glGenVertexArray",
                      &QOpenGLExtraFunctionsWrap::glGenVertexArray),
       InstanceMethod("glGetString", &QOpenGLExtraFunctionsWrap::glGetString),
       InstanceMethod("glUniform1fv", &QOpenGLExtraFunctionsWrap::glUniform1fv),
       InstanceMethod("glUniform2fv", &QOpenGLExtraFunctionsWrap::glUniform2fv),
       InstanceMethod("glUniform3fv", &QOpenGLExtraFunctionsWrap::glUniform3fv),
       InstanceMethod("glUniform4fv", &QOpenGLExtraFunctionsWrap::glUniform4fv),
       InstanceMethod("glUniform1iv", &QOpenGLExtraFunctionsWrap::glUniform1iv),
       InstanceMethod("glUniform2iv", &QOpenGLExtraFunctionsWrap::glUniform2iv),
       InstanceMethod("glUniform3iv", &QOpenGLExtraFunctionsWrap::glUniform3iv),
       InstanceMethod("glUniform4iv", &QOpenGLExtraFunctionsWrap::glUniform4iv),
       InstanceMethod("glUniformMatrix2fv",
                      &QOpenGLExtraFunctionsWrap::glUniformMatrix2fv),
       InstanceMethod("glUniformMatrix3fv",
                      &QOpenGLExtraFunctionsWrap::glUniformMatrix3fv),
       InstanceMethod("glUniformMatrix4fv",
                      &QOpenGLExtraFunctionsWrap::glUniformMatrix4fv),

       InstanceMethod("glUseProgram", &QOpenGLExtraFunctionsWrap::glUseProgram),
       InstanceMethod("glVertexAttribPointer",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribPointer),
       InstanceMethod("initializeOpenGLFunctions",
                      &QOpenGLExtraFunctionsWrap::initializeOpenGLFunctions),

       InstanceMethod("glActiveTexture",
                      &QOpenGLExtraFunctionsWrap::glActiveTexture),
       InstanceMethod("glAttachShader",
                      &QOpenGLExtraFunctionsWrap::glAttachShader),
       InstanceMethod("glBindFramebuffer",
                      &QOpenGLExtraFunctionsWrap::glBindFramebuffer),
       InstanceMethod("glBindRenderbuffer",
                      &QOpenGLExtraFunctionsWrap::glBindRenderbuffer),
       InstanceMethod("glBindTexture",
                      &QOpenGLExtraFunctionsWrap::glBindTexture),
       InstanceMethod("glBlendColor", &QOpenGLExtraFunctionsWrap::glBlendColor),
       InstanceMethod("glBlendEquation",
                      &QOpenGLExtraFunctionsWrap::glBlendEquation),
       InstanceMethod("glBlendEquationSeparate",
                      &QOpenGLExtraFunctionsWrap::glBlendEquationSeparate),
       InstanceMethod("glBlendFunc", &QOpenGLExtraFunctionsWrap::glBlendFunc),
       InstanceMethod("glBlendFuncSeparate",
                      &QOpenGLExtraFunctionsWrap::glBlendFuncSeparate),
       InstanceMethod("glCheckFramebufferStatus",
                      &QOpenGLExtraFunctionsWrap::glCheckFramebufferStatus),
       InstanceMethod("glClearDepthf",
                      &QOpenGLExtraFunctionsWrap::glClearDepthf),
       InstanceMethod("glClearStencil",
                      &QOpenGLExtraFunctionsWrap::glClearStencil),
       InstanceMethod("glColorMask", &QOpenGLExtraFunctionsWrap::glColorMask),
       InstanceMethod("glCompileShader",
                      &QOpenGLExtraFunctionsWrap::glCompileShader),
       InstanceMethod("glCopyTexImage2D",
                      &QOpenGLExtraFunctionsWrap::glCopyTexImage2D),
       InstanceMethod("glCopyTexSubImage2D",
                      &QOpenGLExtraFunctionsWrap::glCopyTexSubImage2D),
       InstanceMethod("glCreateProgram",
                      &QOpenGLExtraFunctionsWrap::glCreateProgram),
       InstanceMethod("glCreateShader",
                      &QOpenGLExtraFunctionsWrap::glCreateShader),
       InstanceMethod("glDeleteProgram",
                      &QOpenGLExtraFunctionsWrap::glDeleteProgram),
       InstanceMethod("glDeleteShader",
                      &QOpenGLExtraFunctionsWrap::glDeleteShader),
       InstanceMethod("glDepthMask", &QOpenGLExtraFunctionsWrap::glDepthMask),
       InstanceMethod("glDepthRangef",
                      &QOpenGLExtraFunctionsWrap::glDepthRangef),
       InstanceMethod("glDetachShader",
                      &QOpenGLExtraFunctionsWrap::glDetachShader),
       InstanceMethod("glDisableVertexAttribArray",
                      &QOpenGLExtraFunctionsWrap::glDisableVertexAttribArray),
       InstanceMethod("glFinish", &QOpenGLExtraFunctionsWrap::glFinish),
       InstanceMethod("glFlush", &QOpenGLExtraFunctionsWrap::glFlush),
       InstanceMethod("glFramebufferRenderbuffer",
                      &QOpenGLExtraFunctionsWrap::glFramebufferRenderbuffer),
       InstanceMethod("glFramebufferTexture2D",
                      &QOpenGLExtraFunctionsWrap::glFramebufferTexture2D),
       InstanceMethod("glGenerateMipmap",
                      &QOpenGLExtraFunctionsWrap::glGenerateMipmap),
       InstanceMethod("glGetError", &QOpenGLExtraFunctionsWrap::glGetError),
       InstanceMethod("glHint", &QOpenGLExtraFunctionsWrap::glHint),
       InstanceMethod("glIsBuffer", &QOpenGLExtraFunctionsWrap::glIsBuffer),
       InstanceMethod("glIsEnabled", &QOpenGLExtraFunctionsWrap::glIsEnabled),
       InstanceMethod("glIsFramebuffer",
                      &QOpenGLExtraFunctionsWrap::glIsFramebuffer),
       InstanceMethod("glIsProgram", &QOpenGLExtraFunctionsWrap::glIsProgram),
       InstanceMethod("glIsRenderbuffer",
                      &QOpenGLExtraFunctionsWrap::glIsRenderbuffer),
       InstanceMethod("glIsShader", &QOpenGLExtraFunctionsWrap::glIsShader),
       InstanceMethod("glIsTexture", &QOpenGLExtraFunctionsWrap::glIsTexture),
       InstanceMethod("glLineWidth", &QOpenGLExtraFunctionsWrap::glLineWidth),
       InstanceMethod("glLinkProgram",
                      &QOpenGLExtraFunctionsWrap::glLinkProgram),
       InstanceMethod("glPixelStorei",
                      &QOpenGLExtraFunctionsWrap::glPixelStorei),
       InstanceMethod("glPolygonOffset",
                      &QOpenGLExtraFunctionsWrap::glPolygonOffset),
       InstanceMethod("glReleaseShaderCompiler",
                      &QOpenGLExtraFunctionsWrap::glReleaseShaderCompiler),
       InstanceMethod("glRenderbufferStorage",
                      &QOpenGLExtraFunctionsWrap::glRenderbufferStorage),
       InstanceMethod("glSampleCoverage",
                      &QOpenGLExtraFunctionsWrap::glSampleCoverage),
       InstanceMethod("glScissor", &QOpenGLExtraFunctionsWrap::glScissor),
       InstanceMethod("glStencilFunc",
                      &QOpenGLExtraFunctionsWrap::glStencilFunc),
       InstanceMethod("glStencilFuncSeparate",
                      &QOpenGLExtraFunctionsWrap::glStencilFuncSeparate),
       InstanceMethod("glStencilMask",
                      &QOpenGLExtraFunctionsWrap::glStencilMask),
       InstanceMethod("glStencilMaskSeparate",
                      &QOpenGLExtraFunctionsWrap::glStencilMaskSeparate),
       InstanceMethod("glStencilOp", &QOpenGLExtraFunctionsWrap::glStencilOp),
       InstanceMethod("glStencilOpSeparate",
                      &QOpenGLExtraFunctionsWrap::glStencilOpSeparate),
       InstanceMethod("glTexParameterf",
                      &QOpenGLExtraFunctionsWrap::glTexParameterf),
       InstanceMethod("glTexParameteri",
                      &QOpenGLExtraFunctionsWrap::glTexParameteri),
       InstanceMethod("glValidateProgram",
                      &QOpenGLExtraFunctionsWrap::glValidateProgram),
       InstanceMethod("glVertexAttrib1f",
                      &QOpenGLExtraFunctionsWrap::glVertexAttrib1f),
       InstanceMethod("glVertexAttrib2f",
                      &QOpenGLExtraFunctionsWrap::glVertexAttrib2f),
       InstanceMethod("glVertexAttrib3f",
                      &QOpenGLExtraFunctionsWrap::glVertexAttrib3f),
       InstanceMethod("glVertexAttrib4f",
                      &QOpenGLExtraFunctionsWrap::glVertexAttrib4f),
       InstanceMethod("glViewport", &QOpenGLExtraFunctionsWrap::glViewport),

       InstanceMethod("glActiveShaderProgram",
                      &QOpenGLExtraFunctionsWrap::glActiveShaderProgram),
       InstanceMethod("glBeginQuery", &QOpenGLExtraFunctionsWrap::glBeginQuery),
       InstanceMethod("glBeginTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glBeginTransformFeedback),
       InstanceMethod("glBindBufferBase",
                      &QOpenGLExtraFunctionsWrap::glBindBufferBase),
       InstanceMethod("glBindImageTexture",
                      &QOpenGLExtraFunctionsWrap::glBindImageTexture),
       InstanceMethod("glBindProgramPipeline",
                      &QOpenGLExtraFunctionsWrap::glBindProgramPipeline),
       InstanceMethod("glBindSampler",
                      &QOpenGLExtraFunctionsWrap::glBindSampler),
       InstanceMethod("glBindTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glBindTransformFeedback),
       InstanceMethod("glBlendBarrier",
                      &QOpenGLExtraFunctionsWrap::glBlendBarrier),
       InstanceMethod("glBlendEquationSeparatei",
                      &QOpenGLExtraFunctionsWrap::glBlendEquationSeparatei),
       InstanceMethod("glBlendEquationi",
                      &QOpenGLExtraFunctionsWrap::glBlendEquationi),
       InstanceMethod("glBlendFuncSeparatei",
                      &QOpenGLExtraFunctionsWrap::glBlendFuncSeparatei),
       InstanceMethod("glBlendFunci", &QOpenGLExtraFunctionsWrap::glBlendFunci),
       InstanceMethod("glClearBufferfi",
                      &QOpenGLExtraFunctionsWrap::glClearBufferfi),
       InstanceMethod("glColorMaski", &QOpenGLExtraFunctionsWrap::glColorMaski),
       InstanceMethod("glCopyImageSubData",
                      &QOpenGLExtraFunctionsWrap::glCopyImageSubData),
       InstanceMethod("glCopyTexSubImage3D",
                      &QOpenGLExtraFunctionsWrap::glCopyTexSubImage3D),
       InstanceMethod("glDisablei", &QOpenGLExtraFunctionsWrap::glDisablei),
       InstanceMethod("glDispatchCompute",
                      &QOpenGLExtraFunctionsWrap::glDispatchCompute),
       InstanceMethod("glDrawArraysInstanced",
                      &QOpenGLExtraFunctionsWrap::glDrawArraysInstanced),
       InstanceMethod("glEnablei", &QOpenGLExtraFunctionsWrap::glEnablei),
       InstanceMethod("glEndQuery", &QOpenGLExtraFunctionsWrap::glEndQuery),
       InstanceMethod("glEndTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glEndTransformFeedback),
       InstanceMethod("glFramebufferParameteri",
                      &QOpenGLExtraFunctionsWrap::glFramebufferParameteri),
       InstanceMethod("glFramebufferTexture",
                      &QOpenGLExtraFunctionsWrap::glFramebufferTexture),
       InstanceMethod("glFramebufferTextureLayer",
                      &QOpenGLExtraFunctionsWrap::glFramebufferTextureLayer),
       InstanceMethod("glGetGraphicsResetStatus",
                      &QOpenGLExtraFunctionsWrap::glGetGraphicsResetStatus),
       InstanceMethod("glIsEnabledi", &QOpenGLExtraFunctionsWrap::glIsEnabledi),
       InstanceMethod("glIsProgramPipeline",
                      &QOpenGLExtraFunctionsWrap::glIsProgramPipeline),
       InstanceMethod("glIsQuery", &QOpenGLExtraFunctionsWrap::glIsQuery),
       InstanceMethod("glIsSampler", &QOpenGLExtraFunctionsWrap::glIsSampler),
       InstanceMethod("glIsTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glIsTransformFeedback),
       InstanceMethod("glIsVertexArray",
                      &QOpenGLExtraFunctionsWrap::glIsVertexArray),
       InstanceMethod("glMinSampleShading",
                      &QOpenGLExtraFunctionsWrap::glMinSampleShading),
       InstanceMethod("glPatchParameteri",
                      &QOpenGLExtraFunctionsWrap::glPatchParameteri),
       InstanceMethod("glPauseTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glPauseTransformFeedback),
       InstanceMethod("glPopDebugGroup",
                      &QOpenGLExtraFunctionsWrap::glPopDebugGroup),
       InstanceMethod("glPrimitiveBoundingBox",
                      &QOpenGLExtraFunctionsWrap::glPrimitiveBoundingBox),
       InstanceMethod("glProgramParameteri",
                      &QOpenGLExtraFunctionsWrap::glProgramParameteri),
       InstanceMethod("glProgramUniform1f",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform1f),
       InstanceMethod("glProgramUniform1i",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform1i),
       InstanceMethod("glProgramUniform1ui",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform1ui),
       InstanceMethod("glProgramUniform2f",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform2f),
       InstanceMethod("glProgramUniform2i",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform2i),
       InstanceMethod("glProgramUniform2ui",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform2ui),
       InstanceMethod("glProgramUniform3f",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform3f),
       InstanceMethod("glProgramUniform3i",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform3i),
       InstanceMethod("glProgramUniform3ui",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform3ui),
       InstanceMethod("glProgramUniform4f",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform4f),
       InstanceMethod("glProgramUniform4i",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform4i),
       InstanceMethod("glProgramUniform4ui",
                      &QOpenGLExtraFunctionsWrap::glProgramUniform4ui),
       InstanceMethod("glReadBuffer", &QOpenGLExtraFunctionsWrap::glReadBuffer),
       InstanceMethod(
           "glRenderbufferStorageMultisample",
           &QOpenGLExtraFunctionsWrap::glRenderbufferStorageMultisample),
       InstanceMethod("glResumeTransformFeedback",
                      &QOpenGLExtraFunctionsWrap::glResumeTransformFeedback),
       InstanceMethod("glSamplerParameterf",
                      &QOpenGLExtraFunctionsWrap::glSamplerParameterf),
       InstanceMethod("glSamplerParameteri",
                      &QOpenGLExtraFunctionsWrap::glSamplerParameteri),
       InstanceMethod("glTexBuffer", &QOpenGLExtraFunctionsWrap::glTexBuffer),
       InstanceMethod("glTexStorage2D",
                      &QOpenGLExtraFunctionsWrap::glTexStorage2D),
       InstanceMethod("glTexStorage2DMultisample",
                      &QOpenGLExtraFunctionsWrap::glTexStorage2DMultisample),
       InstanceMethod("glTexStorage3D",
                      &QOpenGLExtraFunctionsWrap::glTexStorage3D),
       InstanceMethod("glTexStorage3DMultisample",
                      &QOpenGLExtraFunctionsWrap::glTexStorage3DMultisample),
       InstanceMethod("glUniform1ui", &QOpenGLExtraFunctionsWrap::glUniform1ui),
       InstanceMethod("glUniform2ui", &QOpenGLExtraFunctionsWrap::glUniform2ui),
       InstanceMethod("glUniform3ui", &QOpenGLExtraFunctionsWrap::glUniform3ui),
       InstanceMethod("glUniform4ui", &QOpenGLExtraFunctionsWrap::glUniform4ui),
       InstanceMethod("glUniformBlockBinding",
                      &QOpenGLExtraFunctionsWrap::glUniformBlockBinding),
       InstanceMethod("glUnmapBuffer",
                      &QOpenGLExtraFunctionsWrap::glUnmapBuffer),
       InstanceMethod("glValidateProgramPipeline",
                      &QOpenGLExtraFunctionsWrap::glValidateProgramPipeline),
       InstanceMethod("glVertexAttribBinding",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribBinding),
       InstanceMethod("glVertexAttribDivisor",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribDivisor),
       InstanceMethod("glVertexAttribFormat",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribFormat),
       InstanceMethod("glVertexAttribI4i",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribI4i),
       InstanceMethod("glVertexAttribI4ui",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribI4ui),
       InstanceMethod("glVertexAttribIFormat",
                      &QOpenGLExtraFunctionsWrap::glVertexAttribIFormat),
       InstanceMethod("glVertexBindingDivisor",
                      &QOpenGLExtraFunctionsWrap::glVertexBindingDivisor),

       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLExtraFunctionsWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLExtraFunctions* QOpenGLExtraFunctionsWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLExtraFunctionsWrap::QOpenGLExtraFunctionsWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLExtraFunctionsWrap>(info), isOwnsInstance(true) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 0) {
    this->instance = new QOpenGLExtraFunctions();
  } else if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance =
          info[0].As<Napi::External<QOpenGLExtraFunctions>>().Data();
      this->isOwnsInstance = false;
    } else {
      Napi::Object contextObject = info[0].As<Napi::Object>();
      QOpenGLContextWrap* contextWrap =
          Napi::ObjectWrap<QOpenGLContextWrap>::Unwrap(contextObject);
      QOpenGLContext* context = contextWrap->getInternalInstance();
      this->instance = new QOpenGLExtraFunctions(context);
    }
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLExtraFunctionsWrap::~QOpenGLExtraFunctionsWrap() {
  if (this->isOwnsInstance) {
    delete this->instance;
  }
}

Napi::Value QOpenGLExtraFunctionsWrap::initializeOpenGLFunctions(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->initializeOpenGLFunctions();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint bufferId = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindBuffer(target, bufferId);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearColor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto red = info[0].As<Napi::Number>().FloatValue();
  auto green = info[1].As<Napi::Number>().FloatValue();
  auto blue = info[2].As<Napi::Number>().FloatValue();
  auto alpha = info[3].As<Napi::Number>().FloatValue();
  this->instance->glClearColor(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClear(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glClear(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFrontFace(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glFrontFace(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCullFace(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glCullFace(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDisable(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glDisable(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEnable(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  auto arg = info[0].As<Napi::Number>().Int32Value();
  this->instance->glEnable(arg);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDrawArrays(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum mode = info[0].As<Napi::Number>().Int32Value();
  GLint first = info[1].As<Napi::Number>().Int32Value();
  GLint count = info[2].As<Napi::Number>().Int32Value();
  this->instance->glDrawArrays(mode, first, count);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUseProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint programId = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glUseProgram(programId);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGetString(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum name = info[0].As<Napi::Number>().Uint32Value();
  QString result((const char*)(this->instance->glGetString(name)));
  return Napi::String::New(env, result.toStdString());
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthFunc(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum func = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDepthFunc(func);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenVertexArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLuint result = 0;
  this->instance->glGenVertexArrays(1, &result);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindVertexArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint vertextArrayFunc = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glBindVertexArray(vertextArrayFunc);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEnableVertexAttribArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glEnableVertexAttribArray(index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribPointer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLint size = info[1].As<Napi::Number>().Int32Value();
  GLenum type = info[2].As<Napi::Number>().Uint32Value();
  bool normalized = info[3].As<Napi::Boolean>().ToBoolean();
  GLsizei stride = info[4].As<Napi::Number>().Int32Value();
  uint pointer_offset = info[5].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribPointer(
      index, size, type, normalized ? GL_TRUE : GL_FALSE, stride,
      reinterpret_cast<void*>(pointer_offset));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  GLuint result = 0;
  this->instance->glGenBuffers(1, &result);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glBufferData(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint size = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  GLenum usage = info[3].As<Napi::Number>().Int32Value();
  this->instance->glBufferData(target, size, data.Data(), usage);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform1fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[1].As<Napi::ArrayBuffer>();
  this->instance->glUniform1fv(location, count,
                               static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform2fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform2fv(location, count,
                               static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform3fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform3fv(location, count,
                               static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform4fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform4fv(location, count,
                               static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform1iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[1].As<Napi::ArrayBuffer>();
  this->instance->glUniform1iv(location, count,
                               static_cast<const GLint*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform2iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform2iv(location, count,
                               static_cast<const GLint*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform3iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform3iv(location, count,
                               static_cast<const GLint*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform4iv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  Napi::ArrayBuffer data = info[2].As<Napi::ArrayBuffer>();
  this->instance->glUniform4iv(location, count,
                               static_cast<const GLint*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glActiveTexture(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum texture = info[0].As<Napi::Number>().Int32Value();
  this->instance->glActiveTexture(texture);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glAttachShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glAttachShader(program, shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindFramebuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint framebuffer = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindFramebuffer(target, framebuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindRenderbuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint renderbuffer = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindRenderbuffer(target, renderbuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindTexture(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint texture = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindTexture(target, texture);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendColor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf red = info[0].As<Napi::Number>().FloatValue();
  GLclampf green = info[1].As<Napi::Number>().FloatValue();
  GLclampf blue = info[2].As<Napi::Number>().FloatValue();
  GLclampf alpha = info[3].As<Napi::Number>().FloatValue();
  this->instance->glBlendColor(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquation(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum mode = info[0].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquation(mode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquationSeparate(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum modeRGB = info[0].As<Napi::Number>().Int32Value();
  GLenum modeAlpha = info[1].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquationSeparate(modeRGB, modeAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFunc(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum sfactor = info[0].As<Napi::Number>().Int32Value();
  GLenum dfactor = info[1].As<Napi::Number>().Int32Value();
  this->instance->glBlendFunc(sfactor, dfactor);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFuncSeparate(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum srcRGB = info[0].As<Napi::Number>().Int32Value();
  GLenum dstRGB = info[1].As<Napi::Number>().Int32Value();
  GLenum srcAlpha = info[2].As<Napi::Number>().Int32Value();
  GLenum dstAlpha = info[3].As<Napi::Number>().Int32Value();
  this->instance->glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCheckFramebufferStatus(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum result = this->instance->glCheckFramebufferStatus(target);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearDepthf(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf depth = info[0].As<Napi::Number>().FloatValue();
  this->instance->glClearDepthf(depth);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearStencil(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint s = info[0].As<Napi::Number>().Int32Value();
  this->instance->glClearStencil(s);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glColorMask(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLboolean red = info[0].As<Napi::Boolean>().Value();
  GLboolean green = info[1].As<Napi::Boolean>().Value();
  GLboolean blue = info[2].As<Napi::Boolean>().Value();
  GLboolean alpha = info[3].As<Napi::Boolean>().Value();
  this->instance->glColorMask(red, green, blue, alpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCompileShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glCompileShader(shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyTexImage2D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 8) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint level = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLint x = info[3].As<Napi::Number>().Int32Value();
  GLint y = info[4].As<Napi::Number>().Int32Value();
  GLsizei width = info[5].As<Napi::Number>().Int32Value();
  GLsizei height = info[6].As<Napi::Number>().Int32Value();
  GLint border = info[7].As<Napi::Number>().Int32Value();
  this->instance->glCopyTexImage2D(target, level, internalformat, x, y, width,
                                   height, border);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyTexSubImage2D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 8) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint level = info[1].As<Napi::Number>().Int32Value();
  GLint xoffset = info[2].As<Napi::Number>().Int32Value();
  GLint yoffset = info[3].As<Napi::Number>().Int32Value();
  GLint x = info[4].As<Napi::Number>().Int32Value();
  GLint y = info[5].As<Napi::Number>().Int32Value();
  GLsizei width = info[6].As<Napi::Number>().Int32Value();
  GLsizei height = info[7].As<Napi::Number>().Int32Value();
  this->instance->glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y,
                                      width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCreateProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint result = this->instance->glCreateProgram();
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glCreateShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum type = info[0].As<Napi::Number>().Int32Value();
  GLuint result = this->instance->glCreateShader(type);
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glDeleteProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDeleteProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDeleteShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDeleteShader(shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthMask(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  bool flag = info[0].As<Napi::Boolean>().Value();
  this->instance->glDepthMask(flag ? GL_TRUE : GL_FALSE);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDepthRangef(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf zNear = info[0].As<Napi::Number>().FloatValue();
  GLclampf zFar = info[1].As<Napi::Number>().FloatValue();
  this->instance->glDepthRangef(zNear, zFar);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDetachShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLuint shader = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glDetachShader(program, shader);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDisableVertexAttribArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glDisableVertexAttribArray(index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFinish(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glFinish();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFlush(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glFlush();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferRenderbuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLenum renderbuffertarget = info[2].As<Napi::Number>().Int32Value();
  GLuint renderbuffer = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glFramebufferRenderbuffer(target, attachment,
                                            renderbuffertarget, renderbuffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferTexture2D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLenum textarget = info[2].As<Napi::Number>().Int32Value();
  GLuint texture = info[3].As<Napi::Number>().Uint32Value();
  GLint level = info[4].As<Napi::Number>().Int32Value();
  this->instance->glFramebufferTexture2D(target, attachment, textarget, texture,
                                         level);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGenerateMipmap(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  this->instance->glGenerateMipmap(target);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGetError(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum result = this->instance->glGetError();
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glHint(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum mode = info[1].As<Napi::Number>().Int32Value();
  this->instance->glHint(target, mode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsBuffer(buffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsEnabled(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum cap = info[0].As<Napi::Number>().Int32Value();
  GLboolean result = this->instance->glIsEnabled(cap);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsFramebuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint framebuffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsFramebuffer(framebuffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsProgram(program);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsRenderbuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint renderbuffer = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsRenderbuffer(renderbuffer);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint shader = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsShader(shader);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsTexture(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint texture = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsTexture(texture);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glLineWidth(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat width = info[0].As<Napi::Number>().FloatValue();
  this->instance->glLineWidth(width);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glLinkProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glLinkProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPixelStorei(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum pname = info[0].As<Napi::Number>().Int32Value();
  GLint param = info[1].As<Napi::Number>().Int32Value();
  this->instance->glPixelStorei(pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPolygonOffset(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat factor = info[0].As<Napi::Number>().FloatValue();
  GLfloat units = info[1].As<Napi::Number>().FloatValue();
  this->instance->glPolygonOffset(factor, units);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glReleaseShaderCompiler(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glReleaseShaderCompiler();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glRenderbufferStorage(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glRenderbufferStorage(target, internalformat, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glSampleCoverage(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLclampf value = info[0].As<Napi::Number>().FloatValue();
  GLboolean invert = info[1].As<Napi::Boolean>().Value();
  this->instance->glSampleCoverage(value, invert);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glScissor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint x = info[0].As<Napi::Number>().Int32Value();
  GLint y = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glScissor(x, y, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilFunc(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum func = info[0].As<Napi::Number>().Int32Value();
  GLint ref = info[1].As<Napi::Number>().Int32Value();
  GLuint mask = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glStencilFunc(func, ref, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilFuncSeparate(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLenum func = info[1].As<Napi::Number>().Int32Value();
  GLint ref = info[2].As<Napi::Number>().Int32Value();
  GLuint mask = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glStencilFuncSeparate(face, func, ref, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilMask(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint mask = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glStencilMask(mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilMaskSeparate(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLuint mask = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glStencilMaskSeparate(face, mask);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilOp(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum fail = info[0].As<Napi::Number>().Int32Value();
  GLenum zfail = info[1].As<Napi::Number>().Int32Value();
  GLenum zpass = info[2].As<Napi::Number>().Int32Value();
  this->instance->glStencilOp(fail, zfail, zpass);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glStencilOpSeparate(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum face = info[0].As<Napi::Number>().Int32Value();
  GLenum fail = info[1].As<Napi::Number>().Int32Value();
  GLenum zfail = info[2].As<Napi::Number>().Int32Value();
  GLenum zpass = info[3].As<Napi::Number>().Int32Value();
  this->instance->glStencilOpSeparate(face, fail, zfail, zpass);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexParameterf(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLfloat param = info[2].As<Napi::Number>().FloatValue();
  this->instance->glTexParameterf(target, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexParameteri(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLint param = info[2].As<Napi::Number>().Int32Value();
  this->instance->glTexParameteri(target, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glValidateProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glValidateProgram(program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib1f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib1f(indx, x);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib2f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib2f(indx, x, y);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib3f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  GLfloat z = info[3].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib3f(indx, x, y, z);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttrib4f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint indx = info[0].As<Napi::Number>().Uint32Value();
  GLfloat x = info[1].As<Napi::Number>().FloatValue();
  GLfloat y = info[2].As<Napi::Number>().FloatValue();
  GLfloat z = info[3].As<Napi::Number>().FloatValue();
  GLfloat w = info[4].As<Napi::Number>().FloatValue();
  this->instance->glVertexAttrib4f(indx, x, y, z, w);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glViewport(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint x = info[0].As<Napi::Number>().Int32Value();
  GLint y = info[1].As<Napi::Number>().Int32Value();
  GLsizei width = info[2].As<Napi::Number>().Int32Value();
  GLsizei height = info[3].As<Napi::Number>().Int32Value();
  this->instance->glViewport(x, y, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glActiveShaderProgram(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint pipeline = info[0].As<Napi::Number>().Uint32Value();
  GLuint program = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glActiveShaderProgram(pipeline, program);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBeginQuery(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint id = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBeginQuery(target, id);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBeginTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum primitiveMode = info[0].As<Napi::Number>().Int32Value();
  this->instance->glBeginTransformFeedback(primitiveMode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindBufferBase(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint index = info[1].As<Napi::Number>().Uint32Value();
  GLuint buffer = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glBindBufferBase(target, index, buffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindImageTexture(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 7) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint unit = info[0].As<Napi::Number>().Uint32Value();
  GLuint texture = info[1].As<Napi::Number>().Uint32Value();
  GLint level = info[2].As<Napi::Number>().Int32Value();
  GLboolean layered = info[3].As<Napi::Boolean>().Value();
  GLint layer = info[4].As<Napi::Number>().Int32Value();
  GLenum access = info[5].As<Napi::Number>().Int32Value();
  GLenum format = info[6].As<Napi::Number>().Int32Value();
  this->instance->glBindImageTexture(unit, texture, level, layered, layer,
                                     access, format);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindProgramPipeline(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint pipeline = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glBindProgramPipeline(pipeline);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindSampler(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint unit = info[0].As<Napi::Number>().Uint32Value();
  GLuint sampler = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindSampler(unit, sampler);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBindTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint id = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glBindTransformFeedback(target, id);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendBarrier(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glBlendBarrier();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquationSeparatei(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buf = info[0].As<Napi::Number>().Uint32Value();
  GLenum modeRGB = info[1].As<Napi::Number>().Int32Value();
  GLenum modeAlpha = info[2].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendEquationi(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buf = info[0].As<Napi::Number>().Uint32Value();
  GLenum mode = info[1].As<Napi::Number>().Int32Value();
  this->instance->glBlendEquationi(buf, mode);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFuncSeparatei(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buf = info[0].As<Napi::Number>().Uint32Value();
  GLenum srcRGB = info[1].As<Napi::Number>().Int32Value();
  GLenum dstRGB = info[2].As<Napi::Number>().Int32Value();
  GLenum srcAlpha = info[3].As<Napi::Number>().Int32Value();
  GLenum dstAlpha = info[4].As<Napi::Number>().Int32Value();
  this->instance->glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glBlendFunci(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint buf = info[0].As<Napi::Number>().Uint32Value();
  GLenum src = info[1].As<Napi::Number>().Int32Value();
  GLenum dst = info[2].As<Napi::Number>().Int32Value();
  this->instance->glBlendFunci(buf, src, dst);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glClearBufferfi(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum buffer = info[0].As<Napi::Number>().Int32Value();
  GLint drawbuffer = info[1].As<Napi::Number>().Int32Value();
  GLfloat depth = info[2].As<Napi::Number>().FloatValue();
  GLint stencil = info[3].As<Napi::Number>().Int32Value();
  this->instance->glClearBufferfi(buffer, drawbuffer, depth, stencil);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glColorMaski(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLboolean r = info[1].As<Napi::Boolean>().Value();
  GLboolean g = info[2].As<Napi::Boolean>().Value();
  GLboolean b = info[3].As<Napi::Boolean>().Value();
  GLboolean a = info[4].As<Napi::Boolean>().Value();
  this->instance->glColorMaski(index, r, g, b, a);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyImageSubData(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 15) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint srcName = info[0].As<Napi::Number>().Uint32Value();
  GLenum srcTarget = info[1].As<Napi::Number>().Int32Value();
  GLint srcLevel = info[2].As<Napi::Number>().Int32Value();
  GLint srcX = info[3].As<Napi::Number>().Int32Value();
  GLint srcY = info[4].As<Napi::Number>().Int32Value();
  GLint srcZ = info[5].As<Napi::Number>().Int32Value();
  GLuint dstName = info[6].As<Napi::Number>().Uint32Value();
  GLenum dstTarget = info[7].As<Napi::Number>().Int32Value();
  GLint dstLevel = info[8].As<Napi::Number>().Int32Value();
  GLint dstX = info[9].As<Napi::Number>().Int32Value();
  GLint dstY = info[10].As<Napi::Number>().Int32Value();
  GLint dstZ = info[11].As<Napi::Number>().Int32Value();
  GLsizei srcWidth = info[12].As<Napi::Number>().Int32Value();
  GLsizei srcHeight = info[13].As<Napi::Number>().Int32Value();
  GLsizei srcDepth = info[14].As<Napi::Number>().Int32Value();
  this->instance->glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY,
                                     srcZ, dstName, dstTarget, dstLevel, dstX,
                                     dstY, dstZ, srcWidth, srcHeight, srcDepth);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glCopyTexSubImage3D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 9) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLint level = info[1].As<Napi::Number>().Int32Value();
  GLint xoffset = info[2].As<Napi::Number>().Int32Value();
  GLint yoffset = info[3].As<Napi::Number>().Int32Value();
  GLint zoffset = info[4].As<Napi::Number>().Int32Value();
  GLint x = info[5].As<Napi::Number>().Int32Value();
  GLint y = info[6].As<Napi::Number>().Int32Value();
  GLsizei width = info[7].As<Napi::Number>().Int32Value();
  GLsizei height = info[8].As<Napi::Number>().Int32Value();
  this->instance->glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset,
                                      x, y, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDisablei(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint index = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glDisablei(target, index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDispatchCompute(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint num_groups_x = info[0].As<Napi::Number>().Uint32Value();
  GLuint num_groups_y = info[1].As<Napi::Number>().Uint32Value();
  GLuint num_groups_z = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glDrawArraysInstanced(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum mode = info[0].As<Napi::Number>().Int32Value();
  GLint first = info[1].As<Napi::Number>().Int32Value();
  GLsizei count = info[2].As<Napi::Number>().Int32Value();
  GLsizei instancecount = info[3].As<Napi::Number>().Int32Value();
  this->instance->glDrawArraysInstanced(mode, first, count, instancecount);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEnablei(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint index = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glEnablei(target, index);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEndQuery(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  this->instance->glEndQuery(target);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glEndTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glEndTransformFeedback();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferParameteri(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLint param = info[2].As<Napi::Number>().Int32Value();
  this->instance->glFramebufferParameteri(target, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferTexture(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLuint texture = info[2].As<Napi::Number>().Uint32Value();
  GLint level = info[3].As<Napi::Number>().Int32Value();
  this->instance->glFramebufferTexture(target, attachment, texture, level);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glFramebufferTextureLayer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum attachment = info[1].As<Napi::Number>().Int32Value();
  GLuint texture = info[2].As<Napi::Number>().Uint32Value();
  GLint level = info[3].As<Napi::Number>().Int32Value();
  GLint layer = info[4].As<Napi::Number>().Int32Value();
  this->instance->glFramebufferTextureLayer(target, attachment, texture, level,
                                            layer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glGetGraphicsResetStatus(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum result = this->instance->glGetGraphicsResetStatus();
  return Napi::Number::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsEnabledi(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLuint index = info[1].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsEnabledi(target, index);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsProgramPipeline(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint pipeline = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsProgramPipeline(pipeline);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsQuery(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint id = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsQuery(id);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsSampler(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint sampler = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsSampler(sampler);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint id = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsTransformFeedback(id);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glIsVertexArray(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint array = info[0].As<Napi::Number>().Uint32Value();
  GLboolean result = this->instance->glIsVertexArray(array);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glMinSampleShading(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat value = info[0].As<Napi::Number>().FloatValue();
  this->instance->glMinSampleShading(value);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPatchParameteri(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum pname = info[0].As<Napi::Number>().Int32Value();
  GLint value = info[1].As<Napi::Number>().Int32Value();
  this->instance->glPatchParameteri(pname, value);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPauseTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glPauseTransformFeedback();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPopDebugGroup(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glPopDebugGroup();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glPrimitiveBoundingBox(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 8) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLfloat minX = info[0].As<Napi::Number>().FloatValue();
  GLfloat minY = info[1].As<Napi::Number>().FloatValue();
  GLfloat minZ = info[2].As<Napi::Number>().FloatValue();
  GLfloat minW = info[3].As<Napi::Number>().FloatValue();
  GLfloat maxX = info[4].As<Napi::Number>().FloatValue();
  GLfloat maxY = info[5].As<Napi::Number>().FloatValue();
  GLfloat maxZ = info[6].As<Napi::Number>().FloatValue();
  GLfloat maxW = info[7].As<Napi::Number>().FloatValue();
  this->instance->glPrimitiveBoundingBox(minX, minY, minZ, minW, maxX, maxY,
                                         maxZ, maxW);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramParameteri(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLint value = info[2].As<Napi::Number>().Int32Value();
  this->instance->glProgramParameteri(program, pname, value);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform1f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLfloat v0 = info[2].As<Napi::Number>().FloatValue();
  this->instance->glProgramUniform1f(program, location, v0);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform1i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLint v0 = info[2].As<Napi::Number>().Int32Value();
  this->instance->glProgramUniform1i(program, location, v0);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform1ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLuint v0 = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glProgramUniform1ui(program, location, v0);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform2f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLfloat v0 = info[2].As<Napi::Number>().FloatValue();
  GLfloat v1 = info[3].As<Napi::Number>().FloatValue();
  this->instance->glProgramUniform2f(program, location, v0, v1);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform2i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLint v0 = info[2].As<Napi::Number>().Int32Value();
  GLint v1 = info[3].As<Napi::Number>().Int32Value();
  this->instance->glProgramUniform2i(program, location, v0, v1);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform2ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLuint v0 = info[2].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glProgramUniform2ui(program, location, v0, v1);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform3f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLfloat v0 = info[2].As<Napi::Number>().FloatValue();
  GLfloat v1 = info[3].As<Napi::Number>().FloatValue();
  GLfloat v2 = info[4].As<Napi::Number>().FloatValue();
  this->instance->glProgramUniform3f(program, location, v0, v1, v2);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform3i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLint v0 = info[2].As<Napi::Number>().Int32Value();
  GLint v1 = info[3].As<Napi::Number>().Int32Value();
  GLint v2 = info[4].As<Napi::Number>().Int32Value();
  this->instance->glProgramUniform3i(program, location, v0, v1, v2);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform3ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLuint v0 = info[2].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[3].As<Napi::Number>().Uint32Value();
  GLuint v2 = info[4].As<Napi::Number>().Uint32Value();
  this->instance->glProgramUniform3ui(program, location, v0, v1, v2);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform4f(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLfloat v0 = info[2].As<Napi::Number>().FloatValue();
  GLfloat v1 = info[3].As<Napi::Number>().FloatValue();
  GLfloat v2 = info[4].As<Napi::Number>().FloatValue();
  GLfloat v3 = info[5].As<Napi::Number>().FloatValue();
  this->instance->glProgramUniform4f(program, location, v0, v1, v2, v3);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform4i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLint v0 = info[2].As<Napi::Number>().Int32Value();
  GLint v1 = info[3].As<Napi::Number>().Int32Value();
  GLint v2 = info[4].As<Napi::Number>().Int32Value();
  GLint v3 = info[5].As<Napi::Number>().Int32Value();
  this->instance->glProgramUniform4i(program, location, v0, v1, v2, v3);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glProgramUniform4ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLint location = info[1].As<Napi::Number>().Int32Value();
  GLuint v0 = info[2].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[3].As<Napi::Number>().Uint32Value();
  GLuint v2 = info[4].As<Napi::Number>().Uint32Value();
  GLuint v3 = info[5].As<Napi::Number>().Uint32Value();
  this->instance->glProgramUniform4ui(program, location, v0, v1, v2, v3);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glReadBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum src = info[0].As<Napi::Number>().Int32Value();
  this->instance->glReadBuffer(src);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glRenderbufferStorageMultisample(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLsizei samples = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLsizei width = info[3].As<Napi::Number>().Int32Value();
  GLsizei height = info[4].As<Napi::Number>().Int32Value();
  this->instance->glRenderbufferStorageMultisample(
      target, samples, internalformat, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glResumeTransformFeedback(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->instance->glResumeTransformFeedback();
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glSamplerParameterf(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint sampler = info[0].As<Napi::Number>().Uint32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLfloat param = info[2].As<Napi::Number>().FloatValue();
  this->instance->glSamplerParameterf(sampler, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glSamplerParameteri(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint sampler = info[0].As<Napi::Number>().Uint32Value();
  GLenum pname = info[1].As<Napi::Number>().Int32Value();
  GLint param = info[2].As<Napi::Number>().Int32Value();
  this->instance->glSamplerParameteri(sampler, pname, param);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[1].As<Napi::Number>().Int32Value();
  GLuint buffer = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glTexBuffer(target, internalformat, buffer);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexStorage2D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLsizei levels = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLsizei width = info[3].As<Napi::Number>().Int32Value();
  GLsizei height = info[4].As<Napi::Number>().Int32Value();
  this->instance->glTexStorage2D(target, levels, internalformat, width, height);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexStorage2DMultisample(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLsizei samples = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLsizei width = info[3].As<Napi::Number>().Int32Value();
  GLsizei height = info[4].As<Napi::Number>().Int32Value();
  GLboolean fixedsamplelocations = info[5].As<Napi::Boolean>().Value();
  this->instance->glTexStorage2DMultisample(
      target, samples, internalformat, width, height, fixedsamplelocations);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexStorage3D(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 6) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLsizei levels = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLsizei width = info[3].As<Napi::Number>().Int32Value();
  GLsizei height = info[4].As<Napi::Number>().Int32Value();
  GLsizei depth = info[5].As<Napi::Number>().Int32Value();
  this->instance->glTexStorage3D(target, levels, internalformat, width, height,
                                 depth);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glTexStorage3DMultisample(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 7) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLsizei samples = info[1].As<Napi::Number>().Int32Value();
  GLenum internalformat = info[2].As<Napi::Number>().Int32Value();
  GLsizei width = info[3].As<Napi::Number>().Int32Value();
  GLsizei height = info[4].As<Napi::Number>().Int32Value();
  GLsizei depth = info[5].As<Napi::Number>().Int32Value();
  GLboolean fixedsamplelocations = info[6].As<Napi::Boolean>().Value();
  this->instance->glTexStorage3DMultisample(target, samples, internalformat,
                                            width, height, depth,
                                            fixedsamplelocations);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform1ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glUniform1ui(location, v0);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform2ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glUniform2ui(location, v0, v1);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform3ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[2].As<Napi::Number>().Uint32Value();
  GLuint v2 = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glUniform3ui(location, v0, v1, v2);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniform4ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLuint v0 = info[1].As<Napi::Number>().Uint32Value();
  GLuint v1 = info[2].As<Napi::Number>().Uint32Value();
  GLuint v2 = info[3].As<Napi::Number>().Uint32Value();
  GLuint v3 = info[4].As<Napi::Number>().Uint32Value();
  this->instance->glUniform4ui(location, v0, v1, v2, v3);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniformBlockBinding(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint program = info[0].As<Napi::Number>().Uint32Value();
  GLuint uniformBlockIndex = info[1].As<Napi::Number>().Uint32Value();
  GLuint uniformBlockBinding = info[2].As<Napi::Number>().Uint32Value();
  this->instance->glUniformBlockBinding(program, uniformBlockIndex,
                                        uniformBlockBinding);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUnmapBuffer(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLenum target = info[0].As<Napi::Number>().Int32Value();
  GLboolean result = this->instance->glUnmapBuffer(target);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLExtraFunctionsWrap::glValidateProgramPipeline(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint pipeline = info[0].As<Napi::Number>().Uint32Value();
  this->instance->glValidateProgramPipeline(pipeline);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribBinding(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint attribindex = info[0].As<Napi::Number>().Uint32Value();
  GLuint bindingindex = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribBinding(attribindex, bindingindex);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribDivisor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLuint divisor = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribDivisor(index, divisor);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribFormat(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint attribindex = info[0].As<Napi::Number>().Uint32Value();
  GLint size = info[1].As<Napi::Number>().Int32Value();
  GLenum type = info[2].As<Napi::Number>().Int32Value();
  GLboolean normalized = info[3].As<Napi::Boolean>().Value();
  GLuint relativeoffset = info[4].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribFormat(attribindex, size, type, normalized,
                                       relativeoffset);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribI4i(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLint x = info[1].As<Napi::Number>().Int32Value();
  GLint y = info[2].As<Napi::Number>().Int32Value();
  GLint z = info[3].As<Napi::Number>().Int32Value();
  GLint w = info[4].As<Napi::Number>().Int32Value();
  this->instance->glVertexAttribI4i(index, x, y, z, w);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribI4ui(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint index = info[0].As<Napi::Number>().Uint32Value();
  GLuint x = info[1].As<Napi::Number>().Uint32Value();
  GLuint y = info[2].As<Napi::Number>().Uint32Value();
  GLuint z = info[3].As<Napi::Number>().Uint32Value();
  GLuint w = info[4].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribI4ui(index, x, y, z, w);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexAttribIFormat(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint attribindex = info[0].As<Napi::Number>().Uint32Value();
  GLint size = info[1].As<Napi::Number>().Int32Value();
  GLenum type = info[2].As<Napi::Number>().Int32Value();
  GLuint relativeoffset = info[3].As<Napi::Number>().Uint32Value();
  this->instance->glVertexAttribIFormat(attribindex, size, type,
                                        relativeoffset);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glVertexBindingDivisor(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  GLuint bindingindex = info[0].As<Napi::Number>().Uint32Value();
  GLuint divisor = info[1].As<Napi::Number>().Uint32Value();
  this->instance->glVertexBindingDivisor(bindingindex, divisor);
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniformMatrix2fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  bool transpose = info[2].As<Napi::Boolean>().Value();
  Napi::ArrayBuffer data = info[3].As<Napi::ArrayBuffer>();
  this->instance->glUniformMatrix2fv(location, count,
                                     transpose ? GL_TRUE : GL_FALSE,
                                     static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniformMatrix3fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  bool transpose = info[2].As<Napi::Boolean>().Value();
  Napi::ArrayBuffer data = info[3].As<Napi::ArrayBuffer>();
  this->instance->glUniformMatrix3fv(location, count,
                                     transpose ? GL_TRUE : GL_FALSE,
                                     static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}

Napi::Value QOpenGLExtraFunctionsWrap::glUniformMatrix4fv(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 4) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint location = info[0].As<Napi::Number>().Int32Value();
  GLsizei count = info[1].As<Napi::Number>().Int32Value();
  bool transpose = info[2].As<Napi::Boolean>().Value();
  Napi::ArrayBuffer data = info[3].As<Napi::ArrayBuffer>();
  this->instance->glUniformMatrix4fv(location, count,
                                     transpose ? GL_TRUE : GL_FALSE,
                                     static_cast<const GLfloat*>(data.Data()));
  return env.Null();
}
