//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderer.hpp"

#include "mat4x4.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

namespace assignment::opengl
{
    void Renderer::addMesh(const Mesh &mesh) {
        this->meshes.push_back(mesh);
    }

    void Renderer::render() const {
        auto model = glm::mat4x4(1.0f);
        auto view = glm::mat4x4(1.0f);
        auto proj = glm::mat4x4(1.0f);

        view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
        proj = glm::perspective(glm::radians(45.0f), static_cast<float>(800 / 600), .1f, 100.0f);

        for (const Mesh& mesh : this->meshes) {
            setupBuffers(mesh.getVertexData(), mesh.getVertexArray(), mesh.getVertexBuffer());

            glUseProgram(mesh.getShaderProgram().getId());

            const int modelLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            const int viewLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            const int projLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "proj");
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

            glBindVertexArray(mesh.getVertexArray().getId());

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mesh.getVertexData().size() / 3));
        }
    }

    void Renderer::setupBuffers(const std::vector<GLfloat>& vertexData, const object::VertexArray& vertexArray, const object::Buffer& vertexBuffer)
    {
        glBindVertexArray(vertexArray.getId());
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer.getId());

        glBufferData(
            GL_ARRAY_BUFFER,
            vertexData.size() * sizeof(float),
            vertexData.data(),
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
