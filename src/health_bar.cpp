#include "health_bar.h"
#include "health_bar_info.h"
#include <vector>
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

void health_bar::deplete(int columns)
{
    const int green_widths[] = {19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
    const int health_bar_width = 500;
    int start_y = 70;
    int health_bar_start_index = (health_bar_width) * start_y + 27;
    std::vector<unsigned int> health_bar_pixels = health_sprite->get_pixel_data();
    int index = 0;
    unsigned int green_pixel = health_bar_pixels[health_bar_start_index];
    while (health_bar_pixels[health_bar_start_index] == green_pixel)
    {
        health_bar_pixels[health_bar_start_index] = 0xffff000b;
        start_y+=1;
        health_bar_start_index = (health_bar_width) * start_y + 27;
    }
    health_sprite->alter_pixel_data(health_bar_pixels);
    
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