#include "GL_Init.hpp"
#include "MainWindow.hpp"

void createMainWindow() {
    //MainWindow window(1280, 720);
    MainWindow window(800, 800);

    window.mainLoop();
}

int main(void) {
    GL_Init ogl_init;

    createMainWindow();

    return 0;
}
