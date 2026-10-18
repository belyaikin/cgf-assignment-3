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

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        window = opengl::window::WindowUtilities::createWindow(
            windowProperties.width,
            windowProperties.height,
            windowProperties.title.c_str()
        );
    }

    void Application::addMesh(const opengl::Mesh &mesh) { renderer.addMesh(mesh); }

    void Application::run()
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
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.render();

        glfwSwapBuffers(window);
    }
}
