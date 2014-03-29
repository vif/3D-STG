#version 330 core

uniform mat4 ModelViewProjectionMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 NormalMatrix;

in vec3 position;
in vec3 normal;
in vec4 colour;

out vec4 frag_position;
out vec4 frag_normal;
out vec4 frag_colour;

void main()
{
	gl_Position = ModelViewProjectionMatrix * vec4(position, 1.0);
	frag_position = ModelViewMatrix * vec4(position, 1.0);
	frag_normal = normalize (NormalMatrix * vec4(normal, 1.0));
	frag_colour = colour;
}