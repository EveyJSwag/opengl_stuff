#include "keyboard.h"

keyboard::keyboard(GLFWwindow* window)
{
    game_window = window;
    input_buffer_index = 0;
    can_poll = true;
    for (int i = 0; i < INPUT_BUFFER_MAX_SIZE; i++)
    {
        input_buffer[i] = NONE;
    }
}

void keyboard::poll()
{
    if (can_poll)
    {
    if (glfwGetKey(game_window, GLFW_KEY_W) == GLFW_PRESS && 
        glfwGetKey(game_window, GLFW_KEY_A) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = UP_BACK;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_W) == GLFW_PRESS && 
             glfwGetKey(game_window, GLFW_KEY_D) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = UP_FORWARD;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_A) == GLFW_PRESS && 
             glfwGetKey(game_window, GLFW_KEY_S) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = DOWN_BACK;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_S) == GLFW_PRESS && 
             glfwGetKey(game_window, GLFW_KEY_D) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = DOWN_FORWARD;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_W) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = UP;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_D) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = FORWARD;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_A) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = BACK;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_S) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = DOWN;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_U) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = LIGHT_PUNCH;
    }
    else if (glfwGetKey(game_window, GLFW_KEY_J) == GLFW_PRESS)
    {
        input_buffer[input_buffer_index] = LIGHT_KICK;
    }
    else
    {
        input_buffer[input_buffer_index] = NONE;
    }

    input_buffer_index++;
    if (input_buffer_index == INPUT_BUFFER_MAX_SIZE)
    {
        give_input_buffer_space();
        input_buffer_index = 120;
    }
    }
}

void keyboard::give_input_buffer_space()
{
    fg_inputs old_inputs[120];
    for (int i = 119; i < INPUT_BUFFER_MAX_SIZE; i++)
    {
        input_buffer[i - 119] = input_buffer[i];
        input_buffer[i] = NONE;
    }
}

keyboard::fg_inputs keyboard::get_last_directional_input(int index_offset, fg_inputs filter_input)
{
    for (int i = input_buffer_index - index_offset - 1; i >= 0; i--)
    {
        if ( ( input_buffer[i] == fg_inputs::UP           ||
               input_buffer[i] == fg_inputs::UP_BACK      ||
               input_buffer[i] == fg_inputs::UP_FORWARD   ||
               input_buffer[i] == fg_inputs::DOWN         || 
               input_buffer[i] == fg_inputs::DOWN_BACK    ||
               input_buffer[i] == fg_inputs::DOWN_FORWARD ||
               input_buffer[i] == fg_inputs::BACK         ||
               input_buffer[i] == fg_inputs::FORWARD)) 
        {
            return input_buffer[i];
        }
        if ((input_buffer_index - i) == 20)
        {
            return fg_inputs::NONE;
        }
    }
    return fg_inputs::NONE;
}

keyboard::fg_inputs keyboard::get_last_button_input(int index_offset)
{
    for (int i = input_buffer_index - index_offset - 1; i >= 0; i--)
    {
        if ( ( input_buffer[i] == fg_inputs::HEAVY_KICK   ||
               input_buffer[i] == fg_inputs::HEAVY_PUNCH  ||
               input_buffer[i] == fg_inputs::LIGHT_KICK   ||
               input_buffer[i] == fg_inputs::LIGHT_PUNCH)) 
        {
            return input_buffer[i];
        }
        if ((input_buffer_index - i) == 20)
        {
            return fg_inputs::NONE;
        }
    }
    return fg_inputs::NONE;
}

void keyboard::set_can_poll(bool poll_val)
{
    can_poll = poll_val;
}




bool keyboard::is_qcf()
{
    int same_input = 0;
    fg_inputs curr;
    fg_inputs prev;
    bool found_forward = false;
    bool found_down_forward = false;
    bool found_down = false;
    int forward_index = input_buffer_index - 2;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == FORWARD)
        {
            break;
        }
    }
    same_input = 0;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == DOWN_FORWARD)
        {
            break;
        }
    }
    same_input = 0;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == DOWN)
        {
            return true;
        }
    }
    return false;
}

bool keyboard::is_qcb()
{
    int same_input = 0;
    fg_inputs curr;
    fg_inputs prev;
    bool found_forward = false;
    bool found_down_forward = false;
    bool found_down = false;
    int forward_index = input_buffer_index - 2;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == BACK)
        {
            break;
        }
    }
    same_input = 0;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == DOWN_BACK)
        {
            break;
        }
    }
    same_input = 0;
    for (; forward_index >=0; forward_index--)
    {
        if (is_directional(input_buffer[forward_index]))
        {
            same_input++;
            if (same_input == 10)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        if (input_buffer[forward_index] == DOWN)
        {
            return true;
        }
    }
    return false;
}

bool keyboard::is_dpf()
{
    return false;
}

bool keyboard::is_dpb()
{
    return false;
}

bool keyboard::is_directional(fg_inputs in)
{
    if ( ( in == fg_inputs::UP           ||
           in == fg_inputs::UP_BACK      ||
           in == fg_inputs::UP_FORWARD   ||
           in == fg_inputs::DOWN         || 
           in == fg_inputs::DOWN_BACK    ||
           in == fg_inputs::DOWN_FORWARD ||
           in == fg_inputs::BACK         ||
           in == fg_inputs::FORWARD)) 
    {
        return true;
    }
    return false;
}

bool keyboard::is_button(fg_inputs in)
{
    if ( ( in == fg_inputs::HEAVY_KICK   ||
           in == fg_inputs::HEAVY_PUNCH  ||
           in == fg_inputs::LIGHT_KICK   ||
           in == fg_inputs::LIGHT_PUNCH))
    {
        return true;
    }
    return false;
}
