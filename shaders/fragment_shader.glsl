#version 330 core
out vec3 color;
uniform vec3 color_input;
void main()
{
    color = color_input;
}
