#ifndef gl_mesh_hpp
#define gl_mesh_hpp

#include <string>

#include "GL_VAO.hpp"
#include "GL_EBO.hpp"
#include "GL_Camera.hpp"
#include "GL_Texture_2Ds.hpp"

class GL_Mesh {
protected:
	std::vector<GL_Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<GL_Texture_2Ds> textures;

	GL_VAO VAO;
	GL_VBO* VBO;
	GL_EBO* EBO;

public:
	GL_Mesh(
		std::vector<GL_Vertex>& vertices, 
		std::vector<GLuint>& indices, 
		std::vector<GL_Texture_2Ds>& textures
	);

	void Draw(
		GL_Shader& shader, 
		GL_Camera& camera,
		glm::mat4& transform
	);

	void Delete();
};
#endif