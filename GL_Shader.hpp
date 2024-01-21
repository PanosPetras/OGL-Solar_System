#ifndef gl_shader_hpp
#define gl_shader_hpp

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

class GL_Shader {
protected:
	std::string get_file_contents(
		const std::string filename
	);

public:
	GLuint id;

	GL_Shader(
		std::string vertexFile, 
		std::string fragmentFile
	);

	void Activate();
	void Delete();
};

#endif
