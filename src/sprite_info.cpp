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
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {134,205},  {70, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {69, 205},  {49, 85}, 0.0f}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4,{ {12, 205},  {43, 85}, 0.0f}) );
    ryu_location_map[ryu_stand_light_punch] = light_punch_quads;

    std::string ryu_stand_heavy_punch = "RYU_STAND_HEAVY_PUNCH";
    sprite_quad_locations heavy_punch_quads;
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {374, 723},  {48, 83}, 5.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {442, 723},  {48, 83}, 5.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {508, 717},  {52, 89}, 6.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {577, 724},  {54, 82}, 4.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {642, 723},  {60, 83}, 4.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {713, 729},  {60, 77}, 5.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {449, 830},  {60, 77}, 5.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {522, 830},  {60, 77}, 5.0f}) );
    heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, { {593, 825},  {54, 82}, 6.0f}) );
    ryu_location_map[ryu_stand_heavy_punch] = heavy_punch_quads;

    std::string ryu_stand_light_kick = "RYU_STAND_LIGHT_KICK";
    sprite_quad_locations light_kick_quads;
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {10, 106},  {43, 81}, 0.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {65, 102},  {50, 85}, 7.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {123, 100}, {67, 87}, 18.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {65, 102},  {50, 85}, 7.0f}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {10, 106},  {43, 81}, 0.0f}) );
    ryu_location_map[ryu_stand_light_kick] = light_kick_quads;


    std::string ryu_stand_heavy_kick = "RYU_STAND_HEAVY_KICK";
    sprite_quad_locations heavy_kick_quads;
    heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {13, 326},  {44, 81}, 1.0f}) );
    heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {70, 323},  {55, 84}, 5.0f}) );
    heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {136, 323}, {69, 84}, 3.0f}) );
    heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {220, 337},  {58, 70}, 1.0f}) );
    heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {293, 334},  {44, 73}, 1.0f}) );
    ryu_location_map[ryu_stand_heavy_kick] = heavy_kick_quads;

    std::string ryu_crouch_light_punch = "RYU_CROUCH_LIGHT_PUNCH";
    sprite_quad_locations crouch_light_punch_quads;
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {238, 235},  {43, 55}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {298, 235},  {44, 55}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {360, 234},  {60, 56}}) );
    crouch_light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {439, 235},  {44, 55}}) );
    ryu_location_map[ryu_crouch_light_punch] = crouch_light_punch_quads;

    std::string ryu_crouch_light_kick = "RYU_CROUCH_LIGHT_KICK";
    sprite_quad_locations crouch_light_kick_quads;
    crouch_light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {239, 132},  {43, 55}}) );
    crouch_light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {300, 131},  {48, 56}}) );
    crouch_light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {368, 139},  {89, 48}}) );
    crouch_light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {300, 131},  {48, 56}}) );
    ryu_location_map[ryu_crouch_light_kick] = crouch_light_kick_quads;

    std::string ryu_crouch_heavy_punch = "RYU_CROUCH_HEAVY_PUNCH";
    sprite_quad_locations crouch_heavy_punch_quads;
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {542, 234},  {43, 55}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {601, 224},  {43, 65}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {658, 208},  {48, 81}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {718, 177},  {43, 112}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {658, 208},  {48, 81}}) );
    crouch_heavy_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {601, 224},  {43, 65}}) );
    ryu_location_map[ryu_crouch_heavy_punch] = crouch_heavy_punch_quads;

    std::string ryu_crouch_heavy_kick = "RYU_CROUCH_HEAVY_KICK";
    sprite_quad_locations crouch_heavy_kick_quads;
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {391, 352},  {43, 55}, 0.0f}) );
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {452, 353},  {47, 54}, 0.0f}) );
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {517, 354},  {70, 53}, 0.0f}) );
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {602, 355},  {50, 52}, 0.0f}) );
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {665, 354},  {48, 53}, 2.0f}) );
    crouch_heavy_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {726, 352},  {43, 55}, 0.0f}) );
    ryu_location_map[ryu_crouch_heavy_kick] = crouch_heavy_kick_quads;

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


    std::string ryu_jump_neutral = "RYU_JUMP_NEUTRAL";
    sprite_quad_locations jump_neutral_quads;
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {14, 598},   {43, 75} , 0.0f}) );
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {76, 570},   {41, 103}, 0.0f}) );
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {137, 539},  {41, 134}, 0.0f}) );
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {198, 514},  {41, 159}, 0.0f}) );
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {137, 539},  {41, 134}, 0.0f}) );
    jump_neutral_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {76, 570},   {41, 103}, 0.0f}) );
    ryu_location_map[ryu_jump_neutral] = jump_neutral_quads;

    std::string ryu_jump_forward = "RYU_JUMP_FORWARD";
    sprite_quad_locations jump_forward_quads;
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {298, 598},   {43, 75} , 0.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {362, 565},   {41, 108}, 0.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {413, 540},  {61, 134}, 16.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {492, 509},  {45, 165}, 4.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {545, 535},  {72, 139}, 22.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {626, 526},  {55, 148}, 14.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {700, 536},  {41, 138}, 0.0f}) );
    jump_forward_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {362, 565},   {41, 108}, 0.0f}) );
    ryu_location_map[ryu_jump_forward] = jump_forward_quads;

    std::string ryu_jump_back = "RYU_JUMP_BACK";
    sprite_quad_locations jump_back_quads;
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {298, 598}, {43, 75} , 0.0f}  ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {362, 565}, {41, 108}, 0.0f}  ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {413, 540}, {61, 134}, 16.0f} ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {492, 509}, {45, 165}, 4.0f}  ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {545, 535}, {72, 139}, 22.0f} ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {626, 526}, {55, 148}, 14.0f} ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {700, 536}, {41, 138}, 0.0f}  ));
    jump_back_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {362, 565}, {41, 108}, 0.0f}  ));
    ryu_location_map[ryu_jump_back] = jump_back_quads;

    return ryu_location_map;
}
