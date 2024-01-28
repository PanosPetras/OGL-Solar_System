#ifndef mesh_3d_hpp
#define mesh_3d_hpp

#include <string>

#include "VAO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"
#include "Texture_2D.hpp"

namespace OGL {
	class Mesh_3D {
	protected:
		std::vector<Vertex_3D> vertices;
		std::vector<GLuint> indices;
		std::vector<Texture_2D> textures;

		VAO VAO;
		VBO* VBO;
		EBO* EBO;

	public:
		Mesh_3D(
			std::vector<Vertex_3D>& vertices,
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