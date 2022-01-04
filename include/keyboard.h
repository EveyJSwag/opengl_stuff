#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class keyboard
{
public:
    keyboard(GLFWwindow* window);
    void poll();
    typedef enum fg_inputs
    {   NONE = 0,
        UP = 1,
        UP_BACK,
        UP_FORWARD,
        DOWN,
        DOWN_BACK,
        DOWN_FORWARD,
        BACK,
        FORWARD,
        LIGHT_PUNCH,
        HEAVY_PUNCH,
        LIGHT_KICK,
        HEAVY_KICK
    } fg_inputs;

    int get_input_buffer_size() {return input_buffer_index;}
    fg_inputs* get_input_buffer() { return input_buffer; }

    fg_inputs get_last_directional_input(int index_offset = 0);
    fg_inputs get_last_button_input(int index_offset = 0);

private:
    const int INPUT_BUFFER_MAX_SIZE = 480;
    GLFWwindow* game_window;
    fg_inputs input_buffer[480];
    int input_buffer_index;
    void give_input_buffer_space();
};

#endif /* KEYBOARD_H */