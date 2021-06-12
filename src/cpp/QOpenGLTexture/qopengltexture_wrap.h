#pragma once

#include <napi.h>

#include <QOpenGLTexture>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLTextureWrap
    : public Napi::ObjectWrap<QOpenGLTextureWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QOpenGLTexture* instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLTextureWrap(const Napi::CallbackInfo& info);
  ~QOpenGLTextureWrap();
  QOpenGLTexture* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods

  Napi::Value bind(const Napi::CallbackInfo& info);
};
