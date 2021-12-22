#version 330 core
layout(location = 0) in vec3 vertexCoord;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 textureCoord;

out vec3 outVertexColor;
out vec2 outTextureCoord;

void main()
{
    gl_Position = vec4(vertexCoord, 1.0);
    outVertexColor = vertexColor;
    outTextureCoord = textureCoord;

}