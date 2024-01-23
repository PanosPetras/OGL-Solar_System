#include "SolarSystem.hpp"

SolarSystem::SolarSystem(): sun(), earth(sun), mars(sun), moon(earth) {
}

SolarSystem::~SolarSystem() {
}

void SolarSystem::Draw(
	GL_Shader& shader, 
	GL_Shader& lightshader, 
	GL_Camera& camera
) {
	earth.Draw(shader, camera);
	sun.Draw(lightshader, camera);
	moon.Draw(shader, camera);
	mars.Draw(shader, camera);
}

void SolarSystem::Tick() {
	CelestialBody::Tick();
}

void SolarSystem::Delete() {
	earth.Delete();
	sun.Delete();
	moon.Delete();
	mars.Delete();
}
