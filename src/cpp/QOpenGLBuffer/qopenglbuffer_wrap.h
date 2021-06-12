#pragma once

#include <napi.h>

#include <QOpenGLBuffer>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLBufferWrap
    : public Napi::ObjectWrap<QOpenGLBufferWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QOpenGLBuffer* instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLBufferWrap(const Napi::CallbackInfo& info);
  ~QOpenGLBufferWrap();
  QOpenGLBuffer* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value allocate(const Napi::CallbackInfo& info);
  Napi::Value bind(const Napi::CallbackInfo& info);
  Napi::Value bufferId(const Napi::CallbackInfo& info);
  Napi::Value create(const Napi::CallbackInfo& info);
  Napi::Value destroy(const Napi::CallbackInfo& info);
  Napi::Value release(const Napi::CallbackInfo& info);
  Napi::Value size(const Napi::CallbackInfo& info);
  Napi::Value write(const Napi::CallbackInfo& info);
};
