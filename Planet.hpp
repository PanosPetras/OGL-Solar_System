#ifndef planet_hpp
#define planet_hpp

#include "Star.hpp"
#include <string>

class Planet: public CelestialBody {
protected:
	Star &parentStar;
	float orbitRadius;

public:
	Planet(
		Star &parentStar,
		float orbitRadius,
		std::string model,
		float revolutions
	);
};

#endif
