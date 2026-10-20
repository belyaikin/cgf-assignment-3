//
// Created by Dmitriy on 02.10.2026.
//

#include "Application.hpp"

#include "opengl/window/WindowUtilities.hpp"

namespace assignment
{
    Application::Application(const WindowProperties &windowProperties)
    {
        if (!glfwInit()) return;

        std::cout << "[Application]: Initialized GLFW\n";

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        window = opengl::window::WindowUtilities::createWindow(
            windowProperties.width,
            windowProperties.height,
            windowProperties.title.c_str()
        );

        glEnable(GL_DEPTH_TEST);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        std::cout << "[Application]: Initialized application\n";
    }

    void Application::addMesh(const opengl::Mesh &mesh) { renderer.addMesh(mesh); }

    void Application::run() const
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            draw();
        }

        glfwTerminate();
    }

    void Application::draw() const
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderer.render();

        glfwSwapBuffers(window);
    }
}
