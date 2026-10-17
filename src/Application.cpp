//
// Created by Dmitriy on 02.10.2026.
//

#include "Application.hpp"

namespace assignment
{
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
