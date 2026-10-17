//
// Created by Dmitriy on 17.10.2026.
//

#pragma once

#include <vector>
#include <memory>

#include "opengl/Renderable.hpp"

namespace assignment
{
    class Scene final
    {
        std::vector<opengl::Renderable*> renderables;

    public:
        void addRenderable(opengl::Renderable* renderable)
        {
            renderables.push_back(renderable);
        }

        std::vector<opengl::Renderable*> getRenderables()
        {
            return renderables;
        }
    };
}
