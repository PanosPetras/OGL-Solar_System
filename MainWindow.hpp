#ifndef mainWindow_hpp
#define mainWindow_hpp

#include "GL_Window.hpp"

class MainWindow {
private:
	int width, height;

	GL_Window window;

	bool isPaused, spacePressed;
	bool shouldClose;

	void handleKeyboardInput(
		GLFWwindow* window
	);

public:
	MainWindow(
		int width,
		int height
	);

	void mainLoop();
};

#endif
