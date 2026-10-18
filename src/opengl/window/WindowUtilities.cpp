//
// Created by Dmitriy on 18.10.26.
//

#include "WindowUtilities.hpp"

namespace assignment::window
{
    void WindowUtilities::windowSizeChangeCallback(GLFWwindow *window, const int width, const int height)
    {
        glViewport(0, 0, width, height);
    }

    GLFWwindow * WindowUtilities::createWindow(const WindowProperties &properties)
    {
        GLFWwindow* window = glfwCreateWindow(
            properties.width, properties.height,
            properties.title.c_str(),
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

        glViewport(0, 0, properties.width, properties.height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


        std::cout << "[WindowUtilities]: Created window" << std::endl;
        return window;
    }
}
