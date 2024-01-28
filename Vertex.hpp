#ifndef vertex_hpp
#define vertex_hpp

#include <glm/glm.hpp>

namespace OGL {
	struct Vertex {};

	struct Vertex_3D: Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texUV;
	};

	struct Vertex_2D : Vertex {
		glm::vec2 position;
	};
}

#endif
