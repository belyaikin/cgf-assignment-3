//
// Created by Dmitriy on 20.09.2026.
//

#include "ShaderFactory.hpp"

#include <iostream>

#include "glad/gl.h"

namespace assignment::opengl::object::shader
{
    Shader ShaderFactory::createShader(const GLenum type, const char *shaderSource) {
        const auto shader = Shader{glCreateShader(type)};

        glShaderSource(shader.getId(), 1, &shaderSource, nullptr);
        glCompileShader(shader.getId());

        int success;
        char infoLog[512];
        glGetShaderiv(shader.getId(), GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(shader.getId(), 512, nullptr, infoLog);
            std::cout << "[ShaderFactory]: " << infoLog << std::endl;
        }

        std::cout << "[ShaderFactory]: Successfully compiled shader " << shader.getId() << std::endl;

        return shader;
    }

    ShaderProgram ShaderFactory::createShaderProgram(const std::vector<Shader>& shaders) {
        const auto shaderProgram = ShaderProgram{glCreateProgram()};

        std::cout << "[ShaderFactory]: Created shader program " << shaderProgram.getId() << std::endl;

        for (const Shader& shader : shaders) {
            glAttachShader(shaderProgram.getId(), shader.getId());

            std::cout << "[ShaderFactory]: Attached shader " << shader.getId() << " to shader program " << shaderProgram.getId() << std::endl;
        }

        glLinkProgram(shaderProgram.getId());

        return shaderProgram;
    }
}