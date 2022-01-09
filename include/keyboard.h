#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <bitset>
#include <vector>
#include <map>

#define BUTTON_AMOUNT 16
#define DIRECTION_MASK      0x0F
#define ATTACK_BUTTON_MASK  0xF0
#define UP_BIT              0x01
#define LEFT_BIT            0x02      
#define DOWN_BIT            0x04     
#define RIGHT_BIT           0x08

#define LP_BIT              0x10
#define HP_BIT              0x20
#define LK_BIT              0x40
#define HK_BIT              0x80

class keyboard
{
public:
    typedef enum special_move_id
    {
        qcf = 1,
        qcb,
        hcf,
        hcb,
        dpf,
        dpb
    } special_move_id;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> QUARTER_CIRCLE_FORWARD  ;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> QUARTER_CIRCLE_BACKWARD ;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> HALF_CIRCLE_FORWARD     ;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> HALF_CIRCLE_BACKWARD    ;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> DRAGON_FORWARD          ;
    static const std::vector<std::bitset<BUTTON_AMOUNT>> DRAGON_BACKWARD         ;




    keyboard(GLFWwindow* window);
    void poll();
    typedef enum fg_inputs
    {   NONE = 0,       //  kjiudsaw
        UP              = 0b00000001,
        UP_BACK         = 0b00000011,
        UP_FORWARD      = 0b00001001,
        DOWN            = 0b00000100,
        DOWN_BACK       = 0b00000110,
        DOWN_FORWARD    = 0b00001100,
        BACK            = 0b00000010,
        FORWARD         = 0b00001000,
        LIGHT_PUNCH     = 0b00010000,
        HEAVY_PUNCH     = 0b00100000,
        LIGHT_KICK      = 0b01000000,
        HEAVY_KICK      = 0b10000000
    } fg_inputs;

    fg_inputs get_enum_representation(std::bitset<BUTTON_AMOUNT> in);

    int get_input_buffer_size() const {return input_buffer_index;}
    std::bitset<BUTTON_AMOUNT>* get_input_buffer() { return input_bitset_array; }

    fg_inputs get_last_directional_input(int index_offset , fg_inputs filter_input);
    fg_inputs get_last_button_input(int index_offset = 0);

    bool is_qcf();
    bool is_qcb();
    bool is_dpf();
    bool is_dpb();

    void set_can_poll(bool poll_val);

    void bitset_poll();

    bool is_special_move(std::vector<std::bitset<BUTTON_AMOUNT>> bitset_vector, unsigned short button_pressed);

    unsigned short get_button(std::bitset<BUTTON_AMOUNT> input);
    unsigned short get_direction(std::bitset<BUTTON_AMOUNT> input);
private:
    const int INPUT_BUFFER_MAX_SIZE = 480;
    GLFWwindow* game_window;
    fg_inputs input_buffer[480];
    int input_buffer_index;
    void give_input_buffer_space();
    bool can_poll;

    bool is_directional(std::bitset<BUTTON_AMOUNT> in);
    bool is_button(std::bitset<BUTTON_AMOUNT> in);

    bool only_button_pressed(std::bitset<BUTTON_AMOUNT> in);
    bool only_direction_pressed(std::bitset<BUTTON_AMOUNT> in);


    std::bitset<BUTTON_AMOUNT> input_bitset_array[480];

    std::vector<std::bitset<BUTTON_AMOUNT>> input_bitsets;
};

#endif /* KEYBOARD_H */