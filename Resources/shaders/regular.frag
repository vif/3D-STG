#version 330 core

uniform vec4 lightPosition = vec4(1.0, 1.0, 1.0, 0.0);
uniform vec3 lightColour = vec3(1.0, 1.0, 1.0);


uniform	vec4 materialDiffuse;
uniform	vec4 materialSpecular;
uniform	float materialShininess = 0.5;

in vec4 frag_position;
in vec4 frag_normal;
in vec4 frag_colour;

layout(location = 0) out vec4 colour;
layout(location = 1) out vec4 bs;

void main() 
{
	float intensity = clamp( dot( normalize(lightPosition.xyz), frag_normal.xyz ), 0, 1);

	colour = frag_colour * materialDiffuse * vec4(lightColour, 1.0) * intensity;
	bs = materialSpecular + frag_position * frag_colour * materialShininess;
}