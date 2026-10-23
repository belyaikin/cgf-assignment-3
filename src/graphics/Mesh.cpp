//
// Created by Dmitriy on 02.10.2026.
//

#include "Mesh.hpp"

#include "opengl/object/shader/ShaderProgram.hpp"

namespace assignment::graphics
{
    Mesh::Mesh(const VertexData &vertexData, const opengl::object::shader::ShaderProgram shaderProgram)
        : shaderProgram(shaderProgram),
          vertexData(vertexData),
          vertexBuffer(generateVertexBuffer()),
          elementBuffer(generateElementBuffer()),
          vertexArray(generateVertexArray()) {
        // Vertex Array Object initialization should be somewhere else but not here
        glBindVertexArray(vertexArray.getId());
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer.getId());

        glBufferData(
            GL_ARRAY_BUFFER,
            static_cast<GLsizeiptr>(vertexData.vertices.size() * sizeof(float)),
            vertexData.vertices.data(),
            GL_STATIC_DRAW
        );

        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            3 * sizeof(float),
            nullptr
        );
        glEnableVertexAttribArray(0);

        if (!vertexData.elements.empty()) {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer.getId());
            glBufferData(
                GL_ELEMENT_ARRAY_BUFFER,
                static_cast<GLsizeiptr>(vertexData.elements.size() * sizeof(GLuint)),
                vertexData.elements.data(),
                GL_STATIC_DRAW
            );
        }

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    GLuint Mesh::generateVertexArray()
    {
        GLuint vertexArrayId;
        glGenVertexArrays(1, &vertexArrayId);
        return vertexArrayId;
    }

    GLuint Mesh::generateVertexBuffer()
    {
        GLuint vertexBufferId;
        glGenBuffers(1, &vertexBufferId);
        return vertexBufferId;
    }

    GLuint Mesh::generateElementBuffer() {
        GLuint elementBufferId;
        glGenBuffers(1, &elementBufferId);
        return elementBufferId;
    }
}
