#include "GL_VAO.hpp"

GL_VAO::GL_VAO() {
	glGenVertexArrays(1, &id);
}

void GL_VAO::LinkAttrib(
	GL_VBO& vbo,
	GLuint layout,
	GLuint numComponents,
	GLenum type,
	GLsizeiptr stride,
	void* offset
) {
	vbo.Bind();

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);

	vbo.Unbind();
}

void GL_VAO::Bind() {
	glBindVertexArray(id);
}

void GL_VAO::Unbind() {
	glBindVertexArray(0);
}

void GL_VAO::Delete() {
	glDeleteVertexArrays(1, &id);
}
