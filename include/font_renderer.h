#ifndef FONT_RENDERER_H
#define FONT_RENDERER_H

#include <memory>
#include <map>

#include "texture_creator.h"
#include "shader_creator.h"
#include "vertex_manager.h"
#include "vector_types.h"
#include "buffer_manager.h"

class font_renderer
{
public:

    font_renderer(
        std::string font_sheet, 
        vertex_quad& initial_vertex_quad,
        const pixel_offsets font_offset,
        const pixel_offsets character_dimension,
        const pixel_offsets character_distance,
        const font_char_locations char_locations,
        const float scale_amount = 1.0f);

    void write_string(const std::string font_string);
    void write_string(
        const std::string font_string, 
        double delay_between_chars);

    void clear();

private:
    std::unique_ptr<texture_creator> font_texture;
    std::unique_ptr<vertex_manager>  font_vertex;
    std::unique_ptr<buffer_manager>  font_buffer;

    double last_char_time;

    vertex_quad initial_vertex_data;

    int string_index = 0;

    png_loader::png_info_t font_sheet_info;

    std::vector<standard_vertex_info> vertex_info;
    std::vector<unsigned int> vertex_indices;

    void add_character(const char char_to_add);
    void add_vertex();
    void move_quad();

    float shift_vertex_x_amount;
    float shift_vertex_y_amount;

    float floatify_x(unsigned int pixel_x);
    float floatify_y(unsigned int pixel_y);

    font_char_locations font_locations;
    pixel_offsets font_char_offset;
    pixel_offsets font_char_dimension;
    pixel_offsets char_dist;

};

#endif