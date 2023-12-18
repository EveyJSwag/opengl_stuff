#include "mauru_info.h"
#include <string>
animation_name_location_map populate_mauru_info()
{
    animation_name_location_map mauru_info_map;
    std::string mauru_idle = "MAURU_IDLE";
    sprite_quad_locations mauru_info_quads;
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{22,13},  {98,122},  0.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(1, {{129,16}, {98,119},  0.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(2, {{235,15}, {97,121},  -1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(3, {{340,20}, {97,118},  -1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(4, {{445,22}, {98,117},  0.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(5, {{19,153}, {98,117},  0.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(6, {{125,155}, {99,116},  1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(7, {{236,157}, {99,115},  1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(8, {{344,158}, {97,115},  -1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(9, {{451,155}, {99,117},  1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(10, {{22,289}, {99,117},  1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(11, {{131,288}, {99,118},  1.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(12, {{240,285}, {99,121},  0.0f}));
    mauru_info_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(13, {{347,286}, {99,119},  1.0f}));
    mauru_info_map[mauru_idle] = mauru_info_quads;
    return mauru_info_map;
}