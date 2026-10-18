//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <string>

#include "../Object.hpp"

namespace assignment::opengl::object::shader
{
    class ShaderProgram : public Object
    {
    public:
        explicit ShaderProgram(const GLuint id) : Object(id) {}

        void setBool(const std::string &name, bool value);
        void setInt(const std::string &name, int value);
    };
}
