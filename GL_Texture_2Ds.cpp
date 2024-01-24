#include "GL_Texture_2Ds.hpp"

GL_Texture_2Ds::GL_Texture_2Ds(
	std::string image,
	std::string texType,
	GLuint slot,
	GLenum format,
	GLenum pixelType
) {
	type = texType;

	int widthImg, heightImg, numColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image.c_str(), &widthImg, &heightImg, &numColCh, 0);

	glGenTextures(1, &id);

	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(bytes);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GL_Texture_2Ds::texUnit(
	GL_Shader& shader,
	const char* uniform,
	GLuint unit
) {
	GLuint texUni = glGetUniformLocation(shader.id, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void GL_Texture_2Ds::Bind() {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, id);
}

void GL_Texture_2Ds::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void GL_Texture_2Ds::Delete() {
	glDeleteTextures(1, &id);
}