#ifndef background_stars_hpp
#define background_stars_hpp

#include <glm/glm.hpp>
#include <vector>

#include "Shader.hpp"
#include "Mesh_2D.hpp"

class BackgroundStars {
protected:
	std::vector<glm::mat4> transforms;
	std::vector<float> scales;

	OGL::Mesh_2D* mesh;

	void CreateMesh();
	void GenerateRandomCoords(int n);

public:
	BackgroundStars(int n);

	void Draw(
		OGL::Shader& shader
	);

	void Delete();
};

#endif
