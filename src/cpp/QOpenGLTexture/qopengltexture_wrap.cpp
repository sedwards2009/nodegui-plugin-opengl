#include <Extras/Utils/nutils.h>
#include <QtGui/QImage/qimage_wrap.h>

#include "qopengltexture_wrap.h"


Napi::FunctionReference QOpenGLTextureWrap::constructor;

Napi::Object QOpenGLTextureWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLTexture";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("bind", &QOpenGLTextureWrap::bind),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLTextureWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLTexture* QOpenGLTextureWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLTextureWrap::QOpenGLTextureWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLTextureWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 2) {
    Napi::Object qimageObject = info[0].As<Napi::Object>();
    QImageWrap* qimageObjectWrap =
        Napi::ObjectWrap<QImageWrap>::Unwrap(qimageObject);

    auto arg2 = info[1].As<Napi::Number>().Int32Value();
    this->instance =
        new QOpenGLTexture(*qimageObjectWrap->getInternalInstance(),
                           static_cast<QOpenGLTexture::MipMapGeneration>(arg2));
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments to QOpenGLTextureWrap")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLTextureWrap::~QOpenGLTextureWrap() { delete this->instance; }

Napi::Value QOpenGLTextureWrap::bind(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance->bind();
  return env.Null();
}
