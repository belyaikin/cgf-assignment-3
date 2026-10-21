//
// Created by Dmitriy on 02.10.2026.
//

#pragma once

#include "Mesh.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

namespace assignment::opengl
{
    class Renderer
    {
        std::vector<Mesh> meshes = {};

        glm::vec2 frameBufferSize;

        glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
        float cameraFov = 45.0f;
    public:
        void addMesh(const Mesh& mesh);

        [[nodiscard]] const glm::vec2& getFrameBufferSize() const { return frameBufferSize; }
        void setFrameBufferSize(const glm::vec2& value) { this->frameBufferSize = value; }

        [[nodiscard]] const glm::vec3& getCameraPosition() const { return cameraPosition; }
        void setCameraPosition(const glm::vec3& value) { this->cameraPosition = value; }

        [[nodiscard]] float getCameraFov() const { return cameraFov; }
        void setCameraFov(const float value) { this->cameraFov = value; }

        void render() const;
    };
}
