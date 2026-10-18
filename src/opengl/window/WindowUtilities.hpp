//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <iostream>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace assignment::window
{
    class WindowUtilities
    {
    public:
        struct WindowProperties {
            int width;
            int height;
            std::string title;
        };

        static void windowSizeChangeCallback(GLFWwindow *window, int width, int height);

        static GLFWwindow* createWindow(const WindowProperties& properties);
    };
}
