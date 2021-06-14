#pragma once

#include <napi.h>

#include <QOpenGLDebugLogger>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLDebugLoggerWrap : public Napi::ObjectWrap<QOpenGLDebugLoggerWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QOpenGLDebugLogger* instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLDebugLoggerWrap(const Napi::CallbackInfo& info);
  ~QOpenGLDebugLoggerWrap();
  QOpenGLDebugLogger* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value initialize(const Napi::CallbackInfo& info);
  Napi::Value loggedMessages(const Napi::CallbackInfo& info);
  Napi::Value logMessage(const Napi::CallbackInfo& info);
};
