#ifndef TEXT_DISPLAYER_H
#define TEXT_DISPLAYER_H

#include "font_renderer.h"

class text_displayer
{
public:
    text_displayer(vertex_coordinate3& position);
    void write(const char* text);
private:
    vertex_coordinate3 top_left;
    std::unique_ptr<font_renderer> text_displayer_font;
};

#endif