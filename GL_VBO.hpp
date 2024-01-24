#ifndef gl_vbo_hpp
#define gl_vbo_hpp

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

#include "GL_Vertex.hpp"

class GL_VBO {
protected:
	GLuint id;

public:
	GL_VBO(
		std::vector<GL_Vertex>& vertices
	);

	void Bind();
	void Unbind();
	void Delete();
};

#endif
