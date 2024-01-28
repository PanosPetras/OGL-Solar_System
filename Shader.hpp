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

		Shader(
			std::string vertexFile,
			std::string fragmentFile
		);

	public:
		GLuint id;

		void Activate();
		void Delete();
	};

	namespace Shaders {
		class Default_3D: public Shader {
		public:
			Default_3D();
		};

		class Light: public Shader {
		public:
			Light();
		};
	}
}

#endif
