//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderer.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace assignment::opengl
{
    void Renderer::addMesh(const Mesh &mesh) {
        this->meshes.push_back(mesh);
    }

    void Renderer::render() const {
        auto model = glm::mat4x4(1.0f);

        auto [view, projection] = camera.getMatrix();

        for (const Mesh& mesh : this->meshes) {
            glUseProgram(mesh.getShaderProgram().getId());

            glBindVertexArray(mesh.getVertexArray().getId());

            const GLint modelLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            const GLint viewLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            const GLint projLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "proj");
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mesh.getVertexData().size() / 3));

            glBindVertexArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    }
}
