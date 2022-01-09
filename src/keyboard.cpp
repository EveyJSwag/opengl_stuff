#include "keyboard.h"


const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::QUARTER_CIRCLE_FORWARD = 
    {std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | RIGHT_BIT), 
     std::bitset<BUTTON_AMOUNT>(RIGHT_BIT)};

const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::QUARTER_CIRCLE_BACKWARD = 
    {std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | LEFT_BIT),  
     std::bitset<BUTTON_AMOUNT>(LEFT_BIT)};

const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::HALF_CIRCLE_FORWARD = 
    {std::bitset<BUTTON_AMOUNT>(LEFT_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | LEFT_BIT),  
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | RIGHT_BIT), 
     std::bitset<BUTTON_AMOUNT>(RIGHT_BIT)};

const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::HALF_CIRCLE_BACKWARD = 
    {std::bitset<BUTTON_AMOUNT>(RIGHT_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | RIGHT_BIT),  
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | LEFT_BIT), 
     std::bitset<BUTTON_AMOUNT>(LEFT_BIT)};

const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::DRAGON_FORWARD = 
    {std::bitset<BUTTON_AMOUNT>(RIGHT_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | RIGHT_BIT)};

const std::vector<std::bitset<BUTTON_AMOUNT>> keyboard::DRAGON_BACKWARD = 
    {std::bitset<BUTTON_AMOUNT>(LEFT_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT), 
     std::bitset<BUTTON_AMOUNT>(DOWN_BIT | LEFT_BIT)};

keyboard::keyboard(GLFWwindow* window)
{
    game_window = window;
    input_buffer_index = 0;
    can_poll = true;
}

void keyboard::bitset_poll()
{
    std::bitset<BUTTON_AMOUNT> input_bitset;
    input_bitset[0] = glfwGetKey(game_window, GLFW_KEY_W);
    input_bitset[1] = glfwGetKey(game_window, GLFW_KEY_A);
    input_bitset[2] = glfwGetKey(game_window, GLFW_KEY_S);
    input_bitset[3] = glfwGetKey(game_window, GLFW_KEY_D);
    
    input_bitset[4] = glfwGetKey(game_window, GLFW_KEY_U);
    input_bitset[5] = glfwGetKey(game_window, GLFW_KEY_I);
    input_bitset[6] = glfwGetKey(game_window, GLFW_KEY_J);
    input_bitset[7] = glfwGetKey(game_window, GLFW_KEY_K);

    input_bitset_array[input_buffer_index] = input_bitset;
    input_buffer_index++;
    if (input_buffer_index == INPUT_BUFFER_MAX_SIZE)
    {
        give_input_buffer_space();
        input_buffer_index = 240;
    }
}

void keyboard::poll()
{
    if (can_poll)
    {
        bitset_poll();
    }
}

void keyboard::give_input_buffer_space()
{
    for (int i = 230; i < INPUT_BUFFER_MAX_SIZE; i++)
    {
        input_bitset_array[i - 230] = input_bitset_array[i];
    }
}

void keyboard::set_can_poll(bool poll_val)
{
    can_poll = poll_val;
}

bool keyboard::is_directional(std::bitset<BUTTON_AMOUNT> in)
{
    if ( (in & std::bitset<BUTTON_AMOUNT>(DIRECTION_MASK)) != 0)
    {
        return true;
    }
    return false;
}

bool keyboard::is_button(std::bitset<BUTTON_AMOUNT> in)
{
    if ( (in & std::bitset<BUTTON_AMOUNT>(ATTACK_BUTTON_MASK)) != 0)
    {
        return true;
    }
    return false;
}

unsigned short keyboard::get_button(std::bitset<BUTTON_AMOUNT> input)
{
    if ( (input.to_ulong() & HP_BIT) == HP_BIT)
        return HP_BIT;
    if ( (input.to_ulong() & HK_BIT) == HK_BIT)
        return HK_BIT;
    if ( (input.to_ulong() & LP_BIT) == LP_BIT)
        return LP_BIT;
    if ( (input.to_ulong() & LK_BIT) == LK_BIT)
        return LK_BIT;

    return 0;
}
unsigned short keyboard::get_direction(std::bitset<BUTTON_AMOUNT> input)
{
    if ((input.to_ulong() & (UP_BIT | LEFT_BIT)) == (UP_BIT | LEFT_BIT))
        return (UP_BIT | LEFT_BIT);
    if ((input.to_ulong() & (UP_BIT | RIGHT_BIT)) == (UP_BIT | RIGHT_BIT))
        return (UP_BIT | RIGHT_BIT);
    if ((input.to_ulong() & (LEFT_BIT | DOWN_BIT)) == (LEFT_BIT | DOWN_BIT))
        return (LEFT_BIT | DOWN_BIT);
    if ((input.to_ulong() & (RIGHT_BIT | DOWN_BIT)) == (RIGHT_BIT | DOWN_BIT))
        return (RIGHT_BIT | DOWN_BIT);
    if ( (input.to_ulong() & UP_BIT) == UP_BIT)
        return UP_BIT;
    if ((input.to_ulong() & LEFT_BIT) == LEFT_BIT)
        return LEFT_BIT;
    if ((input.to_ulong() & DOWN_BIT) == DOWN_BIT)
        return DOWN_BIT;
    if ((input.to_ulong() & RIGHT_BIT) == RIGHT_BIT)
        return RIGHT_BIT;
    return 0;
}

bool keyboard::only_button_pressed(std::bitset<BUTTON_AMOUNT> in)
{
    if ( (in.to_ulong() & DIRECTION_MASK) != 0)
        return false;
    return true;
}

bool keyboard::only_direction_pressed(std::bitset<BUTTON_AMOUNT> in)
{
    if ( (in.to_ulong() & ATTACK_BUTTON_MASK) != 0)
        return false;
    return true;
}

bool keyboard::is_special_move(
    std::vector<std::bitset<BUTTON_AMOUNT>> bitset_vector, 
    unsigned short button_pressed)
{
    int same_input = 0;
    int forward_index = input_buffer_index - 1;
    int bv_index = bitset_vector.size() - 1;
    while (bv_index != 0)
    {
        if (forward_index == (input_buffer_index - 1))
        {
            if ( get_direction(input_bitset_array[forward_index]) == bitset_vector[bitset_vector.size() - 1].to_ulong())
            {
                bv_index--;
                same_input = 0;
            }
            else
            {
                same_input++;
            }
        }
        else if (only_direction_pressed(input_bitset_array[forward_index]) &&
                 get_direction(input_bitset_array[forward_index]) == bitset_vector[bv_index].to_ulong())
        {
            bv_index--;
            same_input = 0;
        }
        else if (is_button(input_bitset_array[forward_index]))
        {
            return false;
        }
        else
        {
            same_input++;
        }
        forward_index--;
        if (same_input == 5)
        {
            return false;
        }
    }
    return true;
}

