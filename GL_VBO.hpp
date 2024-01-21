#ifndef gl_vbo_hpp
#define gl_vbo_hpp

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

struct GL_Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

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
