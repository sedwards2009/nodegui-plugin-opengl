#include <Extras/Utils/nutils.h>
#include <QtCore/QObject/qobject_wrap.h>

#include "qopenglbuffer_wrap.h"


Napi::FunctionReference QOpenGLBufferWrap::constructor;

Napi::Object QOpenGLBufferWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLBuffer";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("allocate", &QOpenGLBufferWrap::allocate),
                   InstanceMethod("bind", &QOpenGLBufferWrap::bind),
                   InstanceMethod("bufferId", &QOpenGLBufferWrap::bufferId),
                   InstanceMethod("create", &QOpenGLBufferWrap::create),
                   InstanceMethod("destroy", &QOpenGLBufferWrap::destroy),
                   InstanceMethod("release", &QOpenGLBufferWrap::release),
                   InstanceMethod("size", &QOpenGLBufferWrap::size),
                   InstanceMethod("write", &QOpenGLBufferWrap::write),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLBufferWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLBuffer* QOpenGLBufferWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLBufferWrap::QOpenGLBufferWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLBufferWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  int type = info[0].As<Napi::Number>().Int32Value();
  this->instance = new QOpenGLBuffer(static_cast<QOpenGLBuffer::Type>(type));
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLBufferWrap::~QOpenGLBufferWrap() { delete this->instance; }

Napi::Value QOpenGLBufferWrap::allocate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int bytes = info[0].As<Napi::Number>().Int32Value();
  this->instance->allocate(bytes);
  return env.Null();
}

Napi::Value QOpenGLBufferWrap::bind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->bind();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLBufferWrap::create(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->create();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLBufferWrap::destroy(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->destroy();
  return env.Null();
}

Napi::Value QOpenGLBufferWrap::release(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->release();
  return env.Null();
}

Napi::Value QOpenGLBufferWrap::write(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 3) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  // Args: int offset, ArrayBuffer* data, int count
  auto offset = info[0].As<Napi::Number>().Int32Value();
  auto arrayBuffer = info[1].As<Napi::ArrayBuffer>();
  auto count = info[2].As<Napi::Number>().Int32Value();
  this->instance->write(offset, arrayBuffer.Data(), count);
  return env.Null();
}

Napi::Value QOpenGLBufferWrap::size(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int size = this->instance->size();
  return Napi::Number::New(env, size);
}

Napi::Value QOpenGLBufferWrap::bufferId(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int id = this->instance->bufferId();
  return Napi::Number::New(env, id);
}
