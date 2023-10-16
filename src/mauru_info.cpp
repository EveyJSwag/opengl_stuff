#include "mauru_info.h"
#include <string>
animation_name_location_map populate_mauru_info()
{
    animation_name_location_map mauru_info_map;
    std::string mauru_idle = "MAURU_IDLE";
    sprite_quad_locations mauru_info_quads;
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{22,13}, {98,122},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{113,6}, {53,91},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{0,0}, {53,97},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, {{113,6}, {53,91},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, {{0,0}, {53,97},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10, {{113,6}, {53,91},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(11, {{57,3}, {53,94},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(12, {{0,0}, {53,97},  0.0f}));
    //mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(13, {{57,3}, {53,94},  0.0f}));

    mauru_info_map[mauru_idle] = mauru_info_quads;

    return mauru_info_map;
}