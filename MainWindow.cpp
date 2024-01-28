#include "MainWindow.hpp"

#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Model.hpp"
#include "SolarSystem.hpp"

using namespace OGL;

void MainWindow::handleKeyboardInput(
    GLFWwindow* window
) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !spacePressed) {
		spacePressed = true;
		isPaused = !isPaused;
	} else if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE) {
		spacePressed = false;
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		shouldClose = true;
	}
}

MainWindow::MainWindow(
	int width,
	int height
): window(
    width,
    height,
    "Solar System"
), 
	width(width), 
	height(height) {
    isPaused = false;
	shouldClose = false;
	spacePressed = false;
	tps = 30;
}

void MainWindow::InitializeResources() {
	shader = new Shaders::Default_3D();
	lightShader = new Shaders::Light();

	ss = new SolarSystem();

	light = new 
		Point_Light(
			glm::vec3(0.0f, 0.0f, 0.0f)
		);
	light->Activate(*shader);

	camera = new
		Camera(
			width,
			height,
			glm::vec3(0.0f, 0.0f, 2.0f)
		);
}

void MainWindow::DeleteResources() {
	ss->Delete();
	shader->Delete();
	lightShader->Delete();

	delete ss;
	delete light;
	delete shader;
	delete lightShader;
	delete camera;
}

void MainWindow::Tick(
	double& then
) {
	double now = glfwGetTime();

	if (now - then >= 1.0 / tps && !isPaused) {
		ss->Tick();

		then = now;
	}
}

void MainWindow::UpdateCamera() {
	camera->handleKeyboardInput(window.window);
	camera->updateMatrix(45.0f, 0.1f, 100.0f);
}

void MainWindow::Draw() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ss->Draw(*shader, *lightShader, *camera);

	window.swapBuffers();
}

void MainWindow::mainLoop() {
	InitializeResources();

	double then = glfwGetTime();

	while (!window.shouldClose() && !shouldClose) {
		handleKeyboardInput(window.window);

		UpdateCamera();

		Draw();

		Tick(then);

		glfwPollEvents();
	}

	DeleteResources();
}
