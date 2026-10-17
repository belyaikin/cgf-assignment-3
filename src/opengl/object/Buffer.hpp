//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include "Object.hpp"

namespace assignment::opengl::object
{
    class Buffer : public Object
    {
    public:
        explicit Buffer(const GLuint id)
            : Object(id)
        {
        }
    };
}
