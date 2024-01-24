#include "Window.hpp"
#include <stdexcept>

using namespace OGL;

Window::Window(
	int width,
	int height,
	std::string name
) {
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Could not initialize OpenGL Window");
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetWindowAttrib(window, GLFW_RESIZABLE, false);

    gladLoadGL();

    glViewport(0, 0, width, height);

    glEnable(GL_DEPTH_TEST);
}

Window::~Window() {
    glfwDestroyWindow(window);
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}