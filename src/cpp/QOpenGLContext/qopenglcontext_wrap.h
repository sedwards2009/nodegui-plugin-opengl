#pragma once

#include <napi.h>

#include <QOpenGLContext>
#include <QPointer>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLContextWrap
    : public Napi::ObjectWrap<QOpenGLContextWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QPointer<QOpenGLContext> instance;
  bool isOwnsInstance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLContextWrap(const Napi::CallbackInfo& info);
  ~QOpenGLContextWrap();
  QOpenGLContext* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods

  // TODO

  // bool 	create()
  // GLuint 	defaultFramebufferObject() const
  // void 	doneCurrent()
  // QSet<QByteArray> 	extensions() const
  // QOpenGLExtraFunctions *	extraFunctions() const
  // QSurfaceFormat 	format() const

  Napi::Value extraFunctions(const Napi::CallbackInfo& info);

  // QFunctionPointer 	getProcAddress(const QByteArray &procName) const
  // QFunctionPointer 	getProcAddress(const char *procName) const
  // bool 	hasExtension(const QByteArray &extension) const

  Napi::Value isOpenGLES(const Napi::CallbackInfo& info);
  Napi::Value isValid(const Napi::CallbackInfo& info);

  // bool 	makeCurrent(QSurface *surface)
  // QVariant 	nativeHandle() const
  // QScreen *	screen() const
  // void 	setFormat(const QSurfaceFormat &format)
  // void 	setNativeHandle(const QVariant &handle)
  // void 	setScreen(QScreen *screen)
  // void 	setShareContext(QOpenGLContext *shareContext)
  // QOpenGLContext *	shareContext() const
  // QOpenGLContextGroup *	shareGroup() const
  // QSurface *	surface() const
  // void 	swapBuffers(QSurface *surface)
  // QAbstractOpenGLFunctions *	versionFunctions(const QOpenGLVersionProfile
  // &versionProfile = QOpenGLVersionProfile()) const
  // TYPE *	versionFunctions() const
};

namespace StaticOpenGLContextWrapMethods {
DLL_EXPORT Napi::Value currentContext(const Napi::CallbackInfo& info);

// TODO

// bool 	areSharing(QOpenGLContext *first, QOpenGLContext *second)
// QOpenGLContext * 	globalShareContext()
// void * 	openGLModuleHandle()    // Not supported.
// QOpenGLContext::OpenGLModuleType 	openGLModuleType()
// bool 	supportsThreadedOpenGL()  // Not supported.

}  // namespace StaticOpenGLContextWrapMethods