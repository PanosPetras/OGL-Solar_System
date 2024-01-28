#include "BackgroundStars.hpp"
#include <random>
#include <glm/gtc/matrix_transform.hpp>

using namespace OGL;

void BackgroundStars::CreateMesh() {
	std::vector<Vertex_2D> vertices{
		Vertex_2D{.position = glm::vec2(0.5f,  0.0f) },
		Vertex_2D{.position = glm::vec2(0.0f,  1.0f) },
		Vertex_2D{.position = glm::vec2(-0.5f,  0.0f) },
		Vertex_2D{.position = glm::vec2(0.0f, -1.0f) }
	};

	std::vector<GLuint> indices{
		0, 1, 2,
		0, 2, 3
	};

	mesh = new Mesh_2D(vertices, indices);
}

void BackgroundStars::GenerateRandomCoords(
	int n
) {

	std::mt19937 generator;
	std::uniform_real_distribution<float> sizeDistribution(0.007f, 0.02f);
	std::uniform_real_distribution<float> coordDistribution(-1.0f, 1.0f);

	glm::mat4 transform;
	glm::vec3 pos;

	for (int i = 0; i < n; i++) {
		transform = glm::mat4(0.01f);

		pos = glm::vec3(coordDistribution(generator), coordDistribution(generator), 0.0f);
		transform = glm::translate(transform, pos);

		transforms.push_back(transform);
		scales.push_back(sizeDistribution(generator));
	}
}

BackgroundStars::BackgroundStars(
	int n
) {
	CreateMesh();
	GenerateRandomCoords(n);
}

void BackgroundStars::Draw(
	OGL::Shader& shader
) {
	int stars = (int)transforms.size();
	for (int i = 0; i < stars; i++) {
		mesh->Draw(shader, transforms[i], scales[i]);
	}
}

void BackgroundStars::Delete() {
	mesh->Delete();

	delete mesh;
}
