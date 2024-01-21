#include "GL_VBO.hpp"

GL_VBO::GL_VBO(
	GLfloat* vertices, 
	GLsizeiptr size
) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void GL_VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void GL_VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void GL_VBO::Delete() {
	glDeleteBuffers(1, &id);
}
