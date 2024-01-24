#ifndef celestial_body_hpp
#define celestial_body_hpp

#include "GL_Model.hpp"
#include <string>

class CelestialBody {
protected:
	float revolutions;
	GL_Model model;

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
		GL_Shader& shader,
		GL_Camera& camera
	);

	static void Tick();

	void Delete();
};

#endif
