#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "sprite_animator.h"
#include "sprite_info.h"

class game_stage
{

public:

    game_stage(
        std::string name, 
        vertex_coordinate3 location, 
        std::string sprite_sheet_name, 
        animation_name_location_map animation_info);

    void display_stage();

private:
    std::string stage_name;
    std::unique_ptr<sprite_animator> stage_sprite_anim;
    vertex_coordinate3 stage_location;
    animation_name_location_map stage_animation_map;

};

#endif /* GAME_STAGE_H */