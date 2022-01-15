#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "sprite_animator.h"
#include "sprite_info.h"

class game_stage
{

public:

    game_stage(
        std::string name, 
        vertex_coordinate3 b_location, 
        vertex_coordinate3 f_location,
        std::string sprite_sheet_name, 
        animation_name_location_map animation_info,
        std::string a_floor_name,
        std::string a_background_name);

    void display_stage();

    void move_background(float x_amt);

private:
    std::string stage_name;
    std::unique_ptr<sprite_animator> stage_sprite_anim_background;
    std::unique_ptr<sprite_animator> stage_sprite_anim_floor;
    vertex_coordinate3 background_stage_location;
    vertex_coordinate3 floor_stage_location;
    animation_name_location_map stage_animation_map;

    std::string floor_name;
    std::string background_name;

};

#endif /* GAME_STAGE_H */