#ifndef vertex_hpp
#define vertex_hpp

#include <glm/glm.hpp>

namespace OGL {
	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texUV;
	};
}

#endif
