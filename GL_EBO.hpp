#ifndef gl_ebo_hpp
#define gl_ebo_hpp

#include <glad/glad.h>
#include <vector>

class GL_EBO {
protected:
	GLuint id;

public:
	GL_EBO(
		std::vector<GLuint> indices
	);

	void Bind();
	void Unbind();
	void Delete();
};

#endif
