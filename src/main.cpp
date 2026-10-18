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
        {
            .width = WINDOW_WIDTH,
            .height = WINDOW_HEIGHT,
            .title = WINDOW_TITLE
        }
    };

    auto defaultVertexShader =
        opengl::object::shader::ShaderFactory::createShader(
            GL_VERTEX_SHADER,
            "../res/shaders/default.vert"
            );

    auto defaultFragmentShader =
        opengl::object::shader::ShaderFactory::createShader(
            GL_FRAGMENT_SHADER,
            "../res/shaders/default.frag"
            );

    const auto whiteSquareShaderProgram =
        opengl::object::shader::ShaderFactory::createShaderProgram({
        defaultVertexShader, defaultFragmentShader
    });

    defaultVertexShader.destroy();
    defaultFragmentShader.destroy();

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
