#ifndef gl_window_hpp
#define gl_window_hpp

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GL_Window {
public:
	GLFWwindow *window;

public:
	GL_Window(
		int width,
		int height,
		std::string name
	);
	~GL_Window();

	bool shouldClose();

	void swapBuffers();

	void setKeyCallback(
		GLFWkeyfun callback
	);
};
#endif
