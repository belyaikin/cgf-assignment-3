//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include "Renderable.hpp"

namespace assignment::opengl
{
    class Renderer
    {
    public:
        void draw(const Renderable &renderable);

        void setupBuffers(const std::vector<float>& vertices, const object::VertexArray& vertexArray, const object::Buffer& vertexBuffer) const;
    };
}
