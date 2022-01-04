#include "keyboard.h"

keyboard::keyboard(GLFWwindow* window)
{
    game_window = window;
    input_buffer_index = 0;
    for (int i = 0; i < INPUT_BUFFER_MAX_SIZE; i++)
    {
        input_buffer[i] = NONE;
    }
}

void keyboard::poll()
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
    else if (glfwGetKey(game_window, GLFW_KEY_A) == GLFW_PRESS && 
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

void keyboard::give_input_buffer_space()
{
    fg_inputs old_inputs[120];
    for (int i = 119; i < INPUT_BUFFER_MAX_SIZE; i++)
    {
        input_buffer[i - 119] = input_buffer[i];
        input_buffer[i] = NONE;
    }
}

keyboard::fg_inputs keyboard::get_last_directional_input(int index_offset)
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
