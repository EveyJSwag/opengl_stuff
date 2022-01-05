#include "game_character.h"

game_character::game_character(
    keyboard* k, 
    std::string character_name,
    vertex_coordinate3 character_location,
    std::string sprite_sheet_name,
    animation_name_location_map a_animation_info,
    float character_speed)
{
    keyboard_ref = k;
    game_character_name = character_name;
    game_character_location = character_location;
    character_animation_map = a_animation_info;
    game_character_speed = character_speed;
    game_character_sprite_anim = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            character_location, 
            character_animation_map));

    can_move = true;
    can_switch_animation = true;
}

void game_character::handle_character()
{
    if (can_switch_animation)
    {
        curr_action = process_inputs();
        perform_action(curr_action);
    }
    game_character_sprite_anim->do_animation(curr_anim_string, 9);
    if (game_character_sprite_anim->get_current_frame() == character_animation_map[curr_anim_string].size() - 1 &&
        can_switch_animation == false)
    {
        can_switch_animation = true;
        keyboard_ref->set_can_poll(true);
    }
}

game_character::action_types game_character::process_inputs()
{
    int none_count = 0;
    keyboard::fg_inputs prev_input;
    keyboard::fg_inputs curr_input;

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
        switch (curr_input)
        {
            case keyboard::LIGHT_PUNCH:
                keyboard_ref->set_can_poll(false);
                action_to_perform = action_types::LIGHT_PUNCH;
                if (keyboard_ref->is_qcf())
                {
                    return action_types::QUARTER_CIRCLE_FORWARD;
                }
                break;
            case keyboard::LIGHT_KICK:
                action_to_perform = action_types::LIGHT_KICK;
                keyboard_ref->set_can_poll(false);
                if (keyboard_ref->is_qcb())
                {
                    return action_types::QUARTER_CIRCLE_BACK;
                }
                break;
            case keyboard::HEAVY_PUNCH:
                action_to_perform = action_types::HEAVY_PUNCH;
                keyboard_ref->set_can_poll(false);
                if (keyboard_ref->is_qcf())
                {
                    return action_to_perform;
                }
                break;
            case keyboard::BACK:
                action_to_perform = action_types::WALK_BACK;
                return action_to_perform;
                break;
            case keyboard::FORWARD:
                action_to_perform = action_types::WALK_FORWARD;
                return action_to_perform;
                break;
            case keyboard::DOWN_BACK:
            case keyboard::DOWN:
            case keyboard::DOWN_FORWARD:
                action_to_perform = action_types::CROUCH;
                return action_to_perform;
                break;
        }
    }
    else
    {
        none_count++;
    }
    return action_to_perform;
}


void game_character::perform_action(action_types& action)
{
    std::string animation_string;
    prev_anim_string = curr_anim_string;
    switch (action)
    {
        case IDLE:
            animation_string = "RYU_IDLE";
            break;
        case CROUCH:
            animation_string = "RYU_CROUCH";
            break;
        case WALK_BACK:
            animation_string = "RYU_WALK";
            break;
        case WALK_FORWARD:
            animation_string = "RYU_WALK";
            break;
        case JUMP_BACK:
            animation_string = "RYU_IDLE";
            break;
        case JUMP_UP:
            animation_string = "RYU_IDLE";
            break;
        case JUMP_FORWARD:
            animation_string = "RYU_IDLE";
            break;
        case LIGHT_PUNCH:
            animation_string = "RYU_STAND_LIGHT_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_PUNCH:
            animation_string = "RYU_STAND_LIGHT_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case LIGHT_KICK:
            animation_string = "RYU_STAND_LIGHT_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_KICK:
            animation_string = "RYU_STAND_LIGHT_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case QUARTER_CIRCLE_FORWARD:
            animation_string = "RYU_HADOKEN";
            can_switch_animation = false;
            can_move = false;
            break;
        case QUARTER_CIRCLE_BACK:
            animation_string = "RYU_TATSUMAKI";
            can_switch_animation = false;
            can_move = false;
            break;
        case DRAGON_PUNCH_FORWARD:
            animation_string = "RYU_SHORYUKEN";
            can_switch_animation = false;
            can_move = false;
            break;
    }
    curr_anim_string = animation_string;
}
