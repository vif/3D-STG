#version 330 core

uniform vec3 normalized_light_direction = normalize(vec3(1.0, 1.0, 1.0));
uniform vec4 light_colour = vec4(1, 1, 1, 1);
uniform vec3 camera_position;
uniform	vec3 diffuse_colour = vec3(1, 1, 1);
uniform vec3 ambient_colour = vec3(0.1, 0.1, 0.1);
uniform vec3 specular_colour = vec3(1, 1, 1);
uniform	float specular_shininess = 1;

in vec4 normalized_out_normal;
in vec4 out_colour;

out vec4 colour;

void main() 
{
    float diffuse_percent = clamp(dot (normalized_light_direction, normalized_out_normal.xyz), 0, 1);
    vec3 reflected_light_direction = reflect(normalized_light_direction, normalized_out_normal.xyz);
    float specular_percent = max(pow(dot (reflected_light_direction, camera_position), specular_shininess), 0);
    colour = out_colour*light_colour*vec4((diffuse_colour*diffuse_percent + specular_colour*specular_percent + ambient_colour),1);
}