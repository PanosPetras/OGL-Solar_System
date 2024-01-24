#include "Mesh.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>

using namespace OGL;

Mesh::Mesh(
	std::vector <Vertex>& vertices, 
	std::vector <GLuint>& indices, 
	std::vector <Texture_2D>& textures
) {
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	VAO.Bind();
	VBO = new OGL::VBO(vertices);
	EBO = new OGL::EBO(indices);

	VAO.LinkAttrib(*VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(*VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(*VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	VAO.Unbind();
	VBO->Unbind();
	EBO->Unbind();
}

void Mesh::Draw(
	Shader& shader,
	Camera& camera,
	glm::mat4& transform
) {
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.id, "model"), 1, GL_FALSE, glm::value_ptr(transform));

	VAO.Bind();

	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;

	for (unsigned int i = 0; i < textures.size(); i++) {
		std::string num;
		std::string type = textures[i].type;

		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		} else if (type == "specular") {
			num = std::to_string(numSpecular++);
		}
		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}

	glUniform3f(glGetUniformLocation(shader.id, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh::Delete() {
	for (Texture_2D& txt : textures) {
		txt.Delete();
	}
	VAO.Delete();
	VBO->Delete();
	EBO->Delete();

	delete VBO;
	delete EBO;
}
