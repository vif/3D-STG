#version 330 core

uniform vec3 normalized_light_direction = normalize(vec3(1.0, 1.0, 1.0));
uniform vec3 light_colour = vec3(1.2, 1.2, 1.2);

uniform vec3 camera_position;
uniform	vec3 diffuse_colour;
uniform vec3 ambient_colour;
uniform vec3 specular_colour;
uniform	float specular_shininess;

in vec4 normalized_frag_normal;
in vec4 frag_colour;

out vec4 colour;

void main() 
{
	float diffuse_percent = clamp(dot (normalized_light_direction, normalized_frag_normal.xyz), 0, 1);

	vec3 reflected_light_direction = reflect(normalized_light_direction, normalized_frag_normal.xyz);
	float specular_percent = max(pow(dot (reflected_light_direction, camera_position), specular_shininess), 0);

	colour = vec4(frag_colour.rgb*light_colour*(diffuse_colour*diffuse_percent + specular_colour*specular_percent + ambient_colour), 1.0);
}