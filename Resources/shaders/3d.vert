#version 330 core

uniform mat4 ModelViewMatrix;
uniform mat4 ModelViewProjectionMatrix;

in vec4 position;
in vec4 normal;
in vec4 colour;

out vec4 out_normal;
out vec4 out_position;
out vec4 out_colour;

void main()
{
    gl_Position = ModelViewProjectionMatrix * position;
    out_position = ModelViewMatrix * position;
    out_normal = normal;
    out_colour = colour;
}