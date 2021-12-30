#include "font_renderer.h"

font_renderer::font_renderer(
    std::string font_sheet,
    vertex_quad& initial_vertex_quad,
    const pixel_offsets font_offset,
    const pixel_offsets character_dimension,
    const pixel_offsets character_distance,
    const font_char_locations char_locations,
    const float scale_amount)
{
    char_dist = character_distance;
    initial_vertex_data = initial_vertex_quad;
    font_char_offset = font_offset;
    font_locations = char_locations;
    font_char_dimension = character_dimension;

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

    shift_vertex_x_amount = initial_vertex_quad.top_right.x - initial_vertex_quad.top_left.x;
    shift_vertex_y_amount = initial_vertex_quad.top_right.y - initial_vertex_quad.bottom_right.y;

    if (shift_vertex_x_amount < 0.0f) shift_vertex_x_amount*=-1.0f;
    if (shift_vertex_y_amount < 0.0f) shift_vertex_y_amount*=-1.0f;

    std::vector <unsigned int> vec_indicies({0, 1, 3, 1, 2, 3 });
    vertex_indices = vec_indicies;
}

float font_renderer::floatify_x(unsigned int pixel_x)
{
    return (float)( (float)(pixel_x) / (float)font_sheet_info.image_width);
}

float font_renderer::floatify_y(unsigned int pixel_y)
{
    return (float)( (float)(pixel_y) / (float)font_sheet_info.image_height);
}

void font_renderer::write_string(std::string font_string)
{
    for (; string_index < font_string.size(); string_index++)
        add_character(font_string.c_str()[string_index]);

    font_buffer->set_index_buffer_data(vertex_indices);
    font_buffer->set_initial_vertex_buffer_data(vertex_info);
    font_buffer->render_buffer_content();
}

void font_renderer::add_character(const char char_to_add)
{
    float minimum_x_tex_coord = floatify_x(font_char_offset.x + (font_locations[char_to_add].pixel_coord.x));//floatify_x(font_char_offset.x + (font_locations[char_to_add].x * (font_char_dimension.x + char_dist.x)));
    float maximum_x_tex_coord = minimum_x_tex_coord + floatify_x(font_locations[char_to_add].char_dimension.width);//minimum_x_tex_coord + floatify_x(font_char_dimension.x);
    float minimum_y_tex_coord = floatify_y(font_char_offset.y + (font_locations[char_to_add].pixel_coord.y));//floatify_y(font_char_offset.y + (font_locations[char_to_add].y * (font_char_dimension.y + char_dist.y)));
    float maximum_y_tex_coord = minimum_y_tex_coord + floatify_y(font_locations[char_to_add].char_dimension.height);//minimum_y_tex_coord + floatify_y(font_char_dimension.y);
    texture_coordinate2 tl = {minimum_x_tex_coord, minimum_y_tex_coord};
    texture_coordinate2 tr = {maximum_x_tex_coord, minimum_y_tex_coord};
    texture_coordinate2 bl = {minimum_x_tex_coord, maximum_y_tex_coord};
    texture_coordinate2 br = {maximum_x_tex_coord, maximum_y_tex_coord};

    std::vector<texture_coordinate2> new_texure_coordinates;
    new_texure_coordinates.push_back(tr);
    new_texure_coordinates.push_back(br);
    new_texure_coordinates.push_back(bl);
    new_texure_coordinates.push_back(tl);

    int current_vertex_info_size = vertex_info.size();
    color_vector3 color_vec = {1.0f, 1.0f, 1.0f};

    std::vector <vertex_coordinate3> new_vertex_coordinates;
    if (current_vertex_info_size  >= 4)
    {
        for (int index = current_vertex_info_size - 4; index < current_vertex_info_size; index++)
        {
            vertex_coordinate3 new_vertex_coord = 
                { vertex_info[index].vertex_coord.x + shift_vertex_x_amount,
                  vertex_info[index].vertex_coord.y,
                  vertex_info[index].vertex_coord.z };

            new_vertex_coordinates.push_back(new_vertex_coord);
        }

        int vertex_size = vertex_indices.size();
        for (int index = vertex_size - 6; index < vertex_size; index++)
        {
            vertex_indices.push_back(vertex_indices[index] + 4);
        }
    }
    else
    {
        new_vertex_coordinates.push_back(initial_vertex_data.top_right);
        new_vertex_coordinates.push_back(initial_vertex_data.bottom_right);
        new_vertex_coordinates.push_back(initial_vertex_data.bottom_left);
        new_vertex_coordinates.push_back(initial_vertex_data.top_left);
    }

    for (int index = 0; index < 4; index++)
    {
        standard_vertex_info new_entry;
        new_entry.color_vec = color_vec;
        new_entry.texture_coord = new_texure_coordinates[index];
        new_entry.vertex_coord = new_vertex_coordinates[index];
        vertex_info.push_back(new_entry);
    }
}

void font_renderer::add_vertex()
{
}

void font_renderer::move_quad()
{

}
