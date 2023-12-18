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
    return chibi_ken_info_map;
}