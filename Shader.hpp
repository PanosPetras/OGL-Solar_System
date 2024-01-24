#ifndef shader_hpp
#define shader_hpp

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

namespace OGL {
	class Shader {
	protected:
		std::string get_file_contents(
			const std::string filename
		);

	public:
		GLuint id;

		Shader(
			std::string vertexFile,
			std::string fragmentFile
		);

		void Activate();
		void Delete();
	};
}

#endif
