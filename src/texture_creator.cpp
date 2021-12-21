#include "texture_creator.h"

texture_creator::texture_creator()
{
    glGenTextures(1, &texture_id);

    glBindTexture(GL_TEXTURE_2D, texture_id);

}