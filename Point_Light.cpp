#include "Point_Light.hpp"

using namespace OGL;

Point_Light::Point_Light(
	glm::vec3 pos
): pos(pos) {
}

void Point_Light::Activate(
	Shader& shader
) {
	shader.Activate();

	glUniform3f(
		glGetUniformLocation(shader.id, "lightPos"), 
		pos.x, 
		pos.y, 
		pos.z
	);
}
