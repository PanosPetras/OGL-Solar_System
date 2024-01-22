#include "SolarSystem.hpp"

SolarSystem::SolarSystem(): sun(), earth(sun), mars(sun), moon(earth) {
}

SolarSystem::~SolarSystem() {
}

void SolarSystem::Draw(
	GL_Shader& shader, 
	GL_Camera& camera
) {
	earth.Draw(shader, camera);
	sun.Draw(shader, camera);
	moon.Draw(shader, camera);
	mars.Draw(shader, camera);
}

void SolarSystem::Tick() {
	CelestialBody::Tick();
}
