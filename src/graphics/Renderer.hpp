//
// Created by Dmitriy on 02.10.2026.
//

#pragma once

#include "Camera.hpp"
#include "Mesh.hpp"

namespace assignment::graphics
{
    class Renderer
    {
        std::vector<Mesh> meshes = {};

    public:
        Camera camera;

        explicit Renderer(const Camera& camera) : camera(camera) {}

        void addMesh(const Mesh& mesh);

        void render() const;
    };
}
