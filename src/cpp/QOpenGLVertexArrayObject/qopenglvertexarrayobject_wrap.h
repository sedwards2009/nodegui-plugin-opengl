#pragma once

#include <napi.h>

#include <QOpenGLVertexArrayObject>
#include <QPointer>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLVertexArrayObjectWrap
    : public Napi::ObjectWrap<QOpenGLVertexArrayObjectWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QPointer<QOpenGLVertexArrayObject> instance;
  bool ownInstance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLVertexArrayObjectWrap(const Napi::CallbackInfo& info);
  ~QOpenGLVertexArrayObjectWrap();
  QOpenGLVertexArrayObject* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value bind(const Napi::CallbackInfo& info);
  Napi::Value create(const Napi::CallbackInfo& info);
  Napi::Value delete_(const Napi::CallbackInfo& info);
  Napi::Value destroy(const Napi::CallbackInfo& info);
  Napi::Value isCreated(const Napi::CallbackInfo& info);
  Napi::Value objectId(const Napi::CallbackInfo& info);
  Napi::Value release(const Napi::CallbackInfo& info);
};
