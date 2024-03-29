#ifndef SPRITE_ANIMATOR_H
#define SPRITE_ANIMATOR_H

#include <string>

#include "vertex_manager.h"
#include "texture_creator.h"
#include "buffer_manager.h"

class sprite_animator
{
public:

    const float DEFAULT_FLOAT = 1.0f;

    sprite_animator(
        std::string sprite_sheet_name, 
        vertex_coordinate3 a_sprite_location,
        animation_name_location_map a_animation_info);

    sprite_animator(
        std::string sprite_sheet_name, 
        vertex_coordinate3 a_sprite_location,
        animation_name_location_map a_animation_info,
        float& a_base_width,
        bool use_stbi=false);

    sprite_animator(
        std::string sprite_sheet_name, 
        vertex_coordinate3 a_sprite_location,
        animation_name_location_map a_animation_info,
        texture_creator& texture);

    sprite_animator(
        std::string sprite_sheet_name, 
        vertex_coordinate3 a_sprite_location,
        animation_name_location_map a_animation_info,
        texture_creator& texture,
        float& a_base_width);

    void do_animation(
        std::string animation_name,
        unsigned int frames_per_frame);

    void do_animation(
        std::string animation_name, 
        unsigned int frames_per_frame, 
        float scale);

    void move_sprite_x(float x_move_amt);
    void move_sprite_y(float y_move_amt);
    void set_current_frame_and_anim_name(unsigned int a_current_frame, std::string& a_curr_anim_name)
    {
        current_frame = a_current_frame;
        curr_anim_name = a_curr_anim_name;
        prev_anim_name = curr_anim_name;
    }
    bool get_flip_anim() const {return flip_anim;}
    void set_flip_anim(bool fa);

    animation_name_location_map get_animation_info() {return animation_info;}

    unsigned int get_current_frame() {return current_frame;}

    std::vector<unsigned int> get_pixel_data();
    void alter_pixel_data(std::vector<unsigned int> altered_data);
private:

    void build_quad(
        std::string animation_name,
        const float& scale,
        const bool&  flip_texture = false);

    std::unique_ptr<vertex_manager>     sprite_vertex_manager;
    std::unique_ptr<texture_creator>    sprite_texture_creator;
    std::unique_ptr<buffer_manager>     sprite_buffer_manager;

    vertex_coordinate3 sprite_location;

    std::vector<unsigned int> sprite_vector_indices;
    std::vector<standard_vertex_info> sprite_vertex_info;

    std::string curr_anim_name;
    std::string prev_anim_name;

    png_loader::png_info_t sprite_sheet_info;

    animation_name_location_map animation_info;

    standard_vertex_info current_quad[4];

    bool flip_anim = false;

    float base_width;

    float floatify_x(unsigned int pixel_x);
    float floatify_y(unsigned int pixel_y);

    unsigned int current_frame = 0;

    unsigned int frame_count = 0;
};


#endif /* SPRITE_ANIMATOR_H */