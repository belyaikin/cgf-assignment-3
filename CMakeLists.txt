cmake_minimum_required(VERSION 4.1)
project(assignment3)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.5.1
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glm)

include_directories("deps/glad/include" "deps/stb")

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
        src/opengl/Mesh.cpp
        src/opengl/Mesh.hpp
        src/opengl/object/Buffer.hpp
        src/opengl/object/VertexArray.hpp
        src/Application.hpp
        src/Application.cpp
        src/opengl/object/shader/Shader.cpp
        src/opengl/window/WindowUtilities.cpp
        src/file/FileUtilities.hpp
        src/file/FileUtilities.cpp
        src/opengl/object/shader/ShaderProgram.cpp
        src/opengl/Camera.hpp
        src/opengl/Camera.cpp
)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw glm::glm)