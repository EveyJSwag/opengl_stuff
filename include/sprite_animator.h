#ifndef SPRITE_ANIMATOR_H
#define SPRITE_ANIMATOR_H

#include "vertex_manager.h"
#include "texture_creator.h"
#include "buffer_manager.h"

class sprite_animator
{
public:
    sprite_animator(
        std::string sprite_sheet_name, 
        vertex_coordinate3 a_sprite_location,
        animation_name_location_map a_animation_info);

    void do_animation(
        std::string animation_name,
        unsigned int frames_per_frame);

    void move_sprite_x(float x_move_amt);
    void move_sprite_y(float y_move_amt);

    animation_name_location_map get_animation_info() {return animation_info;}

    unsigned int get_current_frame() {return current_frame;}
private:
    std::unique_ptr<vertex_manager>     sprite_vertex_manager;
    std::unique_ptr<texture_creator>    sprite_texture_creator;
    std::unique_ptr<buffer_manager>     sprite_buffer_manager;

    vertex_coordinate3 sprite_location;

    std::vector<unsigned int> sprite_vector_indices;
    std::vector<standard_vertex_info> sprite_vertex_info;

    png_loader::png_info_t sprite_sheet_info;

    animation_name_location_map animation_info;

    standard_vertex_info current_quad[4];

    float floatify_x(unsigned int pixel_x);
    float floatify_y(unsigned int pixel_y);

    unsigned int current_frame = 0;

    unsigned int frame_count = 0;


};


#endif /* SPRITE_ANIMATOR_H */