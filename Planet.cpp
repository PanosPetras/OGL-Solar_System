#include "Planet.hpp"

Planet::Planet(
	Star& parentStar, 
	float orbitRadius, 
	std::string model, 
	float revolutions
): CelestialBody(model, revolutions), 
	parentStar(parentStar), 
	orbitRadius(orbitRadius) {
}
