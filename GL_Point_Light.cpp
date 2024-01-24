#include "GL_Point_Light.hpp"

GL_Point_Light::GL_Point_Light(
	glm::vec3 pos
): pos(pos) {
}

void GL_Point_Light::Activate(
	GL_Shader& shader
) {
	shader.Activate();

	glUniform3f(
		glGetUniformLocation(shader.id, "lightPos"), 
		pos.x, 
		pos.y, 
		pos.z
	);
}
