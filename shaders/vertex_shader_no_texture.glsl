#version 330 core
layout(location = 0) in vec3 vertexCoord;
layout(location = 1) in vec3 vertexColor;
out vec3 outVertexColor;
void main()
{
    //textureCoord = vec2(0.0, 0.0);
    gl_Position = vec4(vertexCoord, 1.0);
    //gl_Position = MVP * vec4(vertexCoord, 1.0);
    outVertexColor = vec3(1.0f, 1.0f, 0.0f);
    //outTextureCoord = textureCoord;
}