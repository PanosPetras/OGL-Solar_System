#include "MainWindow.hpp"

#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "GL_Model.hpp"
#include "SolarSystem.hpp"

void MainWindow::handleKeyboardInput(
    GLFWwindow* window,
    int key,
    int scancode,
    int action,
    int mods
) {
    switch (key) {
    case GLFW_KEY_SPACE:
        
    default:
        break;
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
}

void MainWindow::draw() {
	GL_Vertex lightVertices[] =
	{ //     COORDINATES     //
		GL_Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
		GL_Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
		GL_Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
		GL_Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
		GL_Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
		GL_Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
		GL_Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
		GL_Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
	};

	GLuint lightIndices[] =
	{
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2,
		2, 6, 5,
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6,
		4, 6, 7
	}; 
	
	GL_Texture_Png textures[]
	{
		GL_Texture_Png("planks.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		GL_Texture_Png("planksSpec.png", "specular", 1, GL_RED, GL_UNSIGNED_BYTE)
	};

	GL_Shader shader(
		"default.vert", 
		"default.frag"
	);

	GL_Shader lightShader(
		"light.vert", 
		"light.frag"
	);
	// Store mesh data in vectors for the mesh
	std::vector <GL_Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(GL_Vertex));
	std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	std::vector <GL_Texture_Png> tex(textures, textures + sizeof(textures) / sizeof(GL_Texture_Png));
	// Create light mesh
	GL_Mesh light(lightVerts, lightInd, tex);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	SolarSystem ss;

	glm::vec3 sunPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 sunModel = glm::mat4(1.0f);
	sunModel = glm::translate(sunModel, sunPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.id, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	shader.Activate();
	glUniform4f(glGetUniformLocation(shader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shader.id, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	glEnable(GL_DEPTH_TEST);

	GL_Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	double then = glfwGetTime(), now;

	// Main while loop
	while (!window.shouldClose()) {
		// Specify the color of the background
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window.window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		ss.Draw(shader, camera);
		light.Draw(lightShader, camera, lightModel);

		// Swap the back buffer with the front buffer
		window.swapBuffers();

		// Take care of all GLFW events
		glfwPollEvents();

		now = glfwGetTime();
		if (now - then >= 2.0 / 60) {
			ss.Tick();

			then = now;
		}
	}

	// Delete all the objects we've created
	shader.Delete();
	lightShader.Delete();
}

void MainWindow::mainLoop() {
    /* Loop until the user closes the window */
    /* Render here */
    draw();
}
