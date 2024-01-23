#version 330 core

out vec4 FragColor;

// Imports the texture coordinates from the Vertex Shader
in vec2 texCoord;

// Gets the Texture Units from the main function
uniform sampler2D diffuse0;
uniform vec4 lightColor;

void main()
{
	FragColor = texture(diffuse0, texCoord) * lightColor;
}