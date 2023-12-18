#version 330 core
layout(location = 0) in vec3 vertexCoord;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 textureCoord;
out vec3 outVertexColor;
out vec2 outTextureCoord;
uniform mat4 MVP;
void main()
{
    //textureCoord = vec2(0.0, 0.0);
    gl_Position =vec4(vertexCoord, 1.0);
    gl_Position = MVP * vec4(vertexCoord, 1.0);
    outVertexColor = vec3(1.0f, 1.0f, 0.0f);
    outTextureCoord = textureCoord;
}