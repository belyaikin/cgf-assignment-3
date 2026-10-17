//
// Created by Dmitriy on 20.09.2026.
//

#pragma once
#include <string>

// This is bad

namespace assignment::opengl::object::shader
{
    constexpr auto basicVertexShaderSource =
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";

    constexpr auto *fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"

        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

    inline std::string getColoredFragmentShaderSource(float r, float g, float b) {
        return "#version 330 core\n"
               "out vec4 FragColor;\n"
               "void main()\n"
               "{\n"
               "   FragColor = vec4(" + std::to_string(r) + ", " +
                                         std::to_string(g) + ", " +
                                         std::to_string(b) + ", 1.0);\n"
               "}\n";
    }
}