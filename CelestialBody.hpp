#ifndef celestial_body_hpp
#define celestial_body_hpp

#include "Model.hpp"
#include <string>

class CelestialBody {
protected:
	float revolutions;
	OGL::Model model;

	virtual glm::mat4 getTransformation() = 0;

	glm::mat4 transformation;
	long long lastTick;

	inline static long long tick = 0;

public:
	CelestialBody(
		std::string model,
		float revolutions
	);
	~CelestialBody();

	void Draw(
		OGL::Shader& shader,
		OGL::Camera& camera
	);

	static void Tick();

	void Delete();
};

#endif
