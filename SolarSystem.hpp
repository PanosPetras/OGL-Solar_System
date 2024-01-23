#ifndef solarsystem_hpp
#define solarsystem_hpp

#include "Moon.hpp"
#include "Mars.hpp"

class SolarSystem {
private:
	Earth earth;
	Sun sun;
	Moon moon;
	Mars mars;

public:
	SolarSystem();
	~SolarSystem();

	void Draw(
		GL_Shader& shader,
		GL_Shader& lightshader,
		GL_Camera& camera
	);

	void Tick();

	void Delete();
};

#endif
