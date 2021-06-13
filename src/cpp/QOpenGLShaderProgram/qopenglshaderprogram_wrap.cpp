#include <Extras/Utils/nutils.h>
#include <QtCore/QObject/qobject_wrap.h>

#include "../QOpenGLShader/qopenglshader_wrap.h"

#include "qopenglshaderprogram_wrap.h"


Napi::FunctionReference QOpenGLShaderProgramWrap::constructor;

Napi::Object QOpenGLShaderProgramWrap::init(Napi::Env env,
                                            Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLShaderProgram";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("addShader", &QOpenGLShaderProgramWrap::addShader),
       InstanceMethod("addShaderFromSourceCode",
                      &QOpenGLShaderProgramWrap::addShaderFromSourceCode),
       InstanceMethod("bind", &QOpenGLShaderProgramWrap::bind),
       InstanceMethod("delete",
                      &QOpenGLShaderProgramWrap::delete_),
       InstanceMethod("link", &QOpenGLShaderProgramWrap::link),
       InstanceMethod("log", &QOpenGLShaderProgramWrap::log),
       InstanceMethod("programId", &QOpenGLShaderProgramWrap::programId),
       InstanceMethod("release", &QOpenGLShaderProgramWrap::release),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLShaderProgramWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLShaderProgram* QOpenGLShaderProgramWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap(
    const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLShaderProgramWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance =
          info[0].As<Napi::External<QOpenGLShaderProgram>>().Data();
      ownInstance = false;
    } else {
      Napi::Object parentObject = info[0].As<Napi::Object>();
      QObjectWrap* parentObjectWrap =
          Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
      this->instance =
          new QOpenGLShaderProgram(parentObjectWrap->getInternalInstance());
      ownInstance = true;
    }
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLShaderProgram();
    ownInstance = true;
  } else {
    Napi::TypeError::New(env,
                         "Wrong number of arguments to "
                         "QOpenGLShaderProgramWrap::QOpenGLShaderProgramWrap()")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLShaderProgramWrap::~QOpenGLShaderProgramWrap() {
  if (ownInstance) {
    extrautils::safeDelete(this->instance);
  }
}

Napi::Value QOpenGLShaderProgramWrap::addShader(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(
        env,
        "Wrong number of arguments to QOpenGLShaderProgramWrap::addShader()")
        .ThrowAsJavaScriptException();
  }

  Napi::Object shaderObject = info[0].As<Napi::Object>();
  QOpenGLShaderWrap* shaderWrap =
      Napi::ObjectWrap<QOpenGLShaderWrap>::Unwrap(shaderObject);
  QOpenGLShader* shader = shaderWrap->getInternalInstance();
  bool result = this->instance->addShader(shader);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::addShaderFromSourceCode(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  GLint type = info[0].As<Napi::Number>().Int32Value();
  QString source =
      QString::fromStdString(info[1].As<Napi::String>().Utf8Value());
  bool result = this->instance->addShaderFromSourceCode(
      static_cast<QOpenGLShader::ShaderTypeBit>(type), source);
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::bind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->bind();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::link(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->link();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLShaderProgramWrap::delete_(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  delete this->instance;
  this->instance = nullptr;
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::release(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->release();
  return env.Null();
}

Napi::Value QOpenGLShaderProgramWrap::log(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return Napi::String::New(env, this->instance->log().toStdString());
}

Napi::Value QOpenGLShaderProgramWrap::programId(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return Napi::Number::New(env, this->instance->programId());
}
