#include <Extras/Utils/nutils.h>
#include <QtCore/QObject/qobject_wrap.h>

#include "../QOpenGLExtraFunctions/qopenglextrafunctions_wrap.h"

#include "qopenglcontext_wrap.h"

Napi::FunctionReference QOpenGLContextWrap::constructor;

Napi::Object QOpenGLContextWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLContext";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("injectNodeEventEmitter", &QOpenGLContextWrap::injectNodeEventEmitter),
       InstanceMethod("extraFunctions", &QOpenGLContextWrap::extraFunctions),
       InstanceMethod("hasExtension", &QOpenGLContextWrap::hasExtension),
       InstanceMethod("isOpenGLES", &QOpenGLContextWrap::isOpenGLES),
       InstanceMethod("isValid", &QOpenGLContextWrap::isValid),
       StaticMethod("currentContext",
                    &StaticOpenGLContextWrapMethods::currentContext),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLContextWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLContext* QOpenGLContextWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLContextWrap::QOpenGLContextWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLContextWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    if (info[0].IsExternal()) {
      this->instance = info[0].As<Napi::External<QOpenGLContext>>().Data();
      this->isOwnsInstance =
          false;  // Instance was created elsewhere and shared with us.
    } else {
      Napi::Object parentObject = info[0].As<Napi::Object>();
      QObjectWrap* parentObjectWrap =
          Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
      this->instance =
          new QOpenGLContext(parentObjectWrap->getInternalInstance());
      this->isOwnsInstance = true;
    }
  } else if (info.Length() == 0) {
    this->instance = new QOpenGLContext();
    this->isOwnsInstance = true;
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLContextWrap::~QOpenGLContextWrap() {
  if (this->isOwnsInstance) {
    extrautils::safeDelete(this->instance);
  }
}

Napi::Value QOpenGLContextWrap::injectNodeEventEmitter(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  this->emitOnNode = Napi::Persistent(info[0].As<Napi::Function>());

  QObject::connect(this->instance, &QOpenGLContext::aboutToBeDestroyed, [=]() {
    Napi::Env env = this->emitOnNode.Env();
    Napi::HandleScope scope(env);
    this->emitOnNode.Call({Napi::String::New(env, "AboutToBeDestroyed")});
  });

  return env.Null();
}

Napi::Value QOpenGLContextWrap::extraFunctions(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QOpenGLExtraFunctions* functions = this->instance->extraFunctions();
  if (functions == nullptr) {
    return env.Null();
  }

  auto instance = QOpenGLExtraFunctionsWrap::constructor.New(
      {Napi::External<QOpenGLExtraFunctions>::New(env, functions)});
  return instance;
}

Napi::Value QOpenGLContextWrap::hasExtension(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string name = info[0].As<Napi::String>().Utf8Value();
  bool result = this->instance->hasExtension(QByteArray(name.data()));
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLContextWrap::isOpenGLES(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->isOpenGLES();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLContextWrap::isValid(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->isValid();
  return Napi::Boolean::New(env, result);
}

Napi::Value StaticOpenGLContextWrapMethods::currentContext(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QOpenGLContext* context = QOpenGLContext::currentContext();
  if (context == nullptr) {
    return env.Null();
  }
  auto instance = QOpenGLContextWrap::constructor.New(
      {Napi::External<QOpenGLContext>::New(env, context)});
  return instance;
}
