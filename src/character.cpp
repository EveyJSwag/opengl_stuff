#include "character.h"
#include "sound_manager.h"

void character::flip()
{
    character_sprite_anim->set_flip_anim(true);
}

character::character(
    keyboard* k,
    vertex_coordinate3 character_location,
    std::string sprite_sheet_name,
    animation_name_location_map a_animation_info,
    float character_speed,
    float base_width,
    bool use_stbi)
{
    keyboard_ref = k;
    character_location = character_location;
    character_animation_map = a_animation_info;
    character_speed = character_speed;
    char_base_width = base_width;
    if (!use_stbi)
    {
        character_sprite_anim = std::make_unique<sprite_animator>(
            sprite_animator(
                sprite_sheet_name, 
                character_location, 
                character_animation_map,
                char_base_width));
    }
    else
    {
        character_sprite_anim = std::make_unique<sprite_animator>(
              sprite_animator(
                  sprite_sheet_name, 
                  character_location, 
                  character_animation_map,
                  char_base_width,
                  use_stbi));
    }
    

    can_move = true;
    can_switch_animation = true;
    is_airborne = false;
    should_animation_move = false;

    move_factor = 0.0f;
}
