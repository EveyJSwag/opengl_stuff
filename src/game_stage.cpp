#include "game_stage.h"
#include "texture_creator.h"

game_stage::game_stage(
    std::string name, 
    vertex_coordinate3 b_location, 
    vertex_coordinate3 f_location, 
    std::string sprite_sheet_name, 
    animation_name_location_map animation_info,
    std::string a_floor_name,
    std::string a_background_name)
{
    floor_name = a_floor_name;
    background_name = a_background_name;

    background_stage_location = b_location;
    floor_stage_location = f_location;
    stage_name = name;
    stage_animation_map = animation_info;

    texture_creator stage_texture = texture_creator();

    stage_texture.create_texture_from_png(sprite_sheet_name);

    stage_sprite_anim_background = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            background_stage_location, 
            stage_animation_map,
            stage_texture));

    stage_sprite_anim_floor = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            floor_stage_location, 
            stage_animation_map,
            stage_texture));
}


void game_stage::display_stage()
{
    stage_sprite_anim_background->do_animation(background_name,1, 2.0f);
    stage_sprite_anim_floor->do_animation(floor_name,1, 1.5f);
}


void game_stage::move_background(float x_amt)
{
    stage_sprite_anim_background->move_sprite_x(x_amt);
}
