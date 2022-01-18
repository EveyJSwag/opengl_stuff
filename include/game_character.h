#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "keyboard.h"
#include "sprite_animator.h"
#include "sprite_info.h"
#include "cpp_core_audio.h"

static std::string punch_air = "punch_air.wav";
static std::string tatsu = "tatsumaki.wav";
static std::string hado = "hadoken.wav";
static std::string shoryuken = "shoryuken.wav";

class game_character
{
public:
    game_character(
        keyboard* k, 
        std::string character_name,
        vertex_coordinate3 character_location,
        std::string sprite_sheet_name,
        animation_name_location_map a_animation_info,
        float character_speed);

    void handle_character();

    vertex_coordinate3 get_location() const { return game_character_location; }

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

private:
    keyboard* keyboard_ref;
    std::string game_character_name;
    std::string current_character_state;
    float game_character_speed;
    std::unique_ptr<sprite_animator> game_character_sprite_anim;
    vertex_coordinate3 game_character_location;
    std::vector<std::string> character_move_names;
    animation_name_location_map character_animation_map;
    action_types process_inputs();
    void process_special_move();
    void perform_action(action_types& action);

    bool can_move;
    bool can_switch_animation;
    bool block_high;
    bool block_low;
    bool is_flipped;
    bool is_airborne;

    action_types prev_action;
    action_types curr_action;

    std::string curr_anim_string;
    std::string prev_anim_string;

    /*
     * maximum amount of frames player can not make any inputs before a
     * special move isn't processed
     */
    const int MAX_NONE_AMOUNT = 20;

    const int MAX_SAME_MOVE_AMOUNT = 9;
};

#endif /* GAME_CHARACTER_H */