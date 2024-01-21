#ifndef gl_texture_png_hpp
#define gl_texture_png_hpp

#include <string>
#include <glad/glad.h>
#include <stb/stb_image.h>
#include "GL_Shader.hpp"

class GL_Texture_Png {
protected:
	GLuint id;
	GLuint unit;

public:
	GLenum type;

	GL_Texture_Png(
		std::string image,
		GLenum texType,
		GLuint slot,
		GLenum format,
		GLenum pixelType
	);

	void texUnit(
		GL_Shader& shader, 
		const char* uniform, 
		GLuint unit
	);

	void Bind();
	void Unbind();
	void Delete();
};
#endif