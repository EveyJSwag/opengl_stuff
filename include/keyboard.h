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
        FORWARD
    } fg_inputs;

    int get_input_buffer_size() {return input_buffer_index;}
    fg_inputs* get_input_buffer() { return input_buffer; }

private:
    const int INPUT_BUFFER_MAX_SIZE = 480;
    GLFWwindow* game_window;
    fg_inputs input_buffer[480];
    int input_buffer_index;
    void give_input_buffer_space();
};

#endif /* KEYBOARD_H */