#ifndef solarsystem_hpp
#define solarsystem_hpp

#include "Moon.hpp"
#include "Mars.hpp"
#include "BackgroundStars.hpp"

class SolarSystem {
private:
	Earth earth;
	Sun sun;
	Moon moon;
	Mars mars;

	BackgroundStars bgStars;

public:
	SolarSystem();

	void Draw(
		OGL::Shader& shader3d,
		OGL::Shader& shader2d,
		OGL::Shader& lightshader,
		OGL::Camera& camera
	);

	void Tick();

	void Delete();
};

#endif
