#include "SolarSystem.hpp"

SolarSystem::SolarSystem(): 
	sun(), 
	earth(sun), 
	mars(sun), 
	moon(earth), 
	bgStars(100) { }

void SolarSystem::Draw(
	OGL::Shader& shader3d, 
	OGL::Shader& shader2d, 
	OGL::Shader& lightshader, 
	OGL::Camera& camera
) {
	bgStars.Draw(shader2d);
	sun.Draw(lightshader, camera);
	earth.Draw(shader3d, camera);
	moon.Draw(shader3d, camera);
	mars.Draw(shader3d, camera);
}

void SolarSystem::Tick() {
	CelestialBody::Tick();
}

void SolarSystem::Delete() {
	bgStars.Delete();
	sun.Delete();
	earth.Delete();
	moon.Delete();
	mars.Delete();
}
