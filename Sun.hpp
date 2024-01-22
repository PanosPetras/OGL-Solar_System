#ifndef sun_hpp
#define sun_hpp

#include "Star.hpp"

class Sun: public Star {
protected:
	glm::mat4 getTransformation();

public:
	Sun();
};

#endif
