#ifndef mars_hpp
#define mars_hpp

#include "Planet.hpp"
#include "Sun.hpp"

class Mars : public Planet {
protected:
	glm::mat4 getTransformation();

public:
	Mars(
		Sun& parentStar
	);
};

#endif
