#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "keyboard.h"
#include "sprite_animator.h"
#include "sprite_info.h"
#include "cpp_core_audio.h"



class character
{
public:

    ~character()
    {}

    character(
        keyboard* k,
        vertex_coordinate3 character_location,
        std::string sprite_sheet_name,
        animation_name_location_map a_animation_info,
        float character_speed,
        float base_width);

    virtual void handle_character() = 0;

    vertex_coordinate3 get_location() const { return character_location; }

    typedef enum action_types
    {
        IDLE = 0,
        CROUCH,
        WALK_BACK,
        WALK_FORWARD,
        JUMP_BACK,
        JUMP_UP,
        JUMP_FORWARD,
        LIGHT_PUNCH,
        CROUCH_LIGHT_PUNCH,
        HEAVY_PUNCH,
        CROUCH_HEAVY_PUNCH,
        LIGHT_KICK,
        CROUCH_LIGHT_KICK,
        HEAVY_KICK,
        CROUCH_HEAVY_KICK,
        QUARTER_CIRCLE_FORWARD,
        QUARTER_CIRCLE_BACK,
        DRAGON_PUNCH_FORWARD,
        DRAGON_PUNCH_BACK
    } action_types;

    void flip();

protected:
    /*
     * maximum amount of frames player can not make any inputs before a
     * special move isn't processed
     */
    const int MAX_NONE_AMOUNT = 20;
    const int MAX_SAME_MOVE_AMOUNT = 9;

    keyboard* keyboard_ref;

    float move_factor;
    float char_base_width;
    float character_speed;

    std::unique_ptr<sprite_animator> character_sprite_anim;
    vertex_coordinate3 character_location;

    animation_name_location_map character_animation_map;

    bool can_move;
    bool can_switch_animation;
    bool can_get_hit;
    bool block_high;
    bool block_low;
    bool is_flipped;
    bool is_airborne;
    bool should_animation_move;

    action_types prev_action;
    action_types curr_action;

    std::string character_name;
    std::string current_character_state;
    std::string curr_anim_string;
    std::string prev_anim_string;
    std::vector<std::string> character_move_names;

    action_types decide_action(unsigned short action);
    virtual action_types process_inputs() = 0;
    virtual void perform_action(action_types& action) = 0;

    inline bool is_special_move_qcf(unsigned short button)
    {
        return keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_FORWARD, button) &&
            !character_sprite_anim->get_flip_anim()
            ||
            keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_BACKWARD, button)&&
            character_sprite_anim->get_flip_anim();
    }

    inline bool is_special_move_qcb(unsigned short button)
    {
        return keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_BACKWARD, button) &&
            !character_sprite_anim->get_flip_anim()
            ||
            keyboard_ref->is_special_move(keyboard::QUARTER_CIRCLE_FORWARD, button)&&
            character_sprite_anim->get_flip_anim();
    }

    inline bool is_special_move_dpf(unsigned short button)
    {
        return keyboard_ref->is_special_move(keyboard::DRAGON_FORWARD, HP_BIT) &&
                !character_sprite_anim->get_flip_anim()
                ||
                keyboard_ref->is_special_move(keyboard::DRAGON_BACKWARD, HP_BIT)&&
                character_sprite_anim->get_flip_anim();
    }

    inline bool is_downward(
        std::bitset<BUTTON_AMOUNT>& prev_input, 
        std::bitset<BUTTON_AMOUNT>& curr_input)
    {
        return keyboard_ref->get_direction(prev_input) == DOWN_BIT || 
               keyboard_ref->get_direction(prev_input) == (DOWN_BIT | LEFT_BIT) || 
               keyboard_ref->get_direction(prev_input) == (DOWN_BIT | RIGHT_BIT) ||
               keyboard_ref->get_direction(curr_input) == DOWN_BIT || 
               keyboard_ref->get_direction(curr_input) == (DOWN_BIT | LEFT_BIT) || 
               keyboard_ref->get_direction(curr_input) == (DOWN_BIT | RIGHT_BIT);
    }
};

#endif /* CHARACTER_H */