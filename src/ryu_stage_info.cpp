#include "ryu_stage_info.h"
#include <string>
animation_name_location_map populate_ryu_stage_info()
{
    animation_name_location_map ryu_stage_location_map;
    std::string stage_floor = "RYU_STAGE_FLOOR";
    sprite_quad_locations stage_floor_quads;
    stage_floor_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{30,21}, {446,191}, 0.0f}));
    ryu_stage_location_map[stage_floor] = stage_floor_quads;

    std::string stage_background = "RYU_STAGE_BACKGROUND";
    sprite_quad_locations stage_backbround_quads;
    stage_backbround_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{92,231}, {319,191}, 0.0f}));
    ryu_stage_location_map[stage_background] = stage_backbround_quads;

    return ryu_stage_location_map;
}