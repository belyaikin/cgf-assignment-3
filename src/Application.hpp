//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <string>

#include "Scene.hpp"
#include "WindowUtils.hpp"
#include "GLFW/glfw3.h"
#include "opengl/Renderer.hpp"

namespace assignment
{
    class Application
    {
        GLFWwindow *window;

        Scene *scene;

        opengl::Renderer renderer = opengl::Renderer{};

        void render();

    public:
        explicit Application(const int windowWidth, const int windowHeight, const std::string& windowTitle)
        {
            if (!glfwInit()) return;

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

            window = opengl::WindowUtilities::createWindow(windowWidth, windowHeight, windowTitle);
        }

        void setScene(Scene *scene) {this->scene = scene;}

        void run();

        [[nodiscard]] opengl::Renderer getRenderer() const { return renderer; }
    };
}
