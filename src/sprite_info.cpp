#include "sprite_info.h"
#include <string>
animation_name_location_map populate_sprite_info()
{
    animation_name_location_map ryu_location_map;

    const character_dimensions standard_dimension = {43, 82};
    std::string ryu_idle = "RYU_IDLE";
    sprite_quad_locations idle_quads;
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {8,   6}, {43, 81}, 0.0f}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {67,  5}, {43, 82}, 0.0f}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {129, 6}, {43, 81}, 0.0f}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {189, 7}, {43, 80}, 0.0f}) );

    ryu_location_map[ryu_idle] = idle_quads;


    std::string ryu_idle_bl = "RYU_IDLE_BL";
    sprite_quad_locations idle_quads_bl;
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {8,   87}, {43,81}, 0.0f }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {67,  87}, {43,82}, 0.0f }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {129, 87}, {43,81}, 0.0f }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {189, 87}, {43,80}, 0.0f }) );

    ryu_location_map[ryu_idle_bl] = idle_quads_bl;

    std::string ryu_walk = "RYU_WALK";
    sprite_quad_locations walk_quads;
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {309, 7}, {43,80}   ,0.0f}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {367, 6}, {43,81}   ,0.0f}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {425, 7}, {43,80}   ,0.0f}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {485, 7}, {43,80}   ,0.0f}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {544, 12}, {43, 75} ,0.0f}) );
    ryu_location_map[ryu_walk] = walk_quads;

    std::string ryu_stand_light_punch = "RYU_STAND_LIGHT_PUNCH";
    sprite_quad_locations light_punch_quads;
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {12, 205},  {43, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {12, 205},  {43, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {134,205},  {70, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {134,205},  {70, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {134,205},  {70, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {134,205},  {70, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10,{ {12, 205},  {43, 85}, 0.0f}) );
    ryu_location_map[ryu_stand_light_punch] = light_punch_quads;

    std::string ryu_stand_light_kick = "RYU_STAND_LIGHT_KICK";
    sprite_quad_locations light_kick_quads;
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {10, 106},  {43, 81}, 0.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {65, 102},  {50, 85}, 7.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {123, 100}, {67, 87}, 18.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {65, 102},  {50, 85}, 7.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {10, 106},  {43, 81}, 0.0f}) );
    ryu_location_map[ryu_stand_light_kick] = light_kick_quads;

    std::string ryu_crouch_light_punch = "RYU_CROUCH_LIGHT_PUNCH";
    sprite_quad_locations crouch_light_punch_quads;
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {238, 235},  {43, 55}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {298, 235},  {44, 55}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {360, 234},  {60, 56}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {439, 235},  {44, 55}}) );
    ryu_location_map[ryu_crouch_light_punch] = crouch_light_punch_quads;

    std::string ryu_crouch_heavy_punch = "RYU_CROUCH_HEAVY_PUNCH";
    sprite_quad_locations crouch_heavy_punch_quads;
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {542, 234},  {43, 55}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {601, 224},  {43, 65}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {658, 208},  {48, 81}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {718, 177},  {43, 112}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {658, 208},  {48, 81}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {601, 224},  {43, 65}}) );
    ryu_location_map[ryu_crouch_heavy_punch] = crouch_heavy_punch_quads;

    std::string ryu_hadoken = "RYU_HADOKEN";
    sprite_quad_locations hadoken_quads;
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {13, 724},  {50, 82}}) );
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {83, 730},  {66, 76}}) );
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {168, 731},  {66, 75}}) );
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {251, 736},  {70, 70}}) );
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {168, 731},  {66, 75}}) );
    hadoken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {83, 730},  {66, 76}}) );
    ryu_location_map[ryu_hadoken] = hadoken_quads;

    std::string ryu_shoryuken = "RYU_SHORYUKEN";
    sprite_quad_locations shoryuken_quads;
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {12, 910},  {43, 74} , 0.0f}) );
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {77, 904},  {49, 80} , 0.0f}) );
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {140, 867}, {42, 117}, 1.0f}) );
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {199, 822}, {44, 162}, 3.0f}) );
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {264, 839}, {41, 145}, 0.0f}) );
    shoryuken_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {322, 890},  {46, 94}, 3.0f}) );
    ryu_location_map[ryu_shoryuken] = shoryuken_quads;


    std::string ryu_tatsumaki = "RYU_TATSUMAKI";
    sprite_quad_locations tatsumaki_quads;
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {11, 1073},   {48, 56} , 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {78, 1015},   {42, 114}, 1.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {139, 1009},  {41, 120}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {199, 1006},  {64, 123}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {273, 1010},  {41, 119}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {323, 1012},  {68, 117}, 19.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {409, 1012},  {41, 117}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {466, 1016},  {41, 113}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, { {524, 1019},  {41, 110}, 0.0f}) );
    tatsumaki_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, { {581, 1031},  {41, 98},  0.0f}) );
    ryu_location_map[ryu_tatsumaki] = tatsumaki_quads;


    std::string ryu_crouch = "RYU_CROUCH";
    sprite_quad_locations crouch_quads;
    crouch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {239, 132},   {43, 55}}) );
    ryu_location_map[ryu_crouch] = crouch_quads;


    return ryu_location_map;
}
