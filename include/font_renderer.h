#ifndef FONT_RENDERER_H
#define FONT_RENDERER_H

#include "texture_creator.h"
#include "shader_creator.h"
#include "vertex_manager.h"
#include <memory>
class font_renderer
{
public:

    font_renderer();

    void write_font(const char*);

private:
    std::unique_ptr<texture_creator> font_texture;
    std::unique_ptr<vertex_manager>  font_vertex_array;

};

#endif