#include "mauru_character.h"
mauru_character::mauru_character(
    keyboard* k, 
    std::string character_name,
    vertex_coordinate3 character_location,
    std::string sprite_sheet_name,
    animation_name_location_map a_animation_info,
    float character_speed,
    float base_width)  : 
        character(
            k, 
            character_location, 
            sprite_sheet_name, 
            a_animation_info, 
            character_speed, 
            base_width,
            true)
{
    this->character_name = character_name;
}
void mauru_character::handle_character()
{
    character_sprite_anim->do_animation("MAURU_IDLE", 5);
}

character::action_types mauru_character::process_inputs()
{}

void mauru_character::perform_action(character::action_types& action) 
{}
//
