//
// Created by Dmitriy on 17.10.2026.
//

#include "Shader.hpp"

namespace assignment::opengl::object::shader
{
    void Shader::destroy() const
    {
        glDeleteShader(this->id);
    }
}
