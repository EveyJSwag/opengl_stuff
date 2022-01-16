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

#include "fps_counter.h"
#include "text_displayer.h"
#include "game_character.h"
#include "sprite_animator.h"
#include "keyboard.h"
#include "sprite_info.h"
#include "ryu_stage_info.h"
#include "camera.h"
#include "game_stage.h"

int main() 
{
    try 
    {
        // Initialize GLFW
        glfwInit();

        // Define version and compatibility settings
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2); 
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        // Create OpenGL window and context
        GLFWwindow* window = glfwCreateWindow(1000, 800, "OpenGL", NULL, NULL);
        glfwMakeContextCurrent(window);

        // Check for window creation failure
        if (!window)
        {
            // Terminate GLFW
            glfwTerminate();
            return 0; 
        }

        keyboard* keyboard_ref = new keyboard(window);
        camera* main_camera = new camera();

        // Initialize GLEW
        glewExperimental = GL_TRUE; 
        glewInit();

        vertex_coordinate3 og_coord = {0.0f, -0.1f, 0.0f};
        vertex_coordinate3 ryu_coord = {0.1f, 0.2f, 0.0f};

        game_character* game_char = new game_character(
            keyboard_ref, 
            "ryu", 
            ryu_coord, 
            "ryu_sheet.png", 
            populate_sprite_info(), 
            -0.008f);

        
        game_stage* ryu_stage = new game_stage(
            "RYUS_STAGE", 
            og_coord, 
            og_coord,
            "ryu_stage_alpha_2.png", 
            populate_ryu_stage_info(),
            "RYU_STAGE_FLOOR",
            "RYU_STAGE_BACKGROUND");

        fps_counter* fps_counter_ref = fps_counter::get_instance();
        vertex_coordinate3 i_postion = {-1.0f, -0.2f, 0.0f};
        text_displayer* test_text = new text_displayer(i_postion);
        
        shader_creator* shader_creator_ref = new shader_creator(
            shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
            "shaders/vertex_shader.glsl", 
            "shaders/fragment_shader.glsl");

        shader_creator* shader_creator_ui = new shader_creator(
            shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH, 
            "shaders/UI_vertex_shader.glsl", 
            "shaders/UI_fragment_shader.glsl");

        shader_creator_ref->add_uniform("MVP");

        double current_time = glfwGetTime();
        float should_walk = false;
        int frame_count = 0;
        float projection_angle = 40.0f;
        float view_x_num = 0.0f;
        shader_creator_ref->use_program();
        while(!glfwWindowShouldClose(window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            
            ryu_stage->display_stage();
            game_char->handle_character();

            if (glfwGetKey(window, GLFW_KEY_RIGHT))
            {
                main_camera->move_camera(glm::vec3(0.05f, 0.0f, 0.0f));
                ryu_stage->move_background(0.008);
            }
            if (glfwGetKey(window, GLFW_KEY_LEFT))
            {
                main_camera->move_camera(glm::vec3(-0.05f, 0.0f, 0.0f));
                ryu_stage->move_background(-0.008);
            }
            if (glfwGetKey(window, GLFW_KEY_UP))
            {
                main_camera->move_camera(glm::vec3(0.0f, -0.05f, 0.0f));
            }
            if (glfwGetKey(window, GLFW_KEY_DOWN))
            {
                main_camera->move_camera(glm::vec3(0.0f, 0.05f, 0.0f));
            }
            main_camera->display();
            
            shader_creator_ref->set_uniform_matrix("MVP", main_camera->get_mvp());
            shader_creator_ui->use_program();
            fps_counter_ref->display_fps();
            keyboard_ref->poll();

            shader_creator_ref->use_program();
            glfwSwapBuffers(window);
            glfwPollEvents();
            frame_count++;
        }
        glfwTerminate(); 
        return 0;

    }
    catch (shader_creator::shader_creator_exception& exec)
    {
        std::cout << exec.get_full_reason_string() << std::endl;
    }
    catch (png_loader::png_loader_exception& png_exec)
    {
        std::cout << png_exec.get_exception_details() << std::endl;
    }
    catch (std::exception& exec)
    {
        std::cout << exec.what() << std::endl;;
    }
}
