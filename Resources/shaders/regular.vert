#version 150
#extension GL_ARB_explicit_attrib_location : enable

in vec3 position;
in vec3 normal;
in vec4 colour;
in vec3 UV;

uniform mat4 ModelViewMatrix;
uniform mat4 ModelViewProjectionMatrix;

out vec3 out_position;
out vec3 out_normal;
out vec4 out_colour;
out vec3 out_UV;

void main()
{
	gl_Position = ModelViewProjectionMatrix * vec4(position, 1.0);
	out_position = vec3( ModelViewMatrix * vec4(position, 1.0) );
	out_normal = normal;
	out_colour = colour;
	out_UV = UV;
}