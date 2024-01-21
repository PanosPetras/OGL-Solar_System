#include "GL_Init.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

GL_Init::GL_Init() {
    if (!glfwInit()) {
        throw std::runtime_error("Could not initialize OpenGL");
    }
}

GL_Init::~GL_Init() {
    glfwTerminate();
}
