#ifndef gl_point_light
#define gl_point_light

#include <glm/glm.hpp>

#include "GL_Shader.hpp"

class GL_Point_Light {
protected:
	glm::vec3 pos;

public:
	GL_Point_Light(
		glm::vec3 pos
	);

	void Activate(
		GL_Shader& shader
	);
};

#endif
