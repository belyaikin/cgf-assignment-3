//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <string>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "opengl/Renderer.hpp"

namespace assignment
{
    struct WindowProperties {
        int width;
        int height;
        std::string title;
    };

    class Application
    {
        GLFWwindow *window;

        opengl::Renderer renderer = opengl::Renderer{};

        void draw() const;

    public:
        explicit Application(const WindowProperties &windowProperties);

        void addMesh(const opengl::Mesh &mesh);

        void run();

        [[nodiscard]] opengl::Renderer getRenderer() const { return renderer; }
    };
}
