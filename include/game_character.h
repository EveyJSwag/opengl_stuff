#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "keyboard.h"
#include "sprite_animator.h"

class game_character
{
public:
    game_character(
        keyboard* k, 
        std::string character_name,
        vertex_coordinate3 character_location,
        std::string sprite_sheet_name);

private:
    keyboard* keyboard_ref;
    std::string game_character_name;
    std::unique_ptr<sprite_animator> game_character_sprite_anim;
    vertex_coordinate3 game_character_location;
    void process_inputs();
};

#endif /* GAME_CHARACTER_H */