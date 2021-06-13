#pragma once

#include <napi.h>

#include <QOpenGLShaderProgram>
#include <QPointer>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLShaderProgramWrap
    : public Napi::ObjectWrap<QOpenGLShaderProgramWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QPointer<QOpenGLShaderProgram> instance;
  bool ownInstance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLShaderProgramWrap(const Napi::CallbackInfo& info);
  ~QOpenGLShaderProgramWrap();
  QOpenGLShaderProgram* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods

  Napi::Value addShader(const Napi::CallbackInfo& info);
  Napi::Value addShaderFromSourceCode(const Napi::CallbackInfo& info);
  Napi::Value bind(const Napi::CallbackInfo& info);
  Napi::Value delete_(const Napi::CallbackInfo& info);
  Napi::Value link(const Napi::CallbackInfo& info);
  Napi::Value log(const Napi::CallbackInfo& info);
  Napi::Value programId(const Napi::CallbackInfo& info);
  Napi::Value release(const Napi::CallbackInfo& info);
};
