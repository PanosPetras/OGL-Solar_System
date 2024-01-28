#include "Earth.hpp"
#include "C.hpp"
#include "GetProjectPath.hpp"

Earth::Earth(
	Sun& parentStar
): Planet(
	parentStar, 
	24.0f, 
	getModelPath("\\earth\\Earth.obj"),
	1.0f
) { }

glm::mat4 Earth::getTransformation() {
	glm::vec3 earthPos = c(tick / 360.0f, orbitRadius);
	glm::mat4 earthModel = glm::mat4(0.1f);

	earthModel = glm::translate(earthModel, earthPos);
	earthModel = glm::rotate(earthModel, glm::radians(revolutions * tick), glm::vec3(0.0f, 1.0f, 0.0f));

	return earthModel;
}
