//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <vector>

#include "glad/gl.h"
#include "opengl/object/Buffer.hpp"
#include "opengl/object/VertexArray.hpp"
#include "opengl/object/shader/ShaderProgram.hpp"

namespace assignment::graphics
{
    class Mesh final
    {
        struct VertexData {
            std::vector<GLfloat> vertices;
            std::vector<GLfloat> elements;
        };

        const opengl::object::shader::ShaderProgram shaderProgram;

        VertexData vertexData;

        const opengl::object::Buffer vertexBuffer;
        const opengl::object::VertexArray vertexArray;

        static GLuint generateVertexArray();
        static GLuint generateVertexBuffer();

    public:
        Mesh(const VertexData &vertexData, opengl::object::shader::ShaderProgram shaderProgram);

        [[nodiscard]] const opengl::object::shader::ShaderProgram &getShaderProgram() const { return shaderProgram; }

        [[nodiscard]] const VertexData &getVertexData() const { return vertexData; }

        [[nodiscard]] const opengl::object::VertexArray &getVertexArray() const { return vertexArray; }
        [[nodiscard]] const opengl::object::Buffer &getVertexBuffer() const { return vertexBuffer; }
    };
}
