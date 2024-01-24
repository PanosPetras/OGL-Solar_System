#ifndef mainWindow_hpp
#define mainWindow_hpp

#include "Window.hpp"
#include "SolarSystem.hpp"
#include "Point_Light.hpp"
#include "memory"

class MainWindow {
private:
	int width, height;

	int tps;

	OGL::Window window;

	bool isPaused, spacePressed;
	bool shouldClose;

	OGL::Shader* shader;
	OGL::Shader* lightShader;

	OGL::Camera* camera;

	SolarSystem* ss;
	OGL::Point_Light* light;

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
