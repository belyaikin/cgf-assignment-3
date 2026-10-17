//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderable.hpp"

namespace assignment::opengl
{
    GLuint Renderable::generateVertexArray()
    {
        GLuint vertexArrayId;
        glGenVertexArrays(1, &vertexArrayId);
        return vertexArrayId;
    }

    GLuint Renderable::generateVertexBuffer()
    {
        GLuint vertexBufferId;
        glGenBuffers(1, &vertexBufferId);
        return vertexBufferId;
    }
}
