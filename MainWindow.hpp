#ifndef mainWindow_hpp
#define mainWindow_hpp

#include "GL_Window.hpp"
#include "SolarSystem.hpp"
#include "GL_Point_Light.hpp"
#include "memory"

class MainWindow {
private:
	int width, height;

	int tps;

	GL_Window window;

	bool isPaused, spacePressed;
	bool shouldClose;

	GL_Shader* shader;
	GL_Shader* lightShader;

	GL_Camera* camera;

	SolarSystem* ss;
	GL_Point_Light* light;

	void handleKeyboardInput(
		GLFWwindow* window
	);

	void InitializeResources();
	void DeleteResources();

	void Tick(
		double& then
	);

	void UpdateCamera();
	void Draw();

public:
	MainWindow(
		int width,
		int height
	);

	void mainLoop();
};

#endif
