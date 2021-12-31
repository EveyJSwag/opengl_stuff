#include "fps_counter.h"

fps_counter* fps_counter::fps_counter_instance = nullptr;

fps_counter::fps_counter()
{
    vertex_quad init_vertex_quad;
    init_vertex_quad.bottom_left  = {0.4f, -1.0f, 0.0f};
    init_vertex_quad.bottom_right = {0.5f, -1.0f, 0.0f};
    init_vertex_quad.top_left     = {0.4f, -0.75f, 0.0f};
    init_vertex_quad.top_right    = {0.5f, -0.75f, 0.0f};

    pixel_offsets font_off;
    font_off.x = 3;
    font_off.y = 4;

    pixel_offsets char_dimension;
    char_dimension.x = 10;
    char_dimension.y = 14;

    pixel_offsets char_dist;
    char_dist.x = 2;
    char_dist.y = 5;

    fps_font = std::make_unique<font_renderer>(
        font_renderer(
            "font.png", 
            init_vertex_quad, 
            font_off, 
            char_dimension, 
            char_dist, 
            populate_font_info()));

    current_time = 0.0f;
    amount_of_frames_in_second = 0;
    fps_string_stream << amount_of_frames_in_second << " fps";
    first_loop = false;
}

fps_counter* fps_counter::get_instance()
{
    if (fps_counter_instance == NULL)
        fps_counter_instance = new fps_counter();
    return fps_counter_instance;
}

void fps_counter::display_fps()
{
    if (!first_loop)
    {
        first_loop = true;
        current_time = glfwGetTime();
    }
    fps_font->write_string(fps_string_stream.str());
    amount_of_frames_in_second++;
    if (glfwGetTime() - current_time >= 1.0f)
    {
        current_time = glfwGetTime();
        fps_string_stream.str(std::string());
        fps_string_stream << amount_of_frames_in_second << " fps"; 
        amount_of_frames_in_second = 0;
        fps_font->clear();
    }
}
