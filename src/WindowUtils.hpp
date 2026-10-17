//
// Created by Dmitriy on 02.10.2026.
//

#pragma once
#include <iostream>

#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace assignment::opengl
{
    class WindowUtilities
    {
    public:
        static void windowSizeChangeCallback(GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        static GLFWwindow* createWindow(const int width, const int height, const std::string &title) {
            GLFWwindow* window = glfwCreateWindow(
                width, height,
                title.c_str(),
                nullptr, nullptr
            );

            if (!window) {
                std::cout << "[WindowUtilities]: Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return nullptr;
            }

            glfwMakeContextCurrent(window);
            glfwSetWindowSizeCallback(window, windowSizeChangeCallback);

            if (!gladLoadGL(glfwGetProcAddress)) {
                std::cout << "[WindowUtilities]: Failed to initialize GLAD" << std::endl;
                glfwTerminate();
                return nullptr;
            }

            glViewport(0, 0, width, height);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


            std::cout << "[WindowUtilities]: Created window" << std::endl;
            return window;
        }
    };
}
