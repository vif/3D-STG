#version 330 core

uniform vec3 normalized_light_direction = normalize(vec3(1.0, 1.0, 1.0));
uniform vec3 light_colour = vec3(1, 1, 1);
uniform vec3 camera_position;
uniform	vec3 diffuse_colour = vec3(1, 1, 1);
uniform vec3 ambient_colour = vec3(0.1, 0.1, 0.1);
uniform vec3 specular_colour = vec3(1, 1, 1);
uniform	float specular_shininess = 1;

in vec4 out_position;
in vec4 normalized_out_normal;
in vec4 out_colour;

out vec4 colour;

vec4 diffuseComponent()
{
	float diffuse_percent = dot (normalized_light_direction, normalized_out_normal.xyz);
	return vec4(diffuse_colour * light_colour * clamp( diffuse_percent, 0, 1), 1);
}

vec4 ambientComponent()
{
	return vec4(ambient_colour, 1);
}

vec4 specularComponent()
{
    vec3 reflected_light_direction = reflect(normalized_light_direction, normalized_out_normal.xyz);
	vec3 normalized_dir_camera = normalize(camera_position - out_position.xyz);
	float angle = clamp( dot(reflected_light_direction, normalized_dir_camera), 0, 1);
	float specular_percentage = pow(angle, specular_shininess);
	return vec4(specular_colour * specular_percentage, 1);
}

void main() 
{
    colour = out_colour*(diffuseComponent() + ambientComponent() + specularComponent());
}