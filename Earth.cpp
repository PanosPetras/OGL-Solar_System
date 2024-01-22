#include "Earth.hpp"
#include "C.hpp"

Earth::Earth(
	Sun& parentStar
): Planet(
	parentStar, 
	20.0f, 
	R"(C:\Users\ppetr\source\repos\Solar System\Models\earth\Earth.obj)", 
	1.0f
) {
}

glm::mat4 Earth::getTransformation() {
	glm::vec3 earthPos = c(tick, orbitRadius);
	glm::mat4 earthModel = glm::mat4(0.1f);

	earthModel = glm::translate(earthModel, earthPos);
	earthModel = glm::rotate(earthModel, glm::radians(revolutions * tick), glm::vec3(0.0f, 1.0f, 0.0f));

	return earthModel;
}
