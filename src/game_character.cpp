#include "game_character.h"

game_character::game_character(
    keyboard* k, 
    std::string character_name,
    vertex_coordinate3 character_location,
    std::string sprite_sheet_name)
{
  keyboard_ref = k;
  game_character_name = character_name;
  game_character_location = character_location;
  game_character_sprite_anim = std::make_unique<sprite_animator>(
      sprite_animator(sprite_sheet_name, character_location));
}

void game_character::process_inputs()
{}