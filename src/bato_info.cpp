#include "bato_info.h"
#include <string>
animation_name_location_map populate_bato_info()
{
    animation_name_location_map bato_info_map;
    std::string bato_idle = "BATO_IDLE";
    sprite_quad_locations bato_info_quads;
    bato_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{0,0}, {53,97},  0.0f}));
    bato_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{57,3}, {53,94},  0.0f}));
    bato_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{113,6}, {53,91},  0.0f}));
    bato_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{57,3}, {53,94},  0.0f}));
    bato_info_map[bato_idle] = bato_info_quads;

    return bato_info_map;
}