#include "Init.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

using namespace OGL;

Init::Init() {
    if (!glfwInit()) {
        throw std::runtime_error("Could not initialize OpenGL");
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

Init::~Init() {
    glfwTerminate();
}
