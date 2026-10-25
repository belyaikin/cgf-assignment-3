//
// Created by Dmitriy on 02.10.2026.
//

#include "Renderer.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace assignment::graphics
{
    void Renderer::addMesh(const Mesh &mesh) {
        this->meshes.push_back(mesh);
    }

    void Renderer::render() const {
        auto [view, projection] = camera.getMatrix();

        for (const Mesh& mesh : this->meshes) {
            glUseProgram(mesh.getShaderProgram().getId());
            glBindVertexArray(mesh.getVertexArray().getId());

            const glm::mat4 model = glm::translate(
                glm::mat4(1.0f),
                mesh.getPosition()
            );

            const GLint modelLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            const GLint viewLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            const GLint projLoc = glGetUniformLocation(mesh.getShaderProgram().getId(), "proj");
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

            constexpr glm::vec4 lightColor = {1.0f, 0.0f, 0.0f, 1.0f};
            constexpr glm::vec3 lightPosition = {-4.0f, 2.0f, -3.0f};
            glUniform4f(glGetUniformLocation(mesh.getShaderProgram().getId(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
            glUniform3f(glGetUniformLocation(mesh.getShaderProgram().getId(), "lightPosition"), lightColor.x, lightColor.y, lightColor.z);

            if (!mesh.getVertexData().elements.empty()) {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.getElementBuffer().getId());
                glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mesh.getVertexData().elements.size()), GL_UNSIGNED_INT, nullptr);
            } else {
                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(mesh.getVertexData().vertices.size() / 3));
            }

            glBindVertexArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    }
}
