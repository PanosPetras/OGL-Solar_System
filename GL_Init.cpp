#include "GL_Init.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

GL_Init::GL_Init() {
    if (!glfwInit()) {
        throw std::runtime_error("Could not initialize OpenGL");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

GL_Init::~GL_Init() {
    glfwTerminate();
}
