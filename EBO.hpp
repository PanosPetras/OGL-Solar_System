#ifndef ebo_hpp
#define ebo_hpp

#include <glad/glad.h>
#include <vector>

namespace OGL {
	class EBO {
	protected:
		GLuint id;

	public:
		EBO(
			std::vector<GLuint> indices
		);

		void Bind();
		void Unbind();
		void Delete();
	};
}

#endif
