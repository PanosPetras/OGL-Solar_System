#include "GL_Camera.hpp"
#include "C.hpp"

glm::vec3 getPos(
	int x,
	int y,
	float orbitRadius
) {
	auto pos = c(y / 200.0f, orbitRadius);

	pos = glm::rotate(pos, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	pos = glm::rotate(pos, glm::radians(x / 3.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	return pos;
}

GL_Camera::GL_Camera(
	int width, 
	int height, 
	glm::vec3 position
) {
	this->width = width;
	this->height = height;

	x = 0;
	y = 0;
	orbitRadius = 10.0f;

	Position = getPos(x, y, orbitRadius);
}


void GL_Camera::updateMatrix(
	float FOVdeg, 
	float nearPlane, 
	float farPlane
) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, glm::vec3(0.0f), Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void GL_Camera::Matrix(
	GL_Shader& shader, 
	const char* uniform
) {
	glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void GL_Camera::handleKeyboardInput(
	GLFWwindow* window
) {
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		x -= 1;
		Position = getPos(x, y, orbitRadius);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		x += 1;
		Position = getPos(x, y, orbitRadius);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		if (y / 200.0f > -0.758) {
			y -= 1;
		}
		Position = getPos(x, y, orbitRadius);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		if (y / 200.0f < 0.785) {
			y += 1;
		}
		Position = getPos(x, y, orbitRadius);
	}
}