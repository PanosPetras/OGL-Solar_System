#include "GL_Init.hpp"
#include "MainWindow.hpp"
#include <iostream>
#include <cstdlib>

//#define ASK_FOR_WINDOW_SIZE

void createMainWindow() {
    int width = 1280, height = 720;

#ifdef ASK_FOR_WINDOW_SIZE
    std::cout << "Please enter Window dimensions(format: (width, height)): ";
    scanf_s("(%d, %d)", &width, &height);
#endif

    MainWindow window(width, height);

    window.mainLoop();
}

int main(void) {
    GL_Init ogl_init;

    createMainWindow();

    return 0;
}
