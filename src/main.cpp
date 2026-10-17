#include "glad/gl.h"

#include "Application.hpp"
#include "opengl/Renderer.hpp"
#include "opengl/object/shader/ShaderFactory.hpp"
#include "opengl/object/shader/Shaders.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Assignment 3 - Dmitriy Belyaikin"

using namespace assignment;

int main() {
    auto application = Application{
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        WINDOW_TITLE
    };

    auto basicVertexShader =
        opengl::object::shader::ShaderFactory::createShader(
            GL_VERTEX_SHADER,
            opengl::object::shader::basicVertexShaderSource
            );

    auto whiteFragmentShader =
        opengl::object::shader::ShaderFactory::createShader(
            GL_FRAGMENT_SHADER,
            opengl::object::shader::getColoredFragmentShaderSource(1.f, 0.5f, 1.f).data()
            );

    const auto whiteSquareShaderProgram =
        opengl::object::shader::ShaderFactory::createShaderProgram({
        basicVertexShader, whiteFragmentShader
    });

    basicVertexShader.destroy();
    whiteFragmentShader.destroy();

    auto whiteSquare = opengl::Renderable{
        {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f,

            -0.5f, 0.5f, 0.0f,
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
        },
        whiteSquareShaderProgram
    };

    auto scene = Scene{};
    scene.addRenderable(&whiteSquare);

    application.setScene(&scene);
    application.run();

    return 0;
}
