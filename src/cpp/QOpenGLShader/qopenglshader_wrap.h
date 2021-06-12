#pragma once

#include <napi.h>

#include <QOpenGLShader>
#include <QPointer>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>

class DLL_EXPORT QOpenGLShaderWrap
    : public Napi::ObjectWrap<QOpenGLShaderWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QPointer<QOpenGLShader> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLShaderWrap(const Napi::CallbackInfo& info);
  ~QOpenGLShaderWrap();
  QOpenGLShader* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;

  Napi::Value compileSourceCode(const Napi::CallbackInfo& info);
  Napi::Value log(const Napi::CallbackInfo& info);
};
