#include "glad/gl.h"

#include "Application.hpp"
#include "glm/vec3.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/opengl/object/shader/ShaderFactory.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "Assignment 3 - Dmitriy Belyaikin"

using namespace assignment;

static void setupObjects(Application& application) {
    auto defaultVertexShader =
            graphics::opengl::object::shader::ShaderFactory::createShader(
            GL_VERTEX_SHADER,
            "../res/shaders/default.vert"
    );

    auto defaultFragmentShader =
            graphics::opengl::object::shader::ShaderFactory::createShader(
            GL_FRAGMENT_SHADER,
            "../res/shaders/default.frag"
    );

    const auto defaultShadersProgram =
            graphics::opengl::object::shader::ShaderFactory::createShaderProgram({
            defaultVertexShader, defaultFragmentShader
        }
    );

    defaultVertexShader.destroy();
    defaultFragmentShader.destroy();

    const auto whiteSquare = graphics::Mesh{
        {
            .vertices {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                -0.5f, 0.5f, 0.0f,

                -0.5f, 0.5f, 0.0f,
                0.5f, 0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
            },
            .elements = {

            }
        },
        defaultShadersProgram
    };

    application.addMesh(whiteSquare);
}

int main() {
    auto application = Application{
        {
            .width = WINDOW_WIDTH,
            .height = WINDOW_HEIGHT,
            .title = WINDOW_TITLE
        },
        graphics::Camera{
            glm::vec3(0.f, 0.f, -4.f)
        }
    };

    setupObjects(application);

    application.run();
    return 0;
}
