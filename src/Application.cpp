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

    void Application::run()
    {
        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            render();
        }

        glfwTerminate();
    }

    void Application::render()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        for (const opengl::Renderable* renderable : scene->getRenderables())
            renderer.draw(*renderable);

        glfwSwapBuffers(window);
    }
}
