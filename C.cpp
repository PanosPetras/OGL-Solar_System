#include "C.hpp"

glm::vec3 c(
	int t,
	float r
) {
	float x = (float)cos(t / 360.0) * r, y = (float)sin(t / 360.0) * r;

	return glm::vec3(x, 0.0f, y);
}