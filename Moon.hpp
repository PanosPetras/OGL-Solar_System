#ifndef moon_hpp
#define moon_hpp
#include "Planet.hpp"

class Moon : public CelestialBody {
protected:
	Planet& parentPlanet;

public:
	Moon(
		Planet& parentPlanet,
		float orbitRadius,
		std::string model
	);
};

#endif
