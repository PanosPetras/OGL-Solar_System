#ifndef mainWindow_hpp
#define mainWindow_hpp

#include "GL_Window.hpp"

class MainWindow {
private:
	int width, height;

	GL_Window window;

	bool isPaused;

	void draw(); 
	void handleKeyboardInput(
		GLFWwindow* window,
		int key,
		int scancode,
		int action,
		int mods
	);

public:
	MainWindow(
		int width,
		int height
	);

	void mainLoop();
};

#endif
