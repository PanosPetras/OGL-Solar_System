#include "GL_Window.hpp"
#include <stdexcept>

GL_Window::GL_Window(
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

    gladLoadGL();

    glViewport(0, 0, width, height);
}

GL_Window::~GL_Window() {
    glfwDestroyWindow(window);
}

bool GL_Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void GL_Window::swapBuffers() {
    glfwSwapBuffers(window);
}

void GL_Window::setKeyCallback(
    GLFWkeyfun callback
) {
    glfwSetKeyCallback(window, callback);
}