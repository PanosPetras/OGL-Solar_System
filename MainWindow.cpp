#include "MainWindow.hpp"

#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "GL_Model.hpp"
#include "SolarSystem.hpp"

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
}

void MainWindow::mainLoop() {
	GL_Shader shader(
		"default.vert",
		"default.frag"
	);

	GL_Shader lightShader(
		"light.vert",
		"light.frag"
	);

	SolarSystem ss;

	lightShader.Activate();

	glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
	shader.Activate();
	glUniform3f(glGetUniformLocation(shader.id, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	glEnable(GL_DEPTH_TEST);

	GL_Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	double then = glfwGetTime(), now;

	while (!window.shouldClose() && !shouldClose) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.handleKeyboardInput(window.window);
		handleKeyboardInput(window.window);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		ss.Draw(shader, lightShader, camera);

		window.swapBuffers();

		glfwPollEvents();

		now = glfwGetTime();
		if (now - then >= 2.0 / 60 && !isPaused) {
			ss.Tick();

			then = now;
		}
	}

	ss.Delete();
	shader.Delete();
	lightShader.Delete();
}
