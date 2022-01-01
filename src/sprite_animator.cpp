#include "sprite_animator.h"
#include "sprite_info.h"

sprite_animator::sprite_animator(std::string sprite_sheet_name, vertex_coordinate3 a_sprite_location)
{
    sprite_texture_creator = std::make_unique<texture_creator>(texture_creator());
    sprite_texture_creator->create_texture_from_png(sprite_sheet_name);
    sprite_sheet_info = sprite_texture_creator->get_current_png_info();

    sprite_vertex_manager = std::make_unique<vertex_manager>(vertex_manager());
    sprite_vertex_manager->generate_vertex_array();
    sprite_vertex_manager->bind_vertex_array();

    sprite_buffer_manager = std::make_unique<buffer_manager>(buffer_manager());
    sprite_buffer_manager->generate_vertex_buffer();
    sprite_buffer_manager->bind_vertex_buffer();
    sprite_buffer_manager->generate_index_buffer();
    sprite_buffer_manager->bind_index_buffer();

    animation_info = populate_sprite_info();

    sprite_vector_indices = {0, 1, 3, 1, 2, 3 };
    sprite_buffer_manager->set_index_buffer_data(sprite_vector_indices);

    sprite_location = a_sprite_location;
}


float sprite_animator::floatify_x(unsigned int pixel_x)
{
    return (float)( (float)(pixel_x) / (float)sprite_sheet_info.image_width);
}

float sprite_animator::floatify_y(unsigned int pixel_y)
{
    return (float)( (float)(pixel_y) / (float)sprite_sheet_info.image_height);
}

void sprite_animator::do_animation(
    std::string animation_name,
    unsigned int frames_per_frame)
{
    std::vector<standard_vertex_info> quad;
    sprite_texture_creator->bind_texture();
    if (current_frame >= animation_info[animation_name].size())
    {
        current_frame = 0;
    }
    if (frame_count % frames_per_frame == 0)
    {
        pixel_offsets po = animation_info[animation_name][current_frame].pixel_coord;
        character_dimensions cd = animation_info[animation_name][current_frame].char_dimension;
        float x_offset_kick_array[] = {0.0f, 7.0f, 18.0f, 7.0f, 0.0f};
        if (animation_name == "RYU_STAND_LIGHT_KICK")
        {
            ///////////////
            // TOP RIGHT //
            ///////////////
            current_quad[0].color_vec = {1.0f, 1.0f, 1.0f};
            current_quad[0].vertex_coord = {
                sprite_location.x + (0.009f * ((float)cd.width)), 
                sprite_location.y + (0.009f * ((float)cd.height)), 
                0.0f};
            current_quad[0].texture_coord = {
                floatify_x(po.x + cd.width),
                floatify_y(po.y)};
                //floatify_y(po.y - cd.height)};

            //////////////////
            // BOTTOM RIGHT //
            //////////////////
            current_quad[1].color_vec = {1.0f, 1.0f, 1.0f};
            current_quad[1].vertex_coord = {
                sprite_location.x + (0.009f * ((float)cd.width)   ), 
                sprite_location.y, 
                0.0f};
            current_quad[1].texture_coord = {
                floatify_x(po.x + cd.width),
                floatify_y(po.y + cd.height)};

            /////////////////
            // BOTTOM LEFT //
            /////////////////
            current_quad[2].color_vec = {1.0f, 1.0f, 1.0f};
            current_quad[2].vertex_coord = sprite_location;
            current_quad[2].texture_coord = {
                floatify_x(po.x),
                floatify_y(po.y + cd.height)};

            //////////////
            // TOP LEFT //
            //////////////
            current_quad[3].color_vec = {1.0f, 1.0f, 1.0f};
            current_quad[3].vertex_coord = {
                sprite_location.x, 
                sprite_location.y + (0.009f * ((float)cd.height)), 
                0.0f};
            current_quad[3].texture_coord = {
                floatify_x(po.x),
                floatify_y(po.y)};
        }
        current_frame++;
    }
    quad.push_back(current_quad[0]);
    quad.push_back(current_quad[1]);
    quad.push_back(current_quad[2]);
    quad.push_back(current_quad[3]);
    sprite_buffer_manager->set_initial_vertex_buffer_data(quad);
    sprite_buffer_manager->set_index_buffer_data(sprite_vector_indices);
    sprite_buffer_manager->render_buffer_content();
    sprite_texture_creator->unbind_texture();
    frame_count++;
}
