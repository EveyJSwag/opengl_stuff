#include "game_stage.h"

game_stage::game_stage(
        std::string name, 
        vertex_coordinate3 location, 
        std::string sprite_sheet_name, 
        animation_name_location_map animation_info)
{
    stage_location = location;
    stage_name = name;
    stage_animation_map = animation_info;
    stage_sprite_anim = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            stage_location, 
            stage_animation_map));
}


void game_stage::display_stage()
{
    stage_sprite_anim->do_animation("RYU_STAGE_BACKGROUND",1);
    stage_sprite_anim->do_animation("RYU_STAGE_FLOOR",1);
}