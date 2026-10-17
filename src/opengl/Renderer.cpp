//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderer.hpp"

namespace assignment::opengl
{
    void Renderer::draw(const Renderable &renderable)
    {
        sendRenderableVertexDataToGpu(renderable);

        glUseProgram(renderable.getShaderProgram().getId());

        glBindVertexArray(renderable.getVertexArray().getId());

        glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(renderable.getVertexCount()));
    }

    void Renderer::sendRenderableVertexDataToGpu(const Renderable &renderable) const
    {
        glBindVertexArray(renderable.getVertexArray().getId());
        glBindBuffer(GL_ARRAY_BUFFER, renderable.getVertexBuffer().getId());

        glBufferData(
            GL_ARRAY_BUFFER,
            renderable.getVertices().size() * sizeof(float),
            renderable.getVertices().data(),
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
