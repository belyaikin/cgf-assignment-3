//
// Created by Dmitriy on 02.10.2026.
//

#pragma once

#include "Mesh.hpp"

namespace assignment::opengl
{
    class Renderer
    {
        std::vector<Mesh> meshes = {};

        static void setupBuffers(const std::vector<float>& vertexData, const object::VertexArray& vertexArray, const object::Buffer& vertexBuffer) ;
    public:
        void addMesh(const Mesh& mesh);
        void render() const;
    };
}
