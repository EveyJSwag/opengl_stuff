#include <string>
#include "health_bar_info.h"

animation_name_location_map populate_health_bar_info()
{
    animation_name_location_map health_bar_location_map;
    std::string health_bar = "HEALTH_BAR";
    sprite_quad_locations health_bar_quads;
    health_bar_quads.insert(std::make_pair<unsigned int, pixel_sprite_info>(0, {{23,56}, {388,47}, 0.0f}));
    health_bar_location_map[health_bar] = health_bar_quads;

    return health_bar_location_map;
}