#ifndef vbo_hpp
#define vbo_hpp

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

#include "Vertex.hpp"

namespace OGL {
	class VBO {
	protected:
		GLuint id;

	public:
		VBO(
			std::vector<Vertex_3D>& vertices
		);

		VBO(
			std::vector<Vertex_2D>& vertices
		);

		void Bind();
		void Unbind();
		void Delete();
	};
}

#endif
