#ifndef vao_hpp
#define vao_hpp

#include <glad/glad.h>

#include "VBO.hpp"

namespace OGL {
	class VAO {
	protected:
		GLuint id;

	public:
		VAO();

		void LinkAttrib(
			VBO& vbo,
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
}

#endif
