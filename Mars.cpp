#include "Mars.hpp"
#include "C.hpp"

Mars::Mars(
	Sun& parentStar
) : Planet(
	parentStar,
	50.0f,
	R"(C:\Users\ppetr\source\repos\Solar System\Models\planet\planet.obj)",
	1.0f
) {
}

glm::mat4 Mars::getTransformation() {
	glm::vec3 marsPos = c(tick / 10, orbitRadius);
	glm::mat4 marsModel = glm::mat4(0.1f);

	marsModel = glm::translate(marsModel, marsPos);
	marsModel = glm::rotate(marsModel, glm::radians(revolutions * tick), glm::vec3(0.0f, 1.0f, 0.0f));

	return marsModel;
}
