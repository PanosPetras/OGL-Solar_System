#version 330 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D diffuse0;
uniform vec4 lightColor;

void main() {
	FragColor = texture(diffuse0, texCoord) * lightColor;
}