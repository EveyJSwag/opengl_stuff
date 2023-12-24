#include "chibi_ken_info.h"
#include <string>
animation_name_location_map populate_chibi_ken_info()
{
    animation_name_location_map chibi_ken_info_map;
    std::string chibi_ken_idle = "CHIBI_KEN_IDLE";
    sprite_quad_locations chibi_ken_info_quads;
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{15,17},  {31,40},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{49,16}, {31,41},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{84,15}, {31,42},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{122,14}, {32,43},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{160,15}, {32,42},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{196,16}, {32,41},  0.0f}));
    chibi_ken_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, {{233,17}, {32,40}, 0.0f}));
    chibi_ken_info_map[chibi_ken_idle] = chibi_ken_info_quads;

    // MOVEMENT
    sprite_quad_locations chibi_ken_walk_quads;
    std::string chibi_ken_walk = "CHIBI_KEN_WALK";
    chibi_ken_walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{14,72},  {30,42},  0.0f}));
    chibi_ken_walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{47,71},  {30,43},  0.0f}));
    chibi_ken_walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{81,71},  {29,42},  0.0f}));
    chibi_ken_walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{113,72},  {33,41},  0.0f}));
    chibi_ken_info_map[chibi_ken_walk] = chibi_ken_walk_quads;

    sprite_quad_locations chibi_ken_turn_around_quads;
    std::string chibi_ken_turn_around = "CHIBI_KEN_TURN_AROUND";
    chibi_ken_turn_around_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{311,16},  {32,41},  0.0f}));
    chibi_ken_turn_around_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{349,16},  {32,41},  0.0f}));
    chibi_ken_info_map[chibi_ken_turn_around] = chibi_ken_turn_around_quads;

    sprite_quad_locations chibi_ken_crouch_quads;
    std::string chibi_ken_crouch = "CHIBI_KEN_CROUCH";
    chibi_ken_crouch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{18,257},  {33,34},  0.0f}));
    chibi_ken_info_map[chibi_ken_crouch] = chibi_ken_crouch_quads;

    sprite_quad_locations chibi_ken_crouch_turn_around_quads;
    std::string chibi_ken_crouch_turn_around = "CHIBI_KEN_CROUCH_TURN_AROUND";
    chibi_ken_crouch_turn_around_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{93,257},  {33,34},  0.0f}));
    chibi_ken_crouch_turn_around_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{133,257},  {33,34},  0.0f}));
    chibi_ken_info_map[chibi_ken_crouch_turn_around] = chibi_ken_crouch_turn_around_quads;

    sprite_quad_locations chibi_ken_run_quads;
    std::string chibi_ken_run = "CHIBI_KEN_RUN";
    chibi_ken_run_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{311,75},  {57,39},  0.0f}));
    chibi_ken_run_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{372,77},  {38,37},  0.0f}));
    chibi_ken_run_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{414,75},  {54,39},  0.0f}));
    chibi_ken_run_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{474,77},  {39,37},  0.0f}));
    chibi_ken_info_map[chibi_ken_run] = chibi_ken_run_quads;

    sprite_quad_locations chibi_ken_jump_quads;
    std::string chibi_ken_jump = "CHIBI_KEN_JUMP";
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{87,379},  {30,52},  0.0f}));
    chibi_ken_info_map[chibi_ken_jump] = chibi_ken_jump_quads;

    sprite_quad_locations chibi_ken_jump_forward_quads;
    std::string chibi_ken_jump_forward = "CHIBI_KEN_JUMP_FORWARD";
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{366,382},  {30,52},  0.0f}));
    chibi_ken_info_map[chibi_ken_jump_forward] = chibi_ken_jump_forward_quads;

    // REGULAR BUTTONS
    sprite_quad_locations chibi_ken_light_standing_punch_quads;
    std::string chibi_ken_light_standing_punch = "CHIBI_KEN_LIGHT_STANDING_PUNCH";
    chibi_ken_light_standing_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{17,131},  {39,41},  0.0f}));
    chibi_ken_light_standing_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{59,131},  {50,41},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_standing_punch] = chibi_ken_light_standing_punch_quads;

    sprite_quad_locations chibi_ken_heavy_standing_punch_quads;
    std::string chibi_ken_heavy_standing_punch = "CHIBI_KEN_HEAVY_STANDING_PUNCH";
    chibi_ken_heavy_standing_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{128,132},  {32,40},  0.0f}));
    chibi_ken_heavy_standing_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{165,132},  {32,40},  0.0f}));
    chibi_ken_heavy_standing_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{204,132},  {51,40},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_standing_punch] = chibi_ken_heavy_standing_punch_quads;

    sprite_quad_locations chibi_ken_light_standing_kick_quads;
    std::string chibi_ken_light_standing_kick = "CHIBI_KEN_LIGHT_STANDING_KICK";
    chibi_ken_light_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{285,133},  {31,39},  0.0f}));
    chibi_ken_light_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{320,132},  {52,38},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_standing_kick] = chibi_ken_light_standing_kick_quads;

    sprite_quad_locations chibi_ken_heavy_standing_kick_quads;
    std::string chibi_ken_heavy_standing_kick = "CHIBI_KEN_HEAVY_STANDING_KICK";
    chibi_ken_heavy_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{395,131},  {41,40},  0.0f}));
    chibi_ken_heavy_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{443,129},  {34,42},  0.0f}));
    chibi_ken_heavy_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{482,128},  {53,43},  0.0f}));
    chibi_ken_heavy_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{540,130},  {38,41},  0.0f}));
    chibi_ken_heavy_standing_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{583,132},  {31,39},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_standing_kick] = chibi_ken_heavy_standing_kick_quads;

    sprite_quad_locations chibi_ken_light_crouching_punch_quads;
    std::string chibi_ken_light_crouching_punch = "CHIBI_KEN_LIGHT_CROUCHING_PUNCH";
    chibi_ken_light_crouching_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{15,318},  {36,34},  0.0f}));
    chibi_ken_light_crouching_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{54,317},  {47,34},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_crouching_punch] = chibi_ken_light_crouching_punch_quads;
    
    sprite_quad_locations chibi_ken_heavy_crouching_punch_quads;
    std::string chibi_ken_heavy_crouching_punch = "CHIBI_KEN_HEAVY_CROUCHING_PUNCH";
    chibi_ken_heavy_crouching_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{128,316},  {39,35},  0.0f}));
    chibi_ken_heavy_crouching_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{171,311},  {40,40},  0.0f}));
    chibi_ken_heavy_crouching_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{215,293},  {33,58},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_crouching_punch] = chibi_ken_heavy_crouching_punch_quads;

    sprite_quad_locations chibi_ken_light_crouching_kick_quads;
    std::string chibi_ken_light_crouching_kick = "CHIBI_KEN_LIGHT_CROUCHING_KICK";
    chibi_ken_light_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{275,318},  {36,33},  0.0f}));
    chibi_ken_light_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{318,318},  {46,33},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_crouching_kick] = chibi_ken_light_crouching_kick_quads;

    sprite_quad_locations chibi_ken_heavy_crouching_kick_quads;
    std::string chibi_ken_heavy_crouching_kick = "CHIBI_KEN_HEAVY_CROUCHING_KICK";
    chibi_ken_heavy_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{392,318},  {32,33},  0.0f}));
    chibi_ken_heavy_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{428,319},  {58,32},  0.0f}));
    chibi_ken_heavy_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{493,321},  {32,30},  0.0f}));
    chibi_ken_heavy_crouching_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{530,317},  {30,34},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_crouching_kick] = chibi_ken_heavy_crouching_kick_quads;

    sprite_quad_locations chibi_ken_light_jumping_punch_quads;
    std::string chibi_ken_light_jumping_punch = "CHIBI_KEN_LIGHT_JUMPING_PUNCH";
    chibi_ken_light_jumping_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{17,459},  {30,40},  0.0f}));
    chibi_ken_light_jumping_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{57,463},  {42,36},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_jumping_punch] = chibi_ken_light_jumping_punch_quads;
    
    sprite_quad_locations chibi_ken_heavy_jumping_punch_quads;
    std::string chibi_ken_heavy_jumping_punch = "CHIBI_KEN_HEAVY_JUMPING_PUNCH";
    chibi_ken_heavy_jumping_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{17,459},  {30,40},  0.0f}));
    chibi_ken_heavy_jumping_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{126,462}, {46,37},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_jumping_punch] = chibi_ken_heavy_jumping_punch_quads;

    sprite_quad_locations chibi_ken_light_jumping_kick_quads;
    std::string chibi_ken_light_jumping_kick = "CHIBI_KEN_LIGHT_JUMPING_KICK";
    chibi_ken_light_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{201,459}, {30,40},  0.0f}));
    chibi_ken_light_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{241,463}, {43,36},  0.0f}));
    chibi_ken_info_map[chibi_ken_light_jumping_kick] = chibi_ken_light_jumping_kick_quads;

    sprite_quad_locations chibi_ken_heavy_jumping_kick_quads;
    std::string chibi_ken_heavy_jumping_kick = "CHIBI_KEN_HEAVY_JUMPING_KICK";
    chibi_ken_heavy_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{201,459},  {30,40},  0.0f}));
    chibi_ken_heavy_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{303,458},  {29,46},  0.0f}));
    chibi_ken_heavy_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{342,453},  {40,51},  0.0f}));
    chibi_ken_heavy_jumping_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{409,462},  {49,39},  0.0f}));
    chibi_ken_info_map[chibi_ken_heavy_jumping_kick] = chibi_ken_heavy_jumping_kick_quads;


    // SPECIAL MOVES
    sprite_quad_locations chibi_ken_hadoken_quads;
    std::string chibi_ken_hadoken = "CHIBI_KEN_HADOKEN";
    chibi_ken_hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{14,535},  {38,38},  0.0f}));
    chibi_ken_hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{58,533},  {52,40},  0.0f}));
    chibi_ken_hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{116,535}, {52,38},  0.0f}));
    chibi_ken_info_map[chibi_ken_hadoken] = chibi_ken_hadoken_quads;

    sprite_quad_locations chibi_ken_shoryuken_quads;
    std::string chibi_ken_shoryuken = "CHIBI_KEN_SHORYUKEN";
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{358,537}, {34,46},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{397,532}, {39,41},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{439,531}, {39,41},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{482,508}, {30,65},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{518,508}, {34,65},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{558,510}, {27,63},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, {{594,514}, {27,58},  0.0f}));
    chibi_ken_shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, {{629,508}, {27,66},  0.0f}));
    chibi_ken_info_map[chibi_ken_shoryuken] = chibi_ken_shoryuken_quads;

    sprite_quad_locations chibi_ken_tatsumaki_quads;
    std::string chibi_ken_tatsumaki= "CHIBI_KEN_TATSUMAKI";
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{12,590},  {33,48},  0.0f}));
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{52,595},  {26,37},  0.0f}));
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{86,590},  {31,46},  0.0f}));
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{125,590}, {45,47},  0.0f}));
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{176,590}, {29,46},  0.0f}));
    chibi_ken_tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{212,591}, {40,46},  0.0f}));
    chibi_ken_info_map[chibi_ken_tatsumaki] = chibi_ken_tatsumaki_quads;

    // PROJECTILE
    sprite_quad_locations chibi_ken_hadoken_projectile_quads;
    std::string chibi_ken_hadoken_projectile = "CHIBI_KEN_HADOKEN_PROJECTILE";
    chibi_ken_hadoken_projectile_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{179,539}, {35,24},  0.0f}));
    chibi_ken_hadoken_projectile_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{221,539}, {30,25},  0.0f}));
    chibi_ken_hadoken_projectile_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{256,531}, {24,40},  0.0f}));
    chibi_ken_hadoken_projectile_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{286,529}, {24,48},  0.0f}));
    chibi_ken_info_map[chibi_ken_hadoken_projectile] = chibi_ken_hadoken_projectile_quads;




    return chibi_ken_info_map;
}