#include "GL_EBO.hpp"

GL_EBO::GL_EBO(
	std::vector<GLuint> indices
) {
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void GL_EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void GL_EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void GL_EBO::Delete() {
	glDeleteBuffers(1, &id);
}
