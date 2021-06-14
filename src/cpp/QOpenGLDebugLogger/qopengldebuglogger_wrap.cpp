#include <Extras/Utils/nutils.h>
#include <QtCore/QObject/qobject_wrap.h>

#include "qopengldebuglogger_wrap.h"


Napi::FunctionReference QOpenGLDebugLoggerWrap::constructor;

Napi::Object QOpenGLDebugLoggerWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QOpenGLDebugLogger";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("initialize", &QOpenGLDebugLoggerWrap::initialize),
                   InstanceMethod("loggedMessages", &QOpenGLDebugLoggerWrap::loggedMessages),
                   InstanceMethod("logMessage", &QOpenGLDebugLoggerWrap::logMessage),
                   COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QOpenGLDebugLoggerWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QOpenGLDebugLogger* QOpenGLDebugLoggerWrap::getInternalInstance() {
  return this->instance;
}

QOpenGLDebugLoggerWrap::QOpenGLDebugLoggerWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QOpenGLDebugLoggerWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 0) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }

  this->instance = new QOpenGLDebugLogger();
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QOpenGLDebugLoggerWrap::~QOpenGLDebugLoggerWrap() { delete this->instance; }

Napi::Value QOpenGLDebugLoggerWrap::initialize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  bool result = this->instance->initialize();
  return Napi::Boolean::New(env, result);
}

Napi::Value QOpenGLDebugLoggerWrap::loggedMessages(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  const QList<QOpenGLDebugMessage> messages = this->instance->loggedMessages();

  QString completeMsg;
  for (const QOpenGLDebugMessage &message : messages) {
    QString formattedMessage = QString("%1\t%2\t%3\t%4\t%5\n")
      .arg(message.id())
      .arg(message.severity())
      .arg(message.source())
      .arg(message.type())
      .arg(message.message());
    completeMsg.append(formattedMessage);
  }

  return Napi::String::New(env, completeMsg.toStdString());
}

Napi::Value QOpenGLDebugLoggerWrap::logMessage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QString text = QString::fromStdString(info[0].As<Napi::String>().Utf8Value());
  auto severity = static_cast<QOpenGLDebugMessage::Severity>(info[1].As<Napi::Number>().Uint32Value());
  auto type = static_cast<QOpenGLDebugMessage::Type>(info[2].As<Napi::Number>().Uint32Value());
  GLuint id = info[3].As<Napi::Number>().Uint32Value();

  QOpenGLDebugMessage debugMessage = QOpenGLDebugMessage::createApplicationMessage(text, id, severity, type);
  this->instance->logMessage(debugMessage);
  return env.Null();
}
