#include "chibi_ken_character.h"
chibi_ken_character::chibi_ken_character(
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
void chibi_ken_character::handle_character()
{
    character_sprite_anim->do_animation("CHIBI_KEN_IDLE", 6, 1.75f);
}

character::action_types chibi_ken_character::process_inputs()
{}

void chibi_ken_character::perform_action(character::action_types& action) 
{}
