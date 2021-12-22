#version 330 core
out vec3 fragmentColor;

in vec3 outVertexColor;
in vec2 outTextureCoord;

uniform sampler2D inTexture;

void main()
{
    fragmentColor = texture(inTexture, outTextureCoord).xyz;
}
