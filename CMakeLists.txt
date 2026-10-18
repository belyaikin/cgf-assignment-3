cmake_minimum_required(VERSION 4.1)
project(assignment3)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory("deps/glfw")

include_directories("deps/glad/include")
include_directories("deps/stb")

add_executable(${PROJECT_NAME}
        deps/glad/src/gl.c
        src/main.cpp
        src/opengl/object/shader/ShaderFactory.cpp
        src/opengl/object/shader/ShaderFactory.hpp
        src/opengl/object/shader/Shader.hpp
        src/opengl/object/Object.hpp
        src/opengl/object/shader/ShaderProgram.hpp
        src/opengl/window/WindowUtilities.hpp
        src/opengl/Renderer.cpp
        src/opengl/Renderer.hpp
        src/opengl/Renderable.cpp
        src/opengl/Renderable.hpp
        src/opengl/object/Buffer.hpp
        src/opengl/object/VertexArray.hpp
        src/Application.hpp
        src/Application.cpp
        src/opengl/object/shader/Shader.cpp
        src/Scene.hpp
        src/opengl/window/WindowUtilities.cpp
        src/file/FileUtilities.hpp
        src/file/FileUtilities.cpp
        src/opengl/object/shader/ShaderProgram.cpp
)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)