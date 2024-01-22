#ifndef star_hpp
#define star_hpp

#include "CelestialBody.hpp"
#include <string>

class Star: public CelestialBody {
public:
	Star(
		std::string model,
		float revolutions
	);
};

#endif