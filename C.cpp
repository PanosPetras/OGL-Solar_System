#include "C.hpp"

glm::vec3 c(
	float t,
	float r
) {
	float x = (float)cos(t) * r, y = (float)sin(t) * r;

	return glm::vec3(x, 0.0f, y);
}