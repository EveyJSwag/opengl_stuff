#include "health_bar.h"
#include "health_bar_info.h"

health_bar::health_bar(
    std::string& a_sprite_sheet_name,
    vertex_coordinate3& a_health_bar_pos)
{
    sprite_sheet_name = a_sprite_sheet_name;
    health_bar_pos = a_health_bar_pos;
    float base_width = 1.0f;
    health_sprite = std::make_unique<sprite_animator>(
        sprite_animator(
            sprite_sheet_name, 
            health_bar_pos, 
            populate_health_bar_info(),
            base_width));
}


void health_bar::draw(bool flip)
{
    if (!flip)
        health_sprite->do_animation("HEALTH_BAR", 1.0f, 0.25f);

    if (flip)
    {
        health_sprite->set_flip_anim(flip);
        health_sprite->do_animation("HEALTH_BAR", 1.0f, 0.25f);
    }
}