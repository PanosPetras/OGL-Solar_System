#ifndef window_hpp
#define window_hpp

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OGL {
	class Window {
	public:
		GLFWwindow* window;

		Window(
			int width,
			int height,
			std::string name
		);
		~Window();

		bool shouldClose();

		void swapBuffers();
	};
}

#endif
