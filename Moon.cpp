#include "Moon.hpp"
#include "C.hpp"
#include "GetProjectPath.hpp"

Moon::Moon(
	Earth& parentPlanet
): parentPlanet(parentPlanet), 
	orbitRadius(5.0f), 
	CelestialBody(getModelPath("\\moon\\Moon.obj"), 1.0f) { }

glm::mat4 Moon::getTransformation() {
	glm::vec3 moonPos = c(tick / 360.0f, orbitRadius);
	glm::vec3 moonScale = glm::vec3(0.35f);
	glm::mat4 moonModel = parentPlanet.getTransformation();

	moonModel = glm::translate(moonModel, moonPos);
	moonModel = glm::scale(moonModel, moonScale);
	moonModel = glm::rotate(moonModel, glm::radians(revolutions * tick), glm::vec3(0.0f, 1.0f, 0.0f));

	return moonModel;
}
