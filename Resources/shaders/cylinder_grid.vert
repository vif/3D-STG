#version 330 core

uniform mat4 ViewMatrix;
uniform mat4 ViewProjectionMatrix;

in vec4 position;
in vec4 normal;
in vec4 colour;
in mat4 model_matrix;

out vec4 out_normal;
out vec4 out_position;
out vec4 out_colour;

void main()
{
    gl_Position = ViewProjectionMatrix * model_matrix * position;
    out_position = ViewMatrix * model_matrix * position;
    out_normal = normal;
    out_colour = colour;
}