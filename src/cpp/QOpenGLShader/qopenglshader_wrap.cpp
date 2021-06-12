#include <Extras/Utils/nutils.h>

#include "qopenglshader_wrap.h"


Napi::FunctionReference QOpenGLShaderWrap::constructor;

Napi::Object QOpenGLShaderWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLShader";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("compileSourceCode",
                                  &QOpenGLShaderWrap::compileSourceCode),
                   InstanceMethod("log", &QOpenGLShaderWrap::log),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLShaderWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLShader* QOpenGLShaderWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLShaderWrap::QOpenGLShaderWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLShaderWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    auto arg = info[0].As<Napi::Number>().Int32Value();
    this->instance =
        new QOpenGLShader(static_cast<QOpenGLShader::ShaderType>(arg));
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLShaderWrap::~QOpenGLShaderWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QOpenGLShaderWrap::compileSourceCode(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  QString source =
      QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  bool result = this->instance->compileSourceCode(source);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderWrap::log(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return Napi::String::New(env, this->instance->log().toStdString());
}
