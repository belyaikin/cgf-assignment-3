//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <string>

#include "../Object.hpp"
#include "glad/gl.h"

namespace assignment::opengl::object::shader
{
    class Shader : public Object
    {
        std::string path;

    public:
        explicit Shader(const GLuint id) : Object(id) {}

        void setBool(std::string name, bool value);
        void setInt(std::string name, int value);
        void setString(std::string name, std::string value);

        void destroy();
    };
}
