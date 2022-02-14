#include "bato_character.h"
#include "sound_manager.h"

bato_character::bato_character(
    keyboard* k, 
    std::string a_character_name,
    vertex_coordinate3 character_location,
    std::string sprite_sheet_name,
    animation_name_location_map a_animation_info,
    float character_speed,
    float base_width) : 
        character::character(
            k, 
            character_location, 
            sprite_sheet_name, 
            a_animation_info, 
            character_speed, 
            base_width)
{
    character_name = a_character_name;
}

void bato_character::handle_character()
{
    character_sprite_anim->do_animation("BATO_IDLE", 8);
}


character::action_types bato_character::process_inputs()
{
    int none_count = 0;
    std::bitset<BUTTON_AMOUNT> prev_input;
    std::bitset<BUTTON_AMOUNT> curr_input;

    action_types action_to_perform = IDLE;

    int backward_buffer_bound = keyboard_ref->get_input_buffer_size() - MAX_NONE_AMOUNT - 1;
    if (backward_buffer_bound < 0)
    {
        backward_buffer_bound = 0;
    }

    if (keyboard_ref->get_input_buffer()[keyboard_ref->get_input_buffer_size() - 1] != keyboard::NONE)
    {
        prev_input = curr_input;
        curr_input = keyboard_ref->get_input_buffer()[keyboard_ref->get_input_buffer_size() - 1];
    }
    else
    {
        none_count++;
    }
    return action_to_perform;
}


void bato_character::perform_action(action_types& action)
{
    std::string animation_string;
    prev_anim_string = curr_anim_string;
    switch (action)
    {
        case IDLE:
            animation_string = "BATO_IDLE";
            break;
    }
    curr_anim_string = "BATO_IDLE";
}
