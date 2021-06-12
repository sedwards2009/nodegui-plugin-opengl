#pragma once

#include <napi.h>

#include <QSurfaceFormat>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QSurfaceFormatWrap
    : public Napi::ObjectWrap<QSurfaceFormatWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QSurfaceFormat* instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QSurfaceFormatWrap(const Napi::CallbackInfo& info);
  ~QSurfaceFormatWrap();
  QSurfaceFormat* getInternalInstance();

  // Wrapped methods
  Napi::Value setDepthBufferSize(const Napi::CallbackInfo& info);
  Napi::Value profile(const Napi::CallbackInfo& info);
  Napi::Value setProfile(const Napi::CallbackInfo& info);
  Napi::Value setStencilBufferSize(const Napi::CallbackInfo& info);
  Napi::Value setMajorVersion(const Napi::CallbackInfo& info);
  Napi::Value setMinorVersion(const Napi::CallbackInfo& info);
};

namespace StaticQSurfaceFormatWrapMethods {
DLL_EXPORT Napi::Value setDefaultFormat(const Napi::CallbackInfo& info);
DLL_EXPORT Napi::Value defaultFormat(const Napi::CallbackInfo& info);
}  // namespace StaticQSurfaceFormatWrapMethods
