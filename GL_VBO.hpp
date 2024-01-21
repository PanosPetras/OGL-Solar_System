#ifndef gl_vbo_hpp
#define gl_vbo_hpp

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

struct GL_Vertex {
	glm::uvec3 position;
	glm::uvec3 normal;
	glm::uvec3 color;
	glm::uvec2 texUV;
};

class GL_VBO {
protected:
	GLuint id;

public:
	GL_VBO(
		GLfloat* vertices, 
		GLsizeiptr size
	);

	void Bind();
	void Unbind();
	void Delete();
};

#endif
