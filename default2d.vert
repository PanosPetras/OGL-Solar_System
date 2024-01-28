#version 330 core

layout (location = 0) in vec2 aPos;

uniform mat4 model;
uniform float scale;

void main() {	
	gl_Position = vec4(model * vec4(aPos * scale, 1.0f, 1.0f));
}