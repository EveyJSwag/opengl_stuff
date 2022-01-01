#include "sprite_info.h"
#include <string>
animation_name_location_map populate_sprite_info()
{
    animation_name_location_map ryu_location_map;

    const character_dimensions standard_dimension = {43, 82};
    std::string ryu_idle = "RYU_IDLE";
    sprite_quad_locations idle_quads;
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {8,   6}, {43, 81}}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {67,  5}, {43, 82}}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {129, 6}, {43, 81}}) );
    idle_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {189, 7}, {43, 80}}) );

    ryu_location_map[ryu_idle] = idle_quads;


    std::string ryu_idle_bl = "RYU_IDLE_BL";
    sprite_quad_locations idle_quads_bl;
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {8,   87}, {43,81} }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {67,  87}, {43,82} }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {129, 87}, {43,81} }) );
    idle_quads_bl.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {189, 87}, {43,80} }) );

    ryu_location_map[ryu_idle_bl] = idle_quads_bl;

    std::string ryu_walk = "RYU_WALK";
    sprite_quad_locations walk_quads;
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {309, 7}, {43,80}}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {367, 6}, {43,81}}) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {425, 7}, {43,80} }) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {485, 7}, {43,80} }) );
    walk_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {544, 12}, {43, 75} }) );
    ryu_location_map[ryu_walk] = walk_quads;

    std::string ryu_stand_light_punch = "RYU_STAND_LIGHT_PUNCH";
    sprite_quad_locations light_punch_quads;
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {12, 205},  {43, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {12, 205},  {43, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {69, 205},  {49, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {69, 205},  {49, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {134,205},  {70, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, { {134,205},  {70, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, { {134,205},  {70, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, { {134,205},  {70, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, { {69, 205},  {49, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, { {69, 205},  {49, 85}}) );
    light_punch_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10,{ {12, 205},  {43, 85}}) );
    ryu_location_map[ryu_stand_light_punch] = light_punch_quads;

    std::string ryu_stand_light_kick = "RYU_STAND_LIGHT_KICK";
    sprite_quad_locations light_kick_quads;
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, { {10, 106},  {43, 81}}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, { {65, 102},  {50, 85}}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, { {123, 100},  {67, 87}}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, { {65, 102},  {50, 85}}) );
    light_kick_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, { {10, 106},  {43, 81}}) );
    ryu_location_map[ryu_stand_light_kick] = light_kick_quads;

    return ryu_location_map;
}
