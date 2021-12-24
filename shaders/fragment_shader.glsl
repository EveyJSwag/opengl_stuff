#version 330 core
out vec4 fragmentColor;

in vec3 outVertexColor;
in vec2 outTextureCoord;

uniform vec2 uniformTextureCoord;

uniform sampler2D inTexture;

void main()
{
    vec2 new_texture_coord = uniformTextureCoord + outTextureCoord;
    fragmentColor = texture(inTexture, new_texture_coord);
}
