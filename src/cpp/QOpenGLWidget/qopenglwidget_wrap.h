#pragma once

#include <napi.h>

#include <QPointer>

#include <Extras/Export/export.h>
#include <QtWidgets/QWidget/qwidget_macro.h>

#include "nopenglwidget.hpp"

class DLL_EXPORT QOpenGLWidgetWrap
    : public Napi::ObjectWrap<QOpenGLWidgetWrap> {
 private:
  QPointer<NOpenGLWidget> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLWidgetWrap(const Napi::CallbackInfo& info);
  ~QOpenGLWidgetWrap();
  NOpenGLWidget* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  QWIDGET_WRAPPED_METHODS_DECLARATION
};
