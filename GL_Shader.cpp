#include "GL_Shader.hpp"
#include "glm/glm.hpp"

std::string GL_Shader::get_file_contents(
	std::string filename
) {
	std::ifstream in(filename.c_str(), std::ios::binary);
	if(in) {
		std::string contents;

		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());

		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();

		return contents;
	}

	throw errno;
}

GL_Shader::GL_Shader(
	std::string vertexFile,
	std::string fragmentFile
) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void GL_Shader::Activate() {
	glUseProgram(id);

	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glUniform4f(glGetUniformLocation(id, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
}

void GL_Shader::Delete() {
	glDeleteProgram(id);
}
