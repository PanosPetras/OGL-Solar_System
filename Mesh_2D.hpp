#ifndef mesh_2d_hpp
#define mesh_2d_hpp

#include <string>

#include "VAO.hpp"
#include "EBO.hpp"
#include "Camera.hpp"
#include "Texture_2D.hpp"

namespace OGL {
	class Mesh_2D {
	protected:
		std::vector<Vertex_2D> vertices;
		std::vector<GLuint> indices;

		VAO VAO;
		VBO* VBO;
		EBO* EBO;

	public:
		Mesh_2D(
			std::vector<Vertex_2D>& vertices,
			std::vector<GLuint>& indices
		);

		void Draw(
			Shader& shader,
			glm::mat4& transform,
			GLfloat scale
		);

		void Delete();
	};
}

#endif