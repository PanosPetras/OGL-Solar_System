#ifndef point_light
#define point_light

#include <glm/glm.hpp>

#include "Shader.hpp"

namespace OGL {
	class Point_Light {
	protected:
		glm::vec3 pos;

	public:
		Point_Light(
			glm::vec3 pos
		);

		void Activate(
			Shader& shader
		);
	};
}

#endif
