#include "CelestialBody.hpp"

CelestialBody::CelestialBody(
	std::string model, 
	float revolutions
): model(model), 
	revolutions(revolutions) {
}

CelestialBody::~CelestialBody() {
}

void CelestialBody::Draw(
	GL_Shader& shader, 
	GL_Camera& camera
) {
	auto transformation = getTransformation();

	model.Draw(
		shader, 
		camera, 
		transformation
	);
}

void CelestialBody::Tick() {
	tick++;
	//tick %= (360 * 4);
}
