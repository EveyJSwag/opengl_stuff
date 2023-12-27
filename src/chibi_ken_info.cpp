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
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{15,17},  {31,40},  0.0f}));

    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9,  {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10, {{17,380},  {27,51},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(11, {{17,380},  {27,51},  0.0f}));

    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(12, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(13, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(14, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(15, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(16, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(17, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(18, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(19, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(20, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(21, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(22, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(23, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(24, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(25, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(26, {{49,380},  {31,43},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(27, {{49,380},  {31,43},  0.0f}));

    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(28, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(29, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(30, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(31, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(32, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(33, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(34, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(35, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(36, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(37, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(38, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(39, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(40, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(41, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(42, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(43, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(44, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(45, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(46, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(47, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(48, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(49, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(50, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(51, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(52, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(53, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(54, {{87,379},  {30,52},  0.0f}));
    chibi_ken_jump_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(55, {{87,379},  {30,52},  0.0f}));
    chibi_ken_info_map[chibi_ken_jump] = chibi_ken_jump_quads;

    sprite_quad_locations chibi_ken_jump_forward_quads;
    std::string chibi_ken_jump_forward = "CHIBI_KEN_JUMP_FORWARD";
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{15,17},  {31,40},  0.0f}));

    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9,  {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(11, {{184,380},  {27,51},  0.0f}));

    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(12, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(13, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(14, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(15, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(16, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(17, {{221,384},  {44,34},  0.0f}));

    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(18, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(19, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(20, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(21, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(22, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(23, {{274,370},  {28,46},  0.0f}));

    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(24, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(25, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(26, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(27, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(28, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(29, {{310,383},  {48,25},  0.0f}));

    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(30, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(31, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(32, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(33, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(34, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(35, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(36, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(37, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(38, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(39, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(40, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(41, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(42, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(43, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(44, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(45, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(46, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(47, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(48, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(49, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(50, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(51, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(52, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(53, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(54, {{366,382},  {30,52},  0.0f}));
    chibi_ken_info_map[chibi_ken_jump_forward] = chibi_ken_jump_forward_quads;


    sprite_quad_locations chibi_ken_jump_backward_quads;
    std::string chibi_ken_jump_backward = "CHIBI_KEN_JUMP_BACKWARD";
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(54, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(53, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(52, {{15,17},  {31,40},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(51, {{15,17},  {31,40},  0.0f}));

    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(50, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(49, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(48, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(47, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(46, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(45, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(44, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(43, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(42, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(41, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(40, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(39, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(38, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(37, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(36, {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(35,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(34,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(33,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(32,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(31,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(30,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(29,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(28,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(27,  {{366,382},  {30,52},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(26,  {{366,382},  {30,52},  0.0f}));

    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(25, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(24, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(23, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(22, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(21, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(20, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(19, {{184,380},  {27,51},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(18, {{184,380},  {27,51},  0.0f}));

    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(17, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(16, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(15, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(14, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(13, {{221,384},  {44,34},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(12, {{221,384},  {44,34},  0.0f}));

    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(11, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, {{274,370},  {28,46},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, {{274,370},  {28,46},  0.0f}));

    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{310,383},  {48,25},  0.0f}));
    chibi_ken_jump_backward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{310,383},  {48,25},  0.0f})); 


    chibi_ken_info_map[chibi_ken_jump_backward] = chibi_ken_jump_backward_quads;

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