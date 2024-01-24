#ifndef GL_Texture_2Ds_hpp
#define GL_Texture_2Ds_hpp

#include <string>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "GL_Shader.hpp"

class GL_Texture_2Ds {
protected:
	GLuint unit;

public:
	GLuint id;
	std::string type;

	GL_Texture_2Ds(
		std::string image,
		std::string texType,
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