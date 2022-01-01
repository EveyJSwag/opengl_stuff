#include "text_displayer.h"
#include "font_info.h"

text_displayer::text_displayer(vertex_coordinate3& position)
{
    top_left = position;

    vertex_quad init_vertex_quad;
    const float Y_SHIFT = -0.2f;
    const float X_SHIFT =  0.1f;
    init_vertex_quad.bottom_left  = {top_left.x, top_left.y + Y_SHIFT, 0.0f};
    init_vertex_quad.bottom_right = {top_left.x + X_SHIFT, top_left.y + Y_SHIFT, 0.0f};
    init_vertex_quad.top_left     = {top_left.x, top_left.y, 0.0f};
    init_vertex_quad.top_right    = {top_left.x + X_SHIFT, top_left.y, 0.0f};

    pixel_offsets font_off;
    font_off.x = 3;
    font_off.y = 4;

    pixel_offsets char_dimension;
    char_dimension.x = 10;
    char_dimension.y = 14;

    pixel_offsets char_dist;
    char_dist.x = 2;
    char_dist.y = 5;

    text_displayer_font = std::make_unique<font_renderer>(
        font_renderer(
            "font.png", 
            init_vertex_quad, 
            font_off, 
            char_dimension, 
            char_dist, 
            populate_font_info()));
}

void text_displayer::write(const char* text)
{
    text_displayer_font->write_string(std::string(text));
}
