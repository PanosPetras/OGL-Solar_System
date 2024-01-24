#include "GL_Mesh.hpp"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"

GL_Mesh::GL_Mesh(
	std::vector <GL_Vertex>& vertices, 
	std::vector <GLuint>& indices, 
	std::vector <GL_Texture_2Ds>& textures
) {
	GL_Mesh::vertices = vertices;
	GL_Mesh::indices = indices;
	GL_Mesh::textures = textures;

	VAO.Bind();
	VBO = new GL_VBO(vertices);
	EBO = new GL_EBO(indices);

	VAO.LinkAttrib(*VBO, 0, 3, GL_FLOAT, sizeof(GL_Vertex), (void*)0);
	VAO.LinkAttrib(*VBO, 1, 3, GL_FLOAT, sizeof(GL_Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(*VBO, 2, 2, GL_FLOAT, sizeof(GL_Vertex), (void*)(6 * sizeof(float)));

	VAO.Unbind();
	VBO->Unbind();
	EBO->Unbind();
}

void GL_Mesh::Draw(
	GL_Shader& shader,
	GL_Camera& camera,
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

void GL_Mesh::Delete() {
	for (GL_Texture_2Ds& txt : textures) {
		txt.Delete();
	}
	VAO.Delete();
	VBO->Delete();
	EBO->Delete();

	delete VBO;
	delete EBO;
}
