#include "MainWindow.hpp"

#include "stb/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "GL_Mesh.hpp"

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
    //window.setKeyCallback();
}

void MainWindow::draw() {
	// Vertices coordinates
	GL_Vertex vertices[] =
	{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
		GL_Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
		GL_Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		GL_Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		GL_Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

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
	// Store mesh data in vectors for the mesh
	std::vector <GL_Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(GL_Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <GL_Texture_Png> tex(textures, textures + sizeof(textures) / sizeof(GL_Texture_Png));
	// Create floor mesh
	GL_Mesh floor(verts, ind, tex);

	GL_Shader lightShader(
		"light.vert", 
		"light.frag"
	);
	// Store mesh data in vectors for the mesh
	std::vector <GL_Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(GL_Vertex));
	std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
	// Create light mesh
	GL_Mesh light(lightVerts, lightInd, tex);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 objectModel = glm::mat4(1.0f);
	objectModel = glm::translate(objectModel, objectPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.id, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.id, "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
	glUniform4f(glGetUniformLocation(shader.id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shader.id, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	glEnable(GL_DEPTH_TEST);

	GL_Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!window.shouldClose()) {
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(window.window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		floor.Draw(shader, camera);
		light.Draw(lightShader, camera);

		// Swap the back buffer with the front buffer
		window.swapBuffers();

		// Take care of all GLFW events
		glfwPollEvents();
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
