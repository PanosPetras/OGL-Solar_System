#include "Mesh_2D.hpp"

using namespace OGL;

Mesh_2D::Mesh_2D(
	std::vector<Vertex_2D>& vertices, 
	std::vector<GLuint>& indices
) {
	this->vertices = vertices;
	this->indices = indices;

	VAO.Bind();
	VBO = new OGL::VBO(vertices);
	EBO = new OGL::EBO(indices);

	VAO.LinkAttrib(*VBO, 0, 2, GL_FLOAT, sizeof(Vertex_2D), (void*)0);

	VAO.Unbind();
	VBO->Unbind();
	EBO->Unbind();
}

void Mesh_2D::Draw(
	Shader& shader, 
	glm::mat4& transform,
	GLfloat scale
) {
	shader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shader.id, "model"), 1, GL_FALSE, glm::value_ptr(transform));
	glUniform1f(glGetUniformLocation(shader.id, "scale"), scale);

	VAO.Bind();

	glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
}

void Mesh_2D::Delete() {
	VAO.Delete();
	VBO->Delete();
	EBO->Delete();

	delete VBO;
	delete EBO;
}
