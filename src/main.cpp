#include "glad/gl.h"

#include "Application.hpp"
#include "glm/vec3.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Mesh.hpp"
#include "graphics/opengl/object/shader/ShaderFactory.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 920
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

    const auto cube = graphics::Mesh{
        {
            .vertices {
                // Front
                -0.5f, -0.5f, 0.5f,
                 0.5f, -0.5f, 0.5f,
                 0.5f,  0.5f, 0.5f,
                 0.5f,  0.5f, 0.5f,
                -0.5f,  0.5f, 0.5f,
                -0.5f, -0.5f, 0.5f,

                // Back
                -0.5f, -0.5f, -0.5f,
                -0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,

                // Left
                -0.5f,  0.5f,  0.5f,
                -0.5f,  0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f, -0.5f,
                -0.5f, -0.5f,  0.5f,
                -0.5f,  0.5f,  0.5f,

                // Right
                 0.5f,  0.5f,  0.5f,
                 0.5f, -0.5f,  0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f,  0.5f, -0.5f,
                 0.5f,  0.5f,  0.5f,

                // Top
                -0.5f,  0.5f, -0.5f,
                -0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f,  0.5f,
                 0.5f,  0.5f, -0.5f,
                -0.5f,  0.5f, -0.5f,

                // Bottom
                -0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f, -0.5f,
                 0.5f, -0.5f,  0.5f,
                 0.5f, -0.5f,  0.5f,
                -0.5f, -0.5f,  0.5f,
                -0.5f, -0.5f, -0.5f,
            },
            .elements = {
                0, 1, 2,
                3, 4, 5,

                6, 7, 8,
                9, 10, 11,

                12, 13, 14,
                15, 16, 17,

                18, 19, 20,
                21, 22, 23,

                24, 25, 26,
                27, 28, 29,

                30, 31, 32,
                33, 34, 35,
            }
        },
        defaultShadersProgram
    };

    application.addMesh(cube);
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
