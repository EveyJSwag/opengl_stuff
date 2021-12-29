#include "font_renderer.h"

font_renderer::font_renderer(
    std::string font_sheet, 
    //const vertex_coordinate3& initial_screen_pos,
    vertex_quad& initial_vertex_quad,
    const pixel_offsets font_offset,
    const pixel_offsets character_dimension,
    const float scale_amount)
{

    font_vertex = std::make_unique<vertex_manager>(vertex_manager());
    font_vertex->generate_vertex_array();
    font_vertex->bind_vertex_array();

    font_buffer = std::make_unique<buffer_manager>(buffer_manager());
    font_buffer->generate_vertex_buffer();
    font_buffer->bind_vertex_buffer();
    font_buffer->generate_index_buffer();
    font_buffer->bind_index_buffer();




    font_texture = std::make_unique<texture_creator>(texture_creator());
    font_texture->create_texture_from_png(font_sheet);
    font_sheet_info = font_texture->get_current_png_info();


    texture_coordinate2 tex_top_left =     { floatify_x(font_offset.x), floatify_y(font_offset.y)};
    texture_coordinate2 tex_top_right =    { floatify_x(font_offset.x + character_dimension.x), floatify_y(font_offset.y)};
    texture_coordinate2 tex_bottom_left =  { floatify_x(font_offset.x), floatify_y(font_offset.y + character_dimension.y)};
    texture_coordinate2 tex_bottom_right = { floatify_x(font_offset.x + character_dimension.x), floatify_y(font_offset.y + character_dimension.y)};

    standard_vertex_info top_right;
    top_right.color_vec = {1.0f, 0.0f, 0.0f};
    top_right.texture_coord = tex_top_right;
    top_right.vertex_coord = initial_vertex_quad.top_right;
    vertex_info.push_back(top_right);

    standard_vertex_info bottom_right;
    bottom_right.color_vec = {0.0f, 0.0f, 1.0f};
    bottom_right.texture_coord = tex_bottom_right;
    bottom_right.vertex_coord = initial_vertex_quad.bottom_right;
    vertex_info.push_back(bottom_right);

    standard_vertex_info bottom_left;
    bottom_left.color_vec = {1.0f, 1.0f, 0.0f};
    bottom_left.texture_coord = tex_bottom_left;
    bottom_left.vertex_coord = initial_vertex_quad.bottom_left;
    vertex_info.push_back(bottom_left);

    standard_vertex_info top_left;
    top_left.color_vec = {1.0f, 1.0f, 0.0f};
    top_left.texture_coord = tex_top_left;
    top_left.vertex_coord = initial_vertex_quad.top_left;
    vertex_info.push_back(top_left);







    shift_vertex_x_amount = initial_vertex_quad.top_right.x - initial_vertex_quad.top_left.x;
    shift_vertex_y_amount = initial_vertex_quad.top_right.y - initial_vertex_quad.bottom_right.y;
    if (shift_vertex_x_amount < 0.0f) shift_vertex_x_amount*=-1.0f;
    if (shift_vertex_y_amount < 0.0f) shift_vertex_y_amount*=-1.0f;

    std::vector <unsigned int> vec_indicies({0, 1, 3, 1, 2, 3 });//4, 5, 7, 5, 6, 7});
    font_buffer->set_index_buffer_data(vec_indicies);
    font_buffer->set_initial_vertex_buffer_data(vertex_info);
}

float font_renderer::floatify_x(unsigned int pixel_x)
{
    return (float)( (float)(pixel_x) / (float)font_sheet_info.image_width);
}

float font_renderer::floatify_y(unsigned int pixel_y)
{
    return (float)( (float)(pixel_y) / (float)font_sheet_info.image_height);
}


void font_renderer::write_string(const char* font_string)
{
    font_buffer->render_buffer_content();
}
