#ifndef moon_hpp
#define moon_hpp

#include "Earth.hpp"

class Moon : public CelestialBody {
protected:
	Earth& parentPlanet;
	float orbitRadius;

	glm::mat4 getTransformation();

public:
	Moon(
		Earth& parentPlanet
	);
};

#endif
