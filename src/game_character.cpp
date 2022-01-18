#include "game_character.h"
#include "sound_manager.h"


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
    is_airborne = false;

}

void game_character::handle_character()
{
    if (can_switch_animation)
    {
        curr_action = process_inputs();
        perform_action(curr_action);
    }
    game_character_sprite_anim->do_animation(curr_anim_string, 8);
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
        
        switch (keyboard_ref->get_button(curr_input))
        {
            case (HP_BIT):
                if (keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_FORWARD, HP_BIT))
                {
                    sound_manager::get_instance()->play_sound(hado);
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (keyboard_ref->is_special_move(keyboard::DRAGON_FORWARD, HP_BIT))
                {
                    sound_manager::get_instance()->play_sound(shoryuken);
                    return DRAGON_PUNCH_FORWARD;
                }
                if (keyboard_ref->get_direction(prev_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | RIGHT_BIT) ||
                    keyboard_ref->get_direction(curr_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | RIGHT_BIT) )
                {
                    if (keyboard_ref->was_pressed(HP_BIT))
                    {
                        sound_manager::get_instance()->play_sound(punch_air);
                        return CROUCH_HEAVY_PUNCH;
                    }
                }
                if (keyboard_ref->was_pressed(HP_BIT))
                {
                    sound_manager::get_instance()->play_sound(punch_air);
                    return HEAVY_PUNCH;
                }
                break;
            case (HK_BIT):
                if (keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_BACKWARD, HK_BIT))
                {
                    sound_manager::get_instance()->play_sound(tatsu);
                    return QUARTER_CIRCLE_BACK;
                }
                if (keyboard_ref->get_direction(prev_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | RIGHT_BIT) ||
                    keyboard_ref->get_direction(curr_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | RIGHT_BIT) )
                {
                    if (keyboard_ref->was_pressed(HK_BIT))
                    {
                        sound_manager::get_instance()->play_sound(punch_air);
                        return CROUCH_HEAVY_KICK;
                    }
                }
                if (keyboard_ref->was_pressed(HK_BIT))
                {
                    sound_manager::get_instance()->play_sound(punch_air);
                    return HEAVY_KICK;
                }
                break;
            case (LP_BIT):
                if (keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_FORWARD, LP_BIT))
                {
                    sound_manager::get_instance()->play_sound(hado);
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (keyboard_ref->is_special_move(keyboard::DRAGON_FORWARD, LP_BIT))
                {
                    sound_manager::get_instance()->play_sound(shoryuken);
                    return DRAGON_PUNCH_FORWARD;
                }
                if (keyboard_ref->get_direction(prev_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | RIGHT_BIT) ||
                    keyboard_ref->get_direction(curr_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | RIGHT_BIT) )
                {
                    if (keyboard_ref->was_pressed(LP_BIT))
                    {
                        sound_manager::get_instance()->play_sound(punch_air);
                        return CROUCH_LIGHT_PUNCH;
                    }
                }
                if (keyboard_ref->was_pressed(LP_BIT))
                {
                    sound_manager::get_instance()->play_sound(punch_air);
                    return LIGHT_PUNCH;
                }
                break;
            case (LK_BIT):
                if (keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_BACKWARD, LK_BIT))
                {
                    sound_manager::get_instance()->play_sound(tatsu);
                    return QUARTER_CIRCLE_BACK;
                }
                if (keyboard_ref->get_direction(prev_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(prev_input) == (DOWN_BIT | RIGHT_BIT) ||
                    keyboard_ref->get_direction(curr_input) == DOWN_BIT || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | LEFT_BIT) || 
                    keyboard_ref->get_direction(curr_input) == (DOWN_BIT | RIGHT_BIT) )
                {
                    if (keyboard_ref->was_pressed(LK_BIT))
                    {
                        sound_manager::get_instance()->play_sound(punch_air);
                        return CROUCH_LIGHT_KICK;
                    }
                }
                if (keyboard_ref->was_pressed(LK_BIT))
                {
                    sound_manager::get_instance()->play_sound(punch_air);
                    return LIGHT_KICK;
                }
                break;
        }

        switch (keyboard_ref->get_direction(curr_input))
        {
            case (DOWN_BIT | LEFT_BIT):
                return CROUCH;
                break;
            case (DOWN_BIT | RIGHT_BIT):
                return CROUCH;
                break;
            case (DOWN_BIT):
                return CROUCH;
                break;
            case (UP_BIT | LEFT_BIT):
                break;
            case (UP_BIT | RIGHT_BIT):
                break;
            case (UP_BIT):
                break;
            case (LEFT_BIT):
                game_character_location.x -= 0.01f;
                game_character_sprite_anim->move_sprite_x(-0.01f);
                return WALK_BACK;
                break;
            case (RIGHT_BIT):
                game_character_location.x -= 0.01f;
                game_character_sprite_anim->move_sprite_x(0.01f);
                return WALK_FORWARD;
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
        case CROUCH_LIGHT_PUNCH:
            animation_string = "RYU_CROUCH_LIGHT_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_PUNCH:
            
            animation_string = "RYU_STAND_HEAVY_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_HEAVY_PUNCH:
            animation_string = "RYU_CROUCH_HEAVY_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case LIGHT_KICK:
            animation_string = "RYU_STAND_LIGHT_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_LIGHT_KICK:
            animation_string = "RYU_CROUCH_LIGHT_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_KICK:
            animation_string = "RYU_STAND_HEAVY_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_HEAVY_KICK:
            animation_string = "RYU_CROUCH_HEAVY_KICK";
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
