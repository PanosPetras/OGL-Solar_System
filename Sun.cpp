#include "Sun.hpp"
#include "GetProjectPath.hpp"

glm::mat4 Sun::getTransformation() {
	glm::vec3 sunPos = glm::vec3(-1.0f, -1.0f, -1.0f);
	glm::mat4 sunModel = glm::mat4(1.0f);

	sunModel = glm::rotate(sunModel, glm::radians(revolutions * tick), glm::vec3(0.0f, 1.0f, 0.0f));
	sunModel = glm::translate(sunModel, sunPos);

	return sunModel;
}

Sun::Sun(): 
	Star(
		getModelPath("\\sun\\sun.obj"), 
		0.1f
) { }
