//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderer.hpp"

namespace assignment::opengl
{
    void Renderer::draw(const Renderable &renderable)
    {
        setupBuffers(renderable.getVertices(), renderable.getVertexArray(), renderable.getVertexBuffer());

        glUseProgram(renderable.getShaderProgram().getId());

        glBindVertexArray(renderable.getVertexArray().getId());

        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(renderable.getVertexCount()));
    }

    void Renderer::setupBuffers(const std::vector<GLfloat>& vertices, const object::VertexArray& vertexArray, const object::Buffer& vertexBuffer) const
    {
        glBindVertexArray(vertexArray.getId());
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer.getId());

        glBufferData(
            GL_ARRAY_BUFFER,
            vertices.size() * sizeof(float),
            vertices.data(),
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

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
