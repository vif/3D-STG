#version 150
#extension GL_ARB_explicit_attrib_location : enable

in vec3 out_position;
in vec3 out_normal;
in vec4 out_colour;
in vec3 out_UV;

layout (location = 0) out vec4 colour;
layout (location = 1) out vec4 bs;

void main() 
{
	colour = vec4(1f, 1f, 1f, 1f);
	bs = vec4(out_position + out_normal + out_UV, 0f) + out_colour;
}