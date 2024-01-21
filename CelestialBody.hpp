#ifndef celestialBody_hpp
#define celestialBody_hpp

#include "Point3D.hpp"
#include <string>

class CelestialBody {
protected:
	float revolutions;
	//Mesh *mesh;

public:
	CelestialBody(
		std::string model,
		float revolutions
	);
	~CelestialBody();

	virtual Point3D getPosition() = 0;
	/*virtual Mesh getModel() = 0; */
};

#endif
