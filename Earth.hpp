#ifndef earth_hpp
#define earth_hpp

#include "Planet.hpp"
#include "Sun.hpp"

class Earth: public Planet {
protected:
	glm::mat4 getTransformation();

	friend class Moon;

public:
	Earth(
		Sun& parentStar
	);
};

#endif
