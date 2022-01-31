#include "sprite_animator.h"
#include "sprite_info.h"

void sprite_animator::set_flip_anim(bool fa)
{
    flip_anim = fa;
}

sprite_animator::sprite_animator(
    std::string sprite_sheet_name, 
    vertex_coordinate3 a_sprite_location,
    animation_name_location_map a_animation_info)
{
    base_width = 0.0f;
    prev_anim_name = std::string();
    curr_anim_name = std::string();

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

    animation_info = a_animation_info;

    sprite_vector_indices = {0, 1, 3, 1, 2, 3 };
    sprite_buffer_manager->set_index_buffer_data(sprite_vector_indices);

    sprite_location = a_sprite_location;
    flip_anim = false;
}

sprite_animator::sprite_animator(
    std::string sprite_sheet_name, 
    vertex_coordinate3 a_sprite_location,
    animation_name_location_map a_animation_info,
    float& a_base_width)
{

    prev_anim_name = std::string();
    curr_anim_name = std::string();

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

    animation_info = a_animation_info;

    base_width = a_base_width * 0.009f;

    sprite_vector_indices = {0, 1, 3, 1, 2, 3 };
    sprite_buffer_manager->set_index_buffer_data(sprite_vector_indices);

    sprite_location = a_sprite_location;
    flip_anim = false;
}

sprite_animator::sprite_animator(
    std::string sprite_sheet_name, 
    vertex_coordinate3 a_sprite_location,
    animation_name_location_map a_animation_info,
    texture_creator& texture)
{
    base_width = 0.0f;
    prev_anim_name = std::string();
    curr_anim_name = std::string();

    sprite_texture_creator = std::make_unique<texture_creator>(texture);
    sprite_sheet_info = sprite_texture_creator->get_current_png_info();

    sprite_vertex_manager = std::make_unique<vertex_manager>(vertex_manager());
    sprite_vertex_manager->generate_vertex_array();
    sprite_vertex_manager->bind_vertex_array();

    sprite_buffer_manager = std::make_unique<buffer_manager>(buffer_manager());
    sprite_buffer_manager->generate_vertex_buffer();
    sprite_buffer_manager->bind_vertex_buffer();
    sprite_buffer_manager->generate_index_buffer();
    sprite_buffer_manager->bind_index_buffer();

    animation_info = a_animation_info;//populate_sprite_info();

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
    if (curr_anim_name.size() > 0)
        prev_anim_name = curr_anim_name;

    curr_anim_name = animation_name;
    std::vector<standard_vertex_info> quad;
    sprite_texture_creator->bind_texture();
    if (current_frame >= animation_info[animation_name].size())
    {
        current_frame = 0;
    }
    
    if(curr_anim_name != prev_anim_name)
    {
        current_frame = 0;
    }
    if (frame_count % frames_per_frame == 0)
    {
        build_quad(animation_name, DEFAULT_FLOAT);
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


void sprite_animator::do_animation(
    std::string animation_name,
    unsigned int frames_per_frame,
    float scale)
{
    if (curr_anim_name.size() > 0)
        prev_anim_name = curr_anim_name;

    curr_anim_name = animation_name;
    std::vector<standard_vertex_info> quad;
    sprite_texture_creator->bind_texture();
    if (current_frame >= animation_info[animation_name].size())
    {
        current_frame = 0;
    }
    
    if(curr_anim_name != prev_anim_name)
    {
        current_frame = 0;
    }
    if (frame_count % frames_per_frame == 0)
    {
        build_quad(animation_name, scale);
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

void sprite_animator::move_sprite_x(float x_move_amt)
{
    sprite_location.x += x_move_amt;
}

void sprite_animator::move_sprite_y(float y_move_amt)
{
    sprite_location.y += y_move_amt;
}

void sprite_animator::build_quad(
    std::string animation_name,
    const float& scale,
    const bool& flip_texture)
{
    std::vector<standard_vertex_info> quad;
    pixel_offsets po = animation_info[animation_name][current_frame].pixel_coord;
    character_dimensions cd = animation_info[animation_name][current_frame].char_dimension;
    float x_offset = animation_info[animation_name][current_frame].x_offset;
    const float SCALE_FACTOR = (0.009f * scale);
    float vertex_x_shift = (SCALE_FACTOR * ((float)cd.width));
    float vertex_x_offset = (SCALE_FACTOR * x_offset);

    float vertex_y_shift = (SCALE_FACTOR * ((float)cd.height));

    if (!flip_anim)
    {
        ///////////////
        // TOP RIGHT //
        ///////////////
        current_quad[0].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[0].vertex_coord = {
            sprite_location.x + vertex_x_shift - vertex_x_offset, 
            sprite_location.y + vertex_y_shift, 
            0.0f};
        current_quad[0].texture_coord = {
            floatify_x(po.x + cd.width),
            floatify_y(po.y)};

        //////////////////
        // BOTTOM RIGHT //
        //////////////////
        current_quad[1].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[1].vertex_coord = {
            sprite_location.x + vertex_x_shift - vertex_x_offset, 
            sprite_location.y, 
            0.0f};
        current_quad[1].texture_coord = {
            floatify_x(po.x + cd.width),
            floatify_y(po.y + cd.height)};

        /////////////////
        // BOTTOM LEFT //
        /////////////////
        current_quad[2].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[2].vertex_coord = {
            sprite_location.x - vertex_x_offset,
            sprite_location.y};
        current_quad[2].texture_coord = {
            floatify_x(po.x),
            floatify_y(po.y + cd.height)};

        //////////////
        // TOP LEFT //
        //////////////
        current_quad[3].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[3].vertex_coord = {
            sprite_location.x - vertex_x_offset, 
            sprite_location.y + vertex_y_shift, 
            0.0f};
        current_quad[3].texture_coord = {
            floatify_x(po.x),
            floatify_y(po.y)};
        current_frame++;
    }
    else if (flip_anim)
    {
        //const float idk = 0.387;
        ///////////////
        // TOP RIGHT //
        ///////////////
        current_quad[0].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[0].vertex_coord = {
            sprite_location.x + vertex_x_shift - (vertex_x_shift - vertex_x_offset) + base_width, //+ idk, 
            sprite_location.y + vertex_y_shift};
        current_quad[0].texture_coord = {
            floatify_x(po.x),
            floatify_y(po.y)};

        //////////////////
        // BOTTOM RIGHT //
        //////////////////
        current_quad[1].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[1].vertex_coord = {
            sprite_location.x + vertex_x_shift- (vertex_x_shift - vertex_x_offset) + base_width, //+ idk, 
            sprite_location.y};
        current_quad[1].texture_coord = {
            floatify_x(po.x),
            floatify_y(po.y + cd.height)};

        /////////////////
        // BOTTOM LEFT //
        /////////////////
        current_quad[2].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[2].vertex_coord = {
            sprite_location.x- (vertex_x_shift - vertex_x_offset) + base_width,// + idk,
            sprite_location.y};
        current_quad[2].texture_coord = {
            floatify_x(po.x + cd.width),
            floatify_y(po.y + cd.height)};

        //////////////
        // TOP LEFT //
        //////////////
        current_quad[3].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[3].vertex_coord = {
            sprite_location.x- (vertex_x_shift - vertex_x_offset) + base_width, //+ idk, 
            sprite_location.y + vertex_y_shift};
        current_quad[3].texture_coord = {
            floatify_x(po.x + cd.width),
            floatify_y(po.y)};
        current_frame++;
    }
}

void sprite_animator::alter_pixel_data(std::vector<unsigned int> altered_data)
{
    sprite_texture_creator->alter_texture(altered_data);
}

std::vector<unsigned int> sprite_animator::get_pixel_data()
{
    return sprite_texture_creator->get_pixel_colors();
}
