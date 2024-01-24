#ifndef Texture_2Ds_hpp
#define Texture_2Ds_hpp

#include <string>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.hpp"

namespace OGL {
	class Texture_2D {
	protected:
		GLuint unit;

	public:
		GLuint id;
		std::string type;

		Texture_2D(
			std::string image,
			std::string texType,
			GLuint slot,
			GLenum format,
			GLenum pixelType
		);

		void texUnit(
			Shader& shader,
			const char* uniform,
			GLuint unit
		);

		void Bind();
		void Unbind();
		void Delete();
	};
}

#endif