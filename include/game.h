#ifndef  GAME_H
#define GAME_H
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <unistd.h>
#include <chrono>
#include "fps_counter.h"
#include "text_displayer.h"
#include "sprite_animator.h"
#include "keyboard.h"
#include "sprite_info.h"
#include "bato_info.h"
#include "mauru_info.h"
#include "ryu_stage_info.h"
#include "camera.h"
#include "game_stage.h"
#include "cpp_core_audio.h"
#include "health_bar.h"
#include "bato_character.h"
#include "sound_manager.h"
#include "ryu_character.h"
#include "mauru_character.h"
#include "hurtbox.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "chibi_ken_character.h"
#include "chibi_ken_info.h"

class game
{
public:
    int run_game();
    static const long long FPS_DURATION_NANO_SECONDS = (1/60.0f) * 1000000000;
private:
    GLFWwindow*     window;
    keyboard*       keyboard_ref;
    camera*         main_camera;
    sound_manager*  game_sound;
    ryu_character*  ryu_char;
    mauru_character* mauru_char;
    chibi_ken_character* chibi_ken_char;
    health_bar*     player1_health_bar;
    health_bar*     player2_health_bar;
    game_stage*     ryu_stage;
    fps_counter*    fps_counter_ref;
    hurtbox*        my_hurtbox;

    shader_creator* shader_creator_nt;
    shader_creator* shader_creator_ref;
    shader_creator* shader_creator_ui;

    vertex_coordinate3 player_1_coord;
    vertex_coordinate3 background_coord;
    vertex_coordinate3 floor_coord;
    vertex_coordinate3 health_bar_position_p1;
    vertex_coordinate3 health_bar_position_p2;
    vertex_coordinate3 fps_counter_postion;
    glm::vec3 camera_position;

    int frame_count;

    void game_loop();
    void lock_at_60_fps(const std::chrono::high_resolution_clock::time_point& loop_frame_start);
    void initialize_ImGui();
    int  initialize_OpenGL();
    void initialize_sound();
    void initialize_shaders();
    void initialize_characters();
    void initialize_ui();
    void initialize_stage();

};


#endif /* GAME_H */