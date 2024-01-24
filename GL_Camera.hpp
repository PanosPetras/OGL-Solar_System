#ifndef gl_camera_hpp
#define gl_camera_hpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "GL_Shader.hpp"

class GL_Camera {
protected:
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	bool firstClick = true;

	int width;
	int height;

	int x, y;
	float orbitRadius;

	float speed = 0.1f;
	float sensitivity = 100.0f;

public:
	glm::vec3 Position;

	GL_Camera(
		int width, 
		int height, 
		glm::vec3 position
	);

	void updateMatrix(
		float FOVdeg, 
		float nearPlane, 
		float farPlane
	);
	void Matrix(
		GL_Shader& shader, 
		const char* uniform
	);
	void handleKeyboardInput(
		GLFWwindow* window
	);
};
#endif