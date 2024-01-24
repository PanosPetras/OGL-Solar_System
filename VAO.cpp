#include "VAO.hpp"

using namespace OGL;

VAO::VAO() {
	glGenVertexArrays(1, &id);
}

void VAO::LinkAttrib(
	VBO& vbo,
	GLuint layout,
	GLuint numComponents,
	GLenum type,
	GLsizei stride,
	void* offset
) {
	vbo.Bind();

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	vbo.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(id);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &id);
}
