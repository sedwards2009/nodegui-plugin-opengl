cmake_minimum_required(VERSION 3.1)
# -------------- Plugin Config ---------------
execute_process(COMMAND node -p "require('@nodegui/nodegui/plugin').CMAKE_HELPER_FILE"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE NODEGUI_PLUGIN_CMAKE_HELPER
)
string(REPLACE "\n" "" NODEGUI_PLUGIN_CMAKE_HELPER ${NODEGUI_PLUGIN_CMAKE_HELPER})
string(REPLACE "\"" "" NODEGUI_PLUGIN_CMAKE_HELPER ${NODEGUI_PLUGIN_CMAKE_HELPER})
include("${NODEGUI_PLUGIN_CMAKE_HELPER}")

# -------------- User Config ---------------
set(PLUGIN_ADDON_NAME "nodegui_plugin_opengl")

project(${PLUGIN_ADDON_NAME})

add_library(${PLUGIN_ADDON_NAME} SHARED  
    "${CMAKE_JS_SRC}"
    "${PROJECT_SOURCE_DIR}/src/cpp/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLContext/qopenglcontext_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QSurfaceFormat/qsurfaceformat_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLShader/qopenglshader_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLWidget/nopenglwidget.hpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLWidget/qopenglwidget_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLBuffer/qopenglbuffer_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLExtraFunctions/qopenglextrafunctions_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLTexture/qopengltexture_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLVertexArrayObject/qopenglvertexarrayobject_wrap.cpp"
    "${PROJECT_SOURCE_DIR}/src/cpp/QOpenGLShaderProgram/qopenglshaderprogram_wrap.cpp"
)

AddPluginConfig(${PLUGIN_ADDON_NAME})


target_include_directories(${PLUGIN_ADDON_NAME} PRIVATE 
    "${CMAKE_JS_INC}" 
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/src/cpp"
)
target_link_libraries(${PLUGIN_ADDON_NAME} PRIVATE
    "${CMAKE_JS_LIB}"
     Qt5::Widgets
     Qt5::Gui
)
