#version 330 core

uniform mat4 ModelViewProjectionMatrix;
uniform mat4 NormalMatrix;

in vec3 position;
in vec3 normal;
in vec3 colour;

out vec4 normalized_frag_normal;
out vec4 frag_colour;

void main()
{
	gl_Position = ModelViewProjectionMatrix * vec4(position, 1.0);
	normalized_frag_normal = normalize (NormalMatrix * vec4(normal, 1.0));
	frag_colour = vec4(colour, 1.0);
}