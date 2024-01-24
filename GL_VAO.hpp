#ifndef gl_vao_hpp
#define gl_vao_hpp

#include <glad/glad.h>

#include "GL_VBO.hpp"

class GL_VAO {
protected:
	GLuint id;

public:
	GL_VAO();

	void LinkAttrib(
		GL_VBO& vbo,
		GLuint layout,
		GLuint numComponents, 
		GLenum type,
		GLsizei stride,
		void* offset
	);

	void Bind();
	void Unbind();
	void Delete();
};

#endif
