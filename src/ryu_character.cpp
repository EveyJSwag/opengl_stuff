#include "ryu_character.h"
#include "sound_manager.h"

std::string ryu_character::punch_air = "punch_air.wav";
std::string ryu_character::tatsu = "tatsumaki.wav";
std::string ryu_character::hado = "hadoken.wav";
std::string ryu_character::shoryuken = "shoryuken.wav";

ryu_character::ryu_character(
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
            base_width)
{
    keyboard_ref = k;
    character_name = character_name;
    character_location = character_location;
    character_animation_map = a_animation_info;
    character_speed = character_speed;
    char_base_width = base_width;
    character_sprite_anim = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            character_location, 
            character_animation_map,
            char_base_width));

    can_move = true;
    can_switch_animation = true;
    is_airborne = false;
    should_animation_move = false;

    move_factor = 0.0f;
}

void ryu_character::handle_character()
{
    if (can_switch_animation)
    {
        curr_action = process_inputs();
        perform_action(curr_action);
    }
    if (should_animation_move)
    {
        character_location.x += move_factor;
        character_sprite_anim->move_sprite_x(move_factor);
    }

    character_sprite_anim->do_animation(curr_anim_string, 8);
    if (character_sprite_anim->get_current_frame() == character_animation_map[curr_anim_string].size() - 1 &&
        can_switch_animation == false)
    {
        should_animation_move = false;
        can_switch_animation = true;
        keyboard_ref->set_can_poll(true);
    }
}


ryu_character::action_types ryu_character::process_inputs()
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
                if (is_special_move_qcf(HP_BIT))
                {
                    sound_manager::get_instance()->play_sound(hado);
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (is_special_move_dpf(HP_BIT))
                {
                    sound_manager::get_instance()->play_sound(shoryuken);
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.013f * speed_factor;
                    return DRAGON_PUNCH_FORWARD;
                }
                if (is_downward(prev_input, curr_input))
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
                if (is_special_move_qcb(HK_BIT))
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.015f * speed_factor;
                    sound_manager::get_instance()->play_sound(tatsu);
                    return QUARTER_CIRCLE_BACK;
                }
                if (is_downward(prev_input, curr_input) )
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
                if (is_special_move_qcf(LP_BIT))
                {
                    sound_manager::get_instance()->play_sound(hado);
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (is_special_move_dpf(LP_BIT))
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.01f * speed_factor;
                    sound_manager::get_instance()->play_sound(shoryuken);
                    return DRAGON_PUNCH_FORWARD;
                }
                if (is_downward(prev_input, curr_input) )
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
                if (is_special_move_qcb(LK_BIT)) 
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.01f * speed_factor;
                    sound_manager::get_instance()->play_sound(tatsu);
                    return QUARTER_CIRCLE_BACK;
                }
                if (is_downward(prev_input, curr_input) )
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
                should_animation_move = true;
                move_factor = -0.01f;
                return JUMP_BACK;
                break;
            case (UP_BIT | RIGHT_BIT):
                should_animation_move = true;
                move_factor = 0.01f;
                return JUMP_FORWARD;
                break;
            case (UP_BIT):
                return JUMP_UP;
                break;
            case (LEFT_BIT):
                character_location.x -= 0.01f;
                character_sprite_anim->move_sprite_x(-0.01f);
                return WALK_BACK;
                break;
            case (RIGHT_BIT):
                character_location.x -= 0.01f;
                character_sprite_anim->move_sprite_x(0.01f);
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


void ryu_character::perform_action(action_types& action)
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
            animation_string = "RYU_JUMP_BACK";
            can_switch_animation = false;
            can_move = false;
            break;
        case JUMP_UP:
            animation_string = "RYU_JUMP_NEUTRAL";
            can_switch_animation = false;
            can_move = false;
            break;
        case JUMP_FORWARD:
            animation_string = "RYU_JUMP_FORWARD";
            can_switch_animation = false;
            can_move = false;
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
