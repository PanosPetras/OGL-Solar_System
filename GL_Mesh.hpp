//#ifndef gl_mesh_hpp
//#define gl_mesh_hpp
//
//#include <string>
//
//#include "GL_VAO.hpp"
//#include "GL_EBO.hpp"
//#include "GL_Camera.hpp"
//#include "GL_Texture_Png.hpp"
//
//class GL_Mesh {
//public:
//	std::vector <GL_Vertex> vertices;
//	std::vector <GLuint> indices;
//	std::vector <GL_Texture_Png> textures;
//	// Store VAO in public so it can be used in the Draw function
//	GL_VAO VAO;
//
//	// Initializes the mesh
//	GL_Mesh(
//		std::vector <GL_Vertex>& vertices, 
//		std::vector <GLuint>& indices, 
//		std::vector <GL_Texture_Png>& textures
//	);
//
//	// Draws the mesh
//	void Draw(
//		GL_Shader& shader, 
//		GL_Camera& camera
//	);
//};
//#endif