#include <QWidget>

#include <Extras/Utils/nutils.h>

#include "qopenglwidget_wrap.h"


Napi::FunctionReference QOpenGLWidgetWrap::constructor;

Napi::Object QOpenGLWidgetWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLWidget";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLWidgetWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NOpenGLWidget* QOpenGLWidgetWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLWidgetWrap::~QOpenGLWidgetWrap() {
  extrautils::safeDelete(this->instance);
}

QOpenGLWidgetWrap::QOpenGLWidgetWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLWidgetWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    NodeWidgetWrap* parentWidgetWrap =
        Napi::ObjectWrap<NodeWidgetWrap>::Unwrap(parentObject);
    this->instance = new NOpenGLWidget(parentWidgetWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NOpenGLWidget();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  auto flexNode = this->getInternalInstance()->getFlexNode();
  YGNodeSetNodeType(flexNode, YGNodeType::YGNodeTypeText);
  this->rawData =
      extrautils::configureQWidget(this->getInternalInstance(), flexNode, true);
}
