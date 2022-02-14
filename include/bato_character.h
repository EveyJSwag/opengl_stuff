#ifndef BATO_CHARACTER_H
#define BATO_CHARACTER_H

#include <string>
#include <memory>

#include "vector_types.h"
#include "keyboard.h"
#include "sprite_animator.h"
#include "sprite_info.h"
#include "cpp_core_audio.h"
#include "character.h"



class bato_character : public character
{
public:
    bato_character(
        keyboard* k, 
        std::string character_name,
        vertex_coordinate3 character_location,
        std::string sprite_sheet_name,
        animation_name_location_map a_animation_info,
        float character_speed,
        float base_width);

    void handle_character() override;

    void flip();

private:
    action_types process_inputs() override;
    void perform_action(action_types& action) override;
};

#endif /* BATO_CHARACTER_H */