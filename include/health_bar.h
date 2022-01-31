#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <memory>
#include <string>
#include "vector_types.h"
#include "sprite_animator.h"

class health_bar
{
public:
    health_bar(
        std::string& a_sprite_sheet_name, 
        vertex_coordinate3& a_health_bar_pos);

    void draw(bool flip=false);
private:
    std::unique_ptr<sprite_animator> health_sprite;
    vertex_coordinate3 health_bar_pos;
    std::string sprite_sheet_name;
};

#endif /* HEALTH_BAR_H */