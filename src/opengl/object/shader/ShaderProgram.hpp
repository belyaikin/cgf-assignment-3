//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include "../Object.hpp"

namespace assignment::opengl::object::shader
{
    class ShaderProgram : public Object
    {
    public:
        explicit ShaderProgram(const GLuint id) : Object(id) {}
    };
}
