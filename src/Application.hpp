//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <string>

#include "Scene.hpp"
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

        Scene *scene;

        opengl::Renderer renderer = opengl::Renderer{};

        void render();

    public:
        explicit Application(const WindowProperties &windowProperties);

        void setScene(Scene *scene) {
            if (scene == nullptr) return;
            this->scene = scene;
        }

        void run();

        [[nodiscard]] opengl::Renderer getRenderer() const { return renderer; }
    };
}
