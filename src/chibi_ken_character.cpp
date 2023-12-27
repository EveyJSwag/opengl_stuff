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
    if (can_switch_animation || can_use_air_normals)
    {
        curr_action = process_inputs();
        perform_action(curr_action);
    }

    if (curr_action != JUMP_UP && curr_action!= JUMP_FORWARD && curr_action !=JUMP_BACK)
    {
        character_sprite_anim->do_animation(curr_anim_string, 8);
    }
    else
    {
        character_sprite_anim->do_animation(curr_anim_string, 1);
    } 


    if (is_airborne)
    {
        if (curr_action == JUMP_FORWARD)
        {
            character_location.x += 0.01f;
            character_sprite_anim->move_sprite_x(0.01f);
        }
        if (curr_action == JUMP_BACK)
        {
            character_location.x -= 0.01f;
            character_sprite_anim->move_sprite_x(-0.01f);            
        }
        if (curr_action == JUMP_BACK)
        {
            if(character_sprite_anim->get_current_frame() < ((character_animation_map[curr_anim_string].size() / 2)) )
            {
                character_location.y += 0.03f;
                character_sprite_anim->move_sprite_y(0.03f);
            }
            else
            {
                character_location.y -= 0.03f;
                character_sprite_anim->move_sprite_y(-0.03f);
            }     
        }
        else
        {
            if(character_sprite_anim->get_current_frame() < ((character_animation_map[curr_anim_string].size() / 2)) )
            {
                character_location.y += 0.03f;
                character_sprite_anim->move_sprite_y(0.03f);
            }
            else
            {
                character_location.y -= 0.03f;
                character_sprite_anim->move_sprite_y(-0.03f);
            }
        }
        airborne_counter--;
    }
    if (character_sprite_anim->get_current_frame() == character_animation_map[curr_anim_string].size()  &&
        can_switch_animation == false)
    {
        if(is_airborne && airborne_counter == 0)
        {
            unsigned int current_frame_number = character_sprite_anim->get_current_frame();
            is_airborne = false;
            can_use_air_normals = false;
            airborne_counter = 0;
            if (curr_action != JUMP_FORWARD && curr_action != JUMP_BACK)
            {
                character_location.y += 0.06f;
                character_sprite_anim->move_sprite_y(0.06f);
            }
            else
            {
                character_location.y += 0.09f;
                character_sprite_anim->move_sprite_y(0.09f);
            }
            
        }
        should_animation_move = false;
        can_switch_animation = true;
        keyboard_ref->set_can_poll(true);
        if (is_airborne && airborne_counter > 0)
        {
            can_switch_animation = false;
            int mynum = 0;
            mynum--;
            can_use_air_normals = false;
            
            curr_anim_string = prev_anim_string;
            int anim_frames_left = character_animation_map[curr_anim_string].size() + 2 - airborne_counter;
            perform_action(prev_action);
            character_sprite_anim->set_current_frame_and_anim_name(anim_frames_left,prev_anim_string);
        }
    }
}

character::action_types chibi_ken_character::process_inputs()
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
                if (is_airborne && can_use_air_normals)
                {
                    return JUMPING_HEAVY_PUNCH;
                }
                if (is_special_move_qcf(HP_BIT))
                {
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (is_special_move_dpf(HP_BIT))
                {
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
                        return CROUCH_HEAVY_PUNCH;
                    }
                }
                if (keyboard_ref->was_pressed(HP_BIT))
                {
                    return HEAVY_PUNCH;
                }
                break;
            case (HK_BIT):
                if (is_airborne && can_use_air_normals)
                {
                    return JUMPING_HEAVY_KICK;
                }
                if (is_special_move_qcb(HK_BIT))
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.015f * speed_factor;
                    return QUARTER_CIRCLE_BACK;
                }
                if (is_downward(prev_input, curr_input) )
                {
                    if (keyboard_ref->was_pressed(HK_BIT))
                    {
                        return CROUCH_HEAVY_KICK;
                    }
                }
                if (keyboard_ref->was_pressed(HK_BIT))
                {
                    return HEAVY_KICK;
                }
                break;
            case (LP_BIT):
                if (is_airborne && can_use_air_normals)
                {
                    return JUMPING_LIGHT_PUNCH;
                }
                if (is_special_move_qcf(LP_BIT))
                {
                    return QUARTER_CIRCLE_FORWARD;
                }
                if (is_special_move_dpf(LP_BIT))
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.01f * speed_factor;
                    return DRAGON_PUNCH_FORWARD;
                }
                if (is_downward(prev_input, curr_input) )
                {
                    if (keyboard_ref->was_pressed(LP_BIT))
                    {
                        return CROUCH_LIGHT_PUNCH;
                    }
                }
                if (keyboard_ref->was_pressed(LP_BIT))
                {
                    return LIGHT_PUNCH;
                }
                break;
            case (LK_BIT):
                if (is_airborne && can_use_air_normals)
                {
                    return JUMPING_LIGHT_KICK;
                }
                if (is_special_move_qcb(LK_BIT)) 
                {
                    should_animation_move = true;
                    float speed_factor = 1.0f;
                    if (character_sprite_anim->get_flip_anim()) {speed_factor*=-1.0f;}
                    move_factor = 0.01f * speed_factor;
                    return QUARTER_CIRCLE_BACK;
                }
                if (is_downward(prev_input, curr_input) )
                {
                    if (keyboard_ref->was_pressed(LK_BIT))
                    {
                        return CROUCH_LIGHT_KICK;
                    }
                }
                if (keyboard_ref->was_pressed(LK_BIT))
                {
                    return LIGHT_KICK;
                }
                break;
        }

        if (!is_airborne)
        {
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
                    is_airborne = true;
                    can_use_air_normals = true;
                    airborne_counter = TOTAL_JUMP_FB_FRAMES;
                    return JUMP_BACK;
                    break;
                case (UP_BIT | RIGHT_BIT):
                    should_animation_move = true;
                    move_factor = 0.01f;
                    is_airborne = true;
                    can_use_air_normals = true;
                    airborne_counter = TOTAL_JUMP_FB_FRAMES;
                    return JUMP_FORWARD;
                    break;
                case (UP_BIT):
                    is_airborne = true;
                    can_use_air_normals = true;
                    airborne_counter = TOTAL_JUMP_FRAMES;
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
    }
    else
    {
        none_count++;
    }
    if (!is_airborne)
        return action_to_perform;
    else
        return curr_action;
}

void chibi_ken_character::perform_action(character::action_types& action) 
{

    std::string animation_string;
    prev_anim_string = curr_anim_string;
    switch (action)
    {
        case IDLE:
            animation_string = "CHIBI_KEN_IDLE";
            break;
        case TURN_AROUND:
            animation_string = "CHIBI_KEN_TURN_AROUND";
            break;
        case TURN_AROUND_CROUCH:
            animation_string = "CHIBI_KEN_CROUCH_TURN_AROUND";
            break;
        case CROUCH:
            animation_string = "CHIBI_KEN_CROUCH";
            break;
        case WALK_BACK:
            animation_string = "CHIBI_KEN_WALK";
            break;
        case RUN_FORWARD:
            animation_string = "CHIBI_KEN_RUN";
            break;
        case WALK_FORWARD:
            animation_string = "CHIBI_KEN_WALK";
            break;
        case JUMP_BACK:
            animation_string = "CHIBI_KEN_JUMP_BACKWARD";
            can_switch_animation = false;
            can_move = false;
            break;
        case JUMP_UP:
            animation_string = "CHIBI_KEN_JUMP";
            can_switch_animation = false;
            can_move = false;
            break;
        case JUMP_FORWARD:
            animation_string = "CHIBI_KEN_JUMP_FORWARD";
            can_switch_animation = false;
            can_move = false;
            break;
        case LIGHT_PUNCH:
            animation_string = "CHIBI_KEN_LIGHT_STANDING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_LIGHT_PUNCH:
            animation_string = "CHIBI_KEN_LIGHT_CROUCHING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_PUNCH:
            animation_string = "CHIBI_KEN_HEAVY_STANDING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_HEAVY_PUNCH:
            animation_string = "CHIBI_KEN_HEAVY_CROUCHING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            break;
        case LIGHT_KICK:
            animation_string = "CHIBI_KEN_LIGHT_STANDING_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_LIGHT_KICK:
            animation_string = "CHIBI_KEN_LIGHT_CROUCHING_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case HEAVY_KICK:
            animation_string = "CHIBI_KEN_HEAVY_STANDING_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case CROUCH_HEAVY_KICK:
            animation_string = "CHIBI_KEN_HEAVY_CROUCHING_KICK";
            can_switch_animation = false;
            can_move = false;
            break;
        case QUARTER_CIRCLE_FORWARD:
            animation_string = "CHIBI_KEN_HADOKEN";
            can_switch_animation = false;
            can_move = false;
            break;
        case QUARTER_CIRCLE_BACK:
            animation_string = "CHIBI_KEN_TATSUMAKI";
            can_switch_animation = false;
            can_move = false;
            break;
        case DRAGON_PUNCH_FORWARD:
            animation_string = "CHIBI_KEN_SHORYUKEN";
            can_switch_animation = false;
            can_move = false;
            break;
        case JUMPING_LIGHT_PUNCH:
            animation_string = "CHIBI_KEN_LIGHT_JUMPING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            can_use_air_normals = false;
            break;
        case JUMPING_HEAVY_PUNCH:
            animation_string = "CHIBI_KEN_HEAVY_JUMPING_PUNCH";
            can_switch_animation = false;
            can_move = false;
            can_use_air_normals = false;
            break;
        case JUMPING_LIGHT_KICK:
            animation_string = "CHIBI_KEN_LIGHT_JUMPING_KICK";
            can_switch_animation = false;
            can_move = false;
            can_use_air_normals = false;
            break;
        case JUMPING_HEAVY_KICK:
            animation_string = "CHIBI_KEN_HEAVY_JUMPING_KICK";
            can_switch_animation = false;
            can_move = false;
            can_use_air_normals = false;
            break;
    }
    curr_anim_string = animation_string;
}
