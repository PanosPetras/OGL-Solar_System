#ifndef mesh_hpp
#define mesh_hpp

#include <string>

#include "VAO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"
#include "Texture_2D.hpp"

namespace OGL {
	class Mesh {
	protected:
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture_2D> textures;

		VAO VAO;
		VBO* VBO;
		EBO* EBO;

	public:
		Mesh(
			std::vector<Vertex>& vertices,
			std::vector<GLuint>& indices, 
			std::vector<Texture_2D>& textures
		);

		void Draw(
			Shader& shader, 
			Camera& camera,
			glm::mat4& transform
		);

		void Delete();
	};
}

#endif