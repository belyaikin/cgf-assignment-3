//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <vector>

#include "glad/gl.h"
#include "object/Buffer.hpp"
#include "object/VertexArray.hpp"
#include "object/shader/ShaderProgram.hpp"

namespace assignment::opengl
{
    class Mesh final
    {
        const object::shader::ShaderProgram shaderProgram;

        std::vector<GLfloat> vertexData;

        const object::Buffer vertexBuffer;
        const object::VertexArray vertexArray;

        static GLuint generateVertexArray();
        static GLuint generateVertexBuffer();

    public:
        Mesh(const std::vector<GLfloat> &vertexData, object::shader::ShaderProgram shaderProgram);

        [[nodiscard]] const object::shader::ShaderProgram &getShaderProgram() const { return shaderProgram; }

        [[nodiscard]] const std::vector<GLfloat> &getVertexData() const { return vertexData; }

        [[nodiscard]] const object::VertexArray &getVertexArray() const { return vertexArray; }
        [[nodiscard]] const object::Buffer &getVertexBuffer() const { return vertexBuffer; }
    };
}
