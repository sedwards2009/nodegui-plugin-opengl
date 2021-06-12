#pragma once

#include <napi.h>

#include <QOpenGLExtraFunctions>

#include <Extras/Export/export.h>
#include <core/Component/component_macro.h>


class DLL_EXPORT QOpenGLExtraFunctionsWrap
    : public Napi::ObjectWrap<QOpenGLExtraFunctionsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QOpenGLExtraFunctions* instance;
  bool isOwnsInstance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLExtraFunctionsWrap(const Napi::CallbackInfo& info);
  ~QOpenGLExtraFunctionsWrap();
  QOpenGLExtraFunctions* getInternalInstance();
  // Wrapped methods

  // Open GL Functions

  Napi::Value glActiveTexture(const Napi::CallbackInfo& info);
  Napi::Value glAttachShader(const Napi::CallbackInfo& info);
  // void 	 glBindAttribLocation(GLuint program, GLuint index, const char
  // *name)
  Napi::Value glBindBuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindFramebuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindTexture(const Napi::CallbackInfo& info);
  Napi::Value glBlendColor(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquation(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquationSeparate(const Napi::CallbackInfo& info);
  Napi::Value glBlendFunc(const Napi::CallbackInfo& info);
  Napi::Value glBlendFuncSeparate(const Napi::CallbackInfo& info);
  Napi::Value glBufferData(const Napi::CallbackInfo& info);
  // void 	 glBufferSubData(GLenum target, qopengl_GLintptr offset,
  // qopengl_GLsizeiptr size, const void *data)
  Napi::Value glCheckFramebufferStatus(const Napi::CallbackInfo& info);
  Napi::Value glClear(const Napi::CallbackInfo& info);
  Napi::Value glClearColor(const Napi::CallbackInfo& info);
  Napi::Value glClearDepthf(const Napi::CallbackInfo& info);
  Napi::Value glClearStencil(const Napi::CallbackInfo& info);
  Napi::Value glColorMask(const Napi::CallbackInfo& info);
  Napi::Value glCompileShader(const Napi::CallbackInfo& info);
  // void 	 glCompressedTexImage2D(GLenum target, GLint level, GLenum
  // internalformat, GLsizei width, GLsizei height, GLint border, GLsizei
  // imageSize, const void *data) void 	 glCompressedTexSubImage2D(GLenum
  // target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei
  // height, GLenum format, GLsizei imageSize, const void *data)
  Napi::Value glCopyTexImage2D(const Napi::CallbackInfo& info);
  Napi::Value glCopyTexSubImage2D(const Napi::CallbackInfo& info);
  Napi::Value glCreateProgram(const Napi::CallbackInfo& info);
  Napi::Value glCreateShader(const Napi::CallbackInfo& info);
  Napi::Value glCullFace(const Napi::CallbackInfo& info);
  // void 	 glDeleteBuffers(GLsizei n, const GLuint *buffers)
  // void 	 glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
  Napi::Value glDeleteProgram(const Napi::CallbackInfo& info);
  // void 	 glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
  Napi::Value glDeleteShader(const Napi::CallbackInfo& info);
  // void 	 glDeleteTextures(GLsizei n, const GLuint *textures)
  Napi::Value glDepthFunc(const Napi::CallbackInfo& info);
  Napi::Value glDepthMask(const Napi::CallbackInfo& info);
  Napi::Value glDepthRangef(const Napi::CallbackInfo& info);
  Napi::Value glDetachShader(const Napi::CallbackInfo& info);
  Napi::Value glDisable(const Napi::CallbackInfo& info);
  Napi::Value glDisableVertexAttribArray(const Napi::CallbackInfo& info);
  Napi::Value glDrawArrays(const Napi::CallbackInfo& info);
  // void 	 glDrawElements(GLenum mode, GLsizei count, GLenum type, const
  // GLvoid *indices)
  Napi::Value glEnable(const Napi::CallbackInfo& info);
  Napi::Value glEnableVertexAttribArray(const Napi::CallbackInfo& info);
  Napi::Value glFinish(const Napi::CallbackInfo& info);
  Napi::Value glFlush(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferTexture2D(const Napi::CallbackInfo& info);
  Napi::Value glFrontFace(const Napi::CallbackInfo& info);
  Napi::Value glGenBuffer(const Napi::CallbackInfo& info);
  Napi::Value glGenerateMipmap(const Napi::CallbackInfo& info);
  // void 	 glGenFramebuffers(GLsizei n, GLuint *framebuffers)
  // void 	 glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
  // void 	 glGenTextures(GLsizei n, GLuint *textures)
  // void 	 glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize,
  // GLsizei *length, GLint *size, GLenum *type, char *name) void
  // glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei
  // *length, GLint *size, GLenum *type, char *name) void
  // glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count,
  // GLuint *shaders) GLint 	 glGetAttribLocation(GLuint program, const char
  // *name) void 	 glGetBooleanv(GLenum pname, GLboolean *params) void
  // glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
  Napi::Value glGetError(const Napi::CallbackInfo& info);
  // void 	 glGetFloatv(GLenum pname, GLfloat *params)
  // void 	 glGetFramebufferAttachmentParameteriv(GLenum target, GLenum
  // attachment, GLenum pname, GLint *params) void 	 glGetIntegerv(GLenum
  // pname, GLint *params) void 	 glGetProgramInfoLog(GLuint program, GLsizei
  // bufsize, GLsizei *length, char *infolog) void 	 glGetProgramiv(GLuint
  // program, GLenum pname, GLint *params) void
  // glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
  // void 	 glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei
  // *length, char *infolog)
  // void 	 glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
  // void 	 glGetShaderPrecisionFormat(GLenum shadertype, GLenum
  // precisiontype, GLint *range, GLint *precision) void
  // glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, char
  // *source)
  Napi::Value glGetString(const Napi::CallbackInfo& info);
  // void 	 glGetTexParameterfv(GLenum target, GLenum pname, GLfloat
  // *params) void 	 glGetTexParameteriv(GLenum target, GLenum pname, GLint
  // *params) void 	 glGetUniformfv(GLuint program, GLint location, GLfloat
  // *params) void 	 glGetUniformiv(GLuint program, GLint location, GLint
  // *params) GLint 	 glGetUniformLocation(GLuint program, const char *name)
  // void 	 glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat
  // *params) void 	 glGetVertexAttribiv(GLuint index, GLenum pname, GLint
  // *params)
  // void 	 glGetVertexAttribPointerv(GLuint index, GLenum pname, void
  // **pointer)
  Napi::Value glHint(const Napi::CallbackInfo& info);
  Napi::Value glIsBuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsEnabled(const Napi::CallbackInfo& info);
  Napi::Value glIsFramebuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsProgram(const Napi::CallbackInfo& info);
  Napi::Value glIsRenderbuffer(const Napi::CallbackInfo& info);
  Napi::Value glIsShader(const Napi::CallbackInfo& info);
  Napi::Value glIsTexture(const Napi::CallbackInfo& info);
  Napi::Value glLineWidth(const Napi::CallbackInfo& info);
  Napi::Value glLinkProgram(const Napi::CallbackInfo& info);
  Napi::Value glPixelStorei(const Napi::CallbackInfo& info);
  Napi::Value glPolygonOffset(const Napi::CallbackInfo& info);
  // void 	 glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height,
  // GLenum format, GLenum type, GLvoid *pixels)
  Napi::Value glReleaseShaderCompiler(const Napi::CallbackInfo& info);
  Napi::Value glRenderbufferStorage(const Napi::CallbackInfo& info);
  Napi::Value glSampleCoverage(const Napi::CallbackInfo& info);
  Napi::Value glScissor(const Napi::CallbackInfo& info);
  // void 	 glShaderBinary(GLint n, const GLuint *shaders, GLenum
  // binaryformat, const void *binary, GLint length) void
  // glShaderSource(GLuint shader, GLsizei count, const char **string, const
  // GLint *length)
  Napi::Value glStencilFunc(const Napi::CallbackInfo& info);
  Napi::Value glStencilFuncSeparate(const Napi::CallbackInfo& info);
  Napi::Value glStencilMask(const Napi::CallbackInfo& info);
  Napi::Value glStencilMaskSeparate(const Napi::CallbackInfo& info);
  Napi::Value glStencilOp(const Napi::CallbackInfo& info);
  Napi::Value glStencilOpSeparate(const Napi::CallbackInfo& info);
  // void 	 glTexImage2D(GLenum target, GLint level, GLint internalformat,
  // GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type,
  // const GLvoid *pixels)
  Napi::Value glTexParameterf(const Napi::CallbackInfo& info);
  // void 	 glTexParameterfv(GLenum target, GLenum pname, const GLfloat
  // *params)
  Napi::Value glTexParameteri(const Napi::CallbackInfo& info);
  // void 	 glTexParameteriv(GLenum target, GLenum pname, const GLint
  // *params)
  // void 	 glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint
  // yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const
  // GLvoid *pixels)
  Napi::Value glUniform1fv(const Napi::CallbackInfo& info);
  Napi::Value glUniform1iv(const Napi::CallbackInfo& info);
  Napi::Value glUniform2fv(const Napi::CallbackInfo& info);
  Napi::Value glUniform2iv(const Napi::CallbackInfo& info);
  Napi::Value glUniform3fv(const Napi::CallbackInfo& info);
  Napi::Value glUniform3iv(const Napi::CallbackInfo& info);
  Napi::Value glUniform4fv(const Napi::CallbackInfo& info);
  Napi::Value glUniform4iv(const Napi::CallbackInfo& info);
  Napi::Value glUniformMatrix2fv(const Napi::CallbackInfo& info);
  Napi::Value glUniformMatrix3fv(const Napi::CallbackInfo& info);
  Napi::Value glUniformMatrix4fv(const Napi::CallbackInfo& info);

  Napi::Value glUseProgram(const Napi::CallbackInfo& info);
  Napi::Value glValidateProgram(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttrib1f(const Napi::CallbackInfo& info);
  // void 	 glVertexAttrib1fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib2f(const Napi::CallbackInfo& info);
  // void 	 glVertexAttrib2fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib3f(const Napi::CallbackInfo& info);
  // void 	 glVertexAttrib3fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttrib4f(const Napi::CallbackInfo& info);
  // void 	 glVertexAttrib4fv(GLuint indx, const GLfloat *values)
  Napi::Value glVertexAttribPointer(const Napi::CallbackInfo& info);
  Napi::Value glViewport(const Napi::CallbackInfo& info);
  // bool 	 hasOpenGLFeature(QOpenGLFunctions::OpenGLFeature feature) const
  Napi::Value initializeOpenGLFunctions(const Napi::CallbackInfo& info);

  // Extra Open GL Functions

  Napi::Value glActiveShaderProgram(const Napi::CallbackInfo& info);
  Napi::Value glBeginQuery(const Napi::CallbackInfo& info);
  Napi::Value glBeginTransformFeedback(const Napi::CallbackInfo& info);
  Napi::Value glBindBufferBase(const Napi::CallbackInfo& info);
  // void 	glBindBufferRange(GLenum target, GLuint index, GLuint buffer,
  // GLintptr offset, GLsizeiptr size)
  Napi::Value glBindImageTexture(const Napi::CallbackInfo& info);
  Napi::Value glBindProgramPipeline(const Napi::CallbackInfo& info);
  Napi::Value glBindSampler(const Napi::CallbackInfo& info);
  Napi::Value glBindTransformFeedback(const Napi::CallbackInfo& info);
  Napi::Value glBindVertexArray(const Napi::CallbackInfo& info);
  // void 	glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr
  // offset, GLsizei stride)
  Napi::Value glBlendBarrier(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquationSeparatei(const Napi::CallbackInfo& info);
  Napi::Value glBlendEquationi(const Napi::CallbackInfo& info);
  Napi::Value glBlendFuncSeparatei(const Napi::CallbackInfo& info);
  Napi::Value glBlendFunci(const Napi::CallbackInfo& info);
  // void 	glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint
  // srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask,
  // GLenum filter)
  Napi::Value glClearBufferfi(const Napi::CallbackInfo& info);
  // void 	glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat
  // *value) void 	glClearBufferiv(GLenum buffer, GLint drawbuffer, const
  // GLint *value) void 	glClearBufferuiv(GLenum buffer, GLint drawbuffer, const
  // GLuint *value) GLenum 	glClientWaitSync(GLsync sync, GLbitfield flags,
  // GLuint64 timeout)
  Napi::Value glColorMaski(const Napi::CallbackInfo& info);
  // void 	glCompressedTexImage3D(GLenum target, GLint level, GLenum
  // internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border,
  // GLsizei imageSize, const void *data) void glCompressedTexSubImage3D(GLenum
  // target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei
  // width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize,
  // const void *data) void 	glCopyBufferSubData(GLenum readTarget, GLenum
  // writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
  Napi::Value glCopyImageSubData(const Napi::CallbackInfo& info);
  Napi::Value glCopyTexSubImage3D(const Napi::CallbackInfo& info);
  // GLuint 	glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar
  // *const *strings)
  // void 	glDebugMessageCallback(GLDEBUGPROC callback, const void
  // *userParam) void 	glDebugMessageControl(GLenum source, GLenum type, GLenum
  // severity, GLsizei count, const GLuint *ids, GLboolean enabled) void
  // glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity,
  // GLsizei length, const GLchar *buf)
  // void 	glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines)
  // void 	glDeleteQueries(GLsizei n, const GLuint *ids)
  // void 	glDeleteSamplers(GLsizei count, const GLuint *samplers)
  // void 	glDeleteSync(GLsync sync)
  // void 	glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
  // void 	glDeleteVertexArrays(GLsizei n, const GLuint *arrays)
  Napi::Value glDisablei(const Napi::CallbackInfo& info);
  Napi::Value glDispatchCompute(const Napi::CallbackInfo& info);
  // void 	glDispatchComputeIndirect(GLintptr indirect)
  // void 	glDrawArraysIndirect(GLenum mode, const void *indirect)
  Napi::Value glDrawArraysInstanced(const Napi::CallbackInfo& info);
  // void 	glDrawBuffers(GLsizei n, const GLenum *bufs)
  // void 	glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type,
  // const void *indices, GLint basevertex) void
  // glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect) void
  // glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void
  // *indices, GLsizei instancecount) void
  // glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type,
  // const void *indices, GLsizei instancecount, GLint basevertex) void
  // glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count,
  // GLenum type, const void *indices) void
  // glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei
  // count, GLenum type, const void *indices, GLint basevertex)
  Napi::Value glEnablei(const Napi::CallbackInfo& info);
  Napi::Value glEndQuery(const Napi::CallbackInfo& info);
  Napi::Value glEndTransformFeedback(const Napi::CallbackInfo& info);
  // GLsync 	glFenceSync(GLenum condition, GLbitfield flags)
  // void 	glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr
  // length)
  Napi::Value glFramebufferParameteri(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferTexture(const Napi::CallbackInfo& info);
  Napi::Value glFramebufferTextureLayer(const Napi::CallbackInfo& info);
  // void 	glGenProgramPipelines(GLsizei n, GLuint *pipelines)
  // void 	glGenQueries(GLsizei n, GLuint *ids)
  // void 	glGenSamplers(GLsizei count, GLuint *samplers)
  // void 	glGenTransformFeedbacks(GLsizei n, GLuint *ids)
  Napi::Value glGenVertexArray(const Napi::CallbackInfo& info);
  // void 	glGetActiveUniformBlockName(GLuint program, GLuint
  // uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar
  // *uniformBlockName) void 	glGetActiveUniformBlockiv(GLuint program, GLuint
  // uniformBlockIndex, GLenum pname, GLint *params) void
  // glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint
  // *uniformIndices, GLenum pname, GLint *params) void glGetBooleani_v(GLenum
  // target, GLuint index, GLboolean *data) void
  // glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params) void
  // glGetBufferPointerv(GLenum target, GLenum pname, void **params) GLuint
  // glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum *sources, GLenum
  // *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar
  // *messageLog) GLint 	glGetFragDataLocation(GLuint program, const GLchar
  // *name) void 	glGetFramebufferParameteriv(GLenum target, GLenum pname,
  // GLint *params)
  Napi::Value glGetGraphicsResetStatus(const Napi::CallbackInfo& info);
  // void 	glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data)
  // void 	glGetInteger64v(GLenum pname, GLint64 *data)
  // void 	glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
  // void 	glGetInternalformativ(GLenum target, GLenum internalformat, GLenum
  // pname, GLsizei bufSize, GLint *params)
  // void 	glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
  // void 	glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize,
  // GLsizei *length, GLchar *label) void 	glGetObjectPtrLabel(const void
  // *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) void
  // glGetPointerv(GLenum pname, void **params)
  // void 	glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei
  // *length, GLenum *binaryFormat, void *binary) void
  // glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum
  // pname, GLint *params) void 	glGetProgramPipelineInfoLog(GLuint pipeline,
  // GLsizei bufSize, GLsizei *length, GLchar *infoLog) void
  // glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params) GLuint
  // glGetProgramResourceIndex(GLuint program, GLenum programInterface, const
  // GLchar *name) GLint 	glGetProgramResourceLocation(GLuint program,
  // GLenum programInterface, const GLchar *name) void
  // glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint
  // index, GLsizei bufSize, GLsizei *length, GLchar *name) void
  // glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint
  // index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei
  // *length, GLint *params) void 	glGetQueryObjectuiv(GLuint id, GLenum
  // pname, GLuint *params)
  // void 	glGetQueryiv(GLenum target, GLenum pname, GLint *params)
  // void 	glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint
  // *params) void 	glGetSamplerParameterIuiv(GLuint sampler, GLenum pname,
  // GLuint *params) void 	glGetSamplerParameterfv(GLuint sampler, GLenum
  // pname, GLfloat *params) void 	glGetSamplerParameteriv(GLuint sampler,
  // GLenum pname, GLint *params)
  // const GLubyte *	glGetStringi(GLenum name, GLuint index)
  // void 	glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei
  // *length, GLint *values) void 	glGetTexLevelParameterfv(GLenum target,
  // GLint level, GLenum pname, GLfloat *params) void
  // glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint
  // *params) void 	glGetTexParameterIiv(GLenum target, GLenum pname, GLint
  // *params)
  // void 	glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint
  // *params)
  // void 	glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei
  // bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) GLuint
  // glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName) void
  // glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar
  // *const *uniformNames, GLuint *uniformIndices) void glGetUniformuiv(GLuint
  // program, GLint location, GLuint *params)
  // void 	glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params)
  // void 	glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint
  // *params) void 	glGetnUniformfv(GLuint program, GLint location, GLsizei
  // bufSize, GLfloat *params) void 	glGetnUniformiv(GLuint program, GLint
  // location, GLsizei bufSize, GLint *params) void 	glGetnUniformuiv(GLuint
  // program, GLint location, GLsizei bufSize, GLuint *params) void
  // glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum
  // *attachments) void 	glInvalidateSubFramebuffer(GLenum target, GLsizei
  // numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width,
  // GLsizei height)
  Napi::Value glIsEnabledi(const Napi::CallbackInfo& info);
  Napi::Value glIsProgramPipeline(const Napi::CallbackInfo& info);
  Napi::Value glIsQuery(const Napi::CallbackInfo& info);
  Napi::Value glIsSampler(const Napi::CallbackInfo& info);
  // GLboolean 	glIsSync(GLsync sync)
  Napi::Value glIsTransformFeedback(const Napi::CallbackInfo& info);
  Napi::Value glIsVertexArray(const Napi::CallbackInfo& info);
  // void *	glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr
  // length, GLbitfield access) void 	glMemoryBarrier(GLbitfield barriers)
  // void 	glMemoryBarrierByRegion(GLbitfield barriers)
  Napi::Value glMinSampleShading(const Napi::CallbackInfo& info);
  // void 	glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const
  // GLchar *label)
  // void 	glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar
  // *label)
  Napi::Value glPatchParameteri(const Napi::CallbackInfo& info);
  Napi::Value glPauseTransformFeedback(const Napi::CallbackInfo& info);
  Napi::Value glPopDebugGroup(const Napi::CallbackInfo& info);
  Napi::Value glPrimitiveBoundingBox(const Napi::CallbackInfo& info);
  // void 	glProgramBinary(GLuint program, GLenum binaryFormat, const void
  // *binary, GLsizei length)
  Napi::Value glProgramParameteri(const Napi::CallbackInfo& info);
  Napi::Value glProgramUniform1f(const Napi::CallbackInfo& info);
  // void 	glProgramUniform1fv(GLuint program, GLint location, GLsizei count,
  // const GLfloat *value)
  Napi::Value glProgramUniform1i(const Napi::CallbackInfo& info);
  // void 	glProgramUniform1iv(GLuint program, GLint location, GLsizei count,
  // const GLint *value)
  Napi::Value glProgramUniform1ui(const Napi::CallbackInfo& info);
  // void 	glProgramUniform1uiv(GLuint program, GLint location, GLsizei count,
  // const GLuint *value)
  Napi::Value glProgramUniform2f(const Napi::CallbackInfo& info);
  // void 	glProgramUniform2fv(GLuint program, GLint location, GLsizei count,
  // const GLfloat *value)
  Napi::Value glProgramUniform2i(const Napi::CallbackInfo& info);
  // void 	glProgramUniform2iv(GLuint program, GLint location, GLsizei count,
  // const GLint *value)
  Napi::Value glProgramUniform2ui(const Napi::CallbackInfo& info);
  // void 	glProgramUniform2uiv(GLuint program, GLint location, GLsizei count,
  // const GLuint *value)
  Napi::Value glProgramUniform3f(const Napi::CallbackInfo& info);
  // void 	glProgramUniform3fv(GLuint program, GLint location, GLsizei count,
  // const GLfloat *value)
  Napi::Value glProgramUniform3i(const Napi::CallbackInfo& info);
  // void 	glProgramUniform3iv(GLuint program, GLint location, GLsizei count,
  // const GLint *value)
  Napi::Value glProgramUniform3ui(const Napi::CallbackInfo& info);
  // void 	glProgramUniform3uiv(GLuint program, GLint location, GLsizei count,
  // const GLuint *value)
  Napi::Value glProgramUniform4f(const Napi::CallbackInfo& info);
  // void 	glProgramUniform4fv(GLuint program, GLint location, GLsizei count,
  // const GLfloat *value)
  Napi::Value glProgramUniform4i(const Napi::CallbackInfo& info);
  // void 	glProgramUniform4iv(GLuint program, GLint location, GLsizei count,
  // const GLint *value)
  Napi::Value glProgramUniform4ui(const Napi::CallbackInfo& info);
  // void 	glProgramUniform4uiv(GLuint program, GLint location, GLsizei count,
  // const GLuint *value) void 	glProgramUniformMatrix2fv(GLuint program, GLint
  // location, GLsizei count, GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void
  // glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count,
  // GLboolean transpose, const GLfloat *value) void 	glPushDebugGroup(GLenum
  // source, GLuint id, GLsizei length, const GLchar *message)
  Napi::Value glReadBuffer(const Napi::CallbackInfo& info);
  // void 	glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height,
  // GLenum format, GLenum type, GLsizei bufSize, void *data)
  Napi::Value glRenderbufferStorageMultisample(const Napi::CallbackInfo& info);
  Napi::Value glResumeTransformFeedback(const Napi::CallbackInfo& info);
  // void 	glSampleMaski(GLuint maskNumber, GLbitfield mask)
  // void 	glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint
  // *param)
  // void 	glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint
  // *param)
  Napi::Value glSamplerParameterf(const Napi::CallbackInfo& info);
  // void 	glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat
  // *param)
  Napi::Value glSamplerParameteri(const Napi::CallbackInfo& info);
  // void 	glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint
  // *param)
  Napi::Value glTexBuffer(const Napi::CallbackInfo& info);
  // void 	glTexBufferRange(GLenum target, GLenum internalformat, GLuint
  // buffer, GLintptr offset, GLsizeiptr size)
  // void 	glTexImage3D(GLenum target, GLint level, GLint internalformat,
  // GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format,
  // GLenum type, const void *pixels) void 	glTexParameterIiv(GLenum target,
  // GLenum pname, const GLint *params)
  // void 	glTexParameterIuiv(GLenum target, GLenum pname, const GLuint
  // *params)
  Napi::Value glTexStorage2D(const Napi::CallbackInfo& info);
  Napi::Value glTexStorage2DMultisample(const Napi::CallbackInfo& info);
  Napi::Value glTexStorage3D(const Napi::CallbackInfo& info);
  Napi::Value glTexStorage3DMultisample(const Napi::CallbackInfo& info);
  // void 	glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint
  // yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum
  // format, GLenum type, const void *pixels) void
  // glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar
  // *const *varyings, GLenum bufferMode)
  Napi::Value glUniform1ui(const Napi::CallbackInfo& info);
  // void 	glUniform1uiv(GLint location, GLsizei count, const GLuint
  // *value)
  Napi::Value glUniform2ui(const Napi::CallbackInfo& info);
  // void 	glUniform2uiv(GLint location, GLsizei count, const GLuint
  // *value)
  Napi::Value glUniform3ui(const Napi::CallbackInfo& info);
  // void 	glUniform3uiv(GLint location, GLsizei count, const GLuint
  // *value)
  Napi::Value glUniform4ui(const Napi::CallbackInfo& info);
  // void 	glUniform4uiv(GLint location, GLsizei count, const GLuint
  // *value)
  Napi::Value glUniformBlockBinding(const Napi::CallbackInfo& info);
  // void 	glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean
  // transpose, const GLfloat *value) void 	glUniformMatrix2x4fv(GLint
  // location, GLsizei count, GLboolean transpose, const GLfloat *value) void
  // glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose,
  // const GLfloat *value) void 	glUniformMatrix3x4fv(GLint location, GLsizei
  // count, GLboolean transpose, const GLfloat *value) void
  // glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose,
  // const GLfloat *value) void 	glUniformMatrix4x3fv(GLint location, GLsizei
  // count, GLboolean transpose, const GLfloat *value)
  Napi::Value glUnmapBuffer(const Napi::CallbackInfo& info);
  // void 	glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint
  // program)
  Napi::Value glValidateProgramPipeline(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttribBinding(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttribDivisor(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttribFormat(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttribI4i(const Napi::CallbackInfo& info);
  // void 	glVertexAttribI4iv(GLuint index, const GLint *v)
  Napi::Value glVertexAttribI4ui(const Napi::CallbackInfo& info);
  // void 	glVertexAttribI4uiv(GLuint index, const GLuint *v)
  Napi::Value glVertexAttribIFormat(const Napi::CallbackInfo& info);
  // void 	glVertexAttribIPointer(GLuint index, GLint size, GLenum type,
  // GLsizei stride, const void *pointer)
  Napi::Value glVertexBindingDivisor(const Napi::CallbackInfo& info);
  // void 	glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
};
