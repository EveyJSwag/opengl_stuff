#version 330 core
out vec4 fragmentColor;

in vec3 outVertexColor;

void main()
{
    fragmentColor = vec4(1.0f, 0.5f, 0.2f,1.0f);
}
