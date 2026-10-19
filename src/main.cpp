#include "glad/gl.h"

#include "Application.hpp"
#include "opengl/Renderer.hpp"
#include "opengl/object/shader/ShaderFactory.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640
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

    auto whiteSquareShaderProgram =
        opengl::object::shader::ShaderFactory::createShaderProgram({
        defaultVertexShader, defaultFragmentShader
    });

    defaultVertexShader.destroy();
    defaultFragmentShader.destroy();

    const auto whiteSquare = opengl::Mesh{
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

    application.addMesh(whiteSquare);
    application.setCameraPosition(glm::vec3(0.f, 0.f, -4.f));
    application.run();


    return 0;
}
