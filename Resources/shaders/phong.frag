#version 330 core

uniform vec4 ViewLightDirection;
uniform mat4 NormalMatrix;

uniform vec3 light_colour = vec3(1, 1, 1);
uniform vec3 camera_position;
uniform	vec3 diffuse_colour = vec3(1, 1, 1);
uniform vec3 ambient_colour = vec3(0.1, 0.1, 0.1);
uniform vec3 specular_colour = vec3(1, 1, 1);
uniform	float specular_shininess = 1;

in vec4 out_position;
in vec4 out_normal;
in vec4 out_colour;

out vec4 colour;

void main() 
{
	vec3 normalized_transformed_normal = normalize((NormalMatrix * out_normal).xyz);

	//ambient
	vec4 ambient_component = vec4(ambient_colour, 1);

	//diffuse
	float diffuse_percent = dot (ViewLightDirection.xyz, normalized_transformed_normal);
	vec4 diffuse_component = vec4(diffuse_colour * light_colour * clamp( diffuse_percent, 0, 1), 1);

	//specular
	vec3 reflected_light_direction = normalize(reflect(ViewLightDirection.xyz, normalized_transformed_normal));
	float angle = clamp( dot(reflected_light_direction, normalize(-out_position.xyz)), 0, 1);
	float specular_percentage = pow(angle, specular_shininess);
	vec4 specular_component = vec4(specular_colour * specular_percentage, 1);

    colour = out_colour*(ambient_component + diffuse_component + specular_component);
}