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
    class Renderable
    {
        const object::shader::ShaderProgram shaderProgram;

        std::vector<GLfloat> vertices;

        const object::Buffer vertexBuffer;
        const object::VertexArray vertexArray;

        static GLuint generateVertexArray();
        static GLuint generateVertexBuffer();

    public:
        Renderable(const std::vector<GLfloat> &vertices, const object::shader::ShaderProgram shaderProgram) :
            shaderProgram(shaderProgram),
            vertices(vertices),
            vertexBuffer(generateVertexBuffer()),
            vertexArray(generateVertexArray())
        {}

        [[nodiscard]] const object::shader::ShaderProgram &getShaderProgram() const { return shaderProgram; }

        [[nodiscard]] std::vector<float> getVertices() const { return vertices; }
        [[nodiscard]] int getVertexCount() const { return vertices.size() / 3; }

        [[nodiscard]] const object::VertexArray &getVertexArray() const { return vertexArray; }
        [[nodiscard]] const object::Buffer &getVertexBuffer() const { return vertexBuffer; }
    };
}
