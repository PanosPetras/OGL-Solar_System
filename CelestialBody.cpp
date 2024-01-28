#include "CelestialBody.hpp"
#include "glm/glm.hpp"

CelestialBody::CelestialBody(
	std::string model, 
	float revolutions
): model(model), 
	revolutions(revolutions) {
	lastTick = -1;
}

CelestialBody::~CelestialBody() { }

void CelestialBody::Draw(
	OGL::Shader& shader,
	OGL::Camera& camera
) {
	if (lastTick != tick) {
		transformation = getTransformation();
		lastTick = tick;
	}

	model.Draw(
		shader, 
		camera, 
		transformation
	);
}

void CelestialBody::Tick() {
	tick++;
}

void CelestialBody::Delete() {
	model.Delete();
}
