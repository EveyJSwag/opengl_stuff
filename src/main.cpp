#include <GL/glew.h> 
#include <GLFW/glfw3.h>
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
        GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
        glfwMakeContextCurrent(window);

        // Check for window creation failure
        if (!window)
        {
            // Terminate GLFW
            glfwTerminate();
            return 0; 
        }

        keyboard* keyboard_ref = new keyboard(window);

        // Initialize GLEW
        glewExperimental = GL_TRUE; 
        glewInit();

        game_character* game_char = new game_character(
            keyboard_ref, 
            "ryu", 
            {0.0f, -0.1f, 0.0f}, 
            "ryu_sheet.png", 
            populate_sprite_info(), 
            -0.008f);

        //sprite_animator* sprite_animator_ref = new sprite_animator(
        //    "ryu_sheet.png", 
        //    {0.0f, -0.1f, 0.0f},
        //    populate_sprite_info());


        
        fps_counter* fps_counter_ref = fps_counter::get_instance();
        vertex_coordinate3 i_postion = {-1.0f, -0.2f, 0.0f};
        text_displayer* test_text = new text_displayer(i_postion);
        
        shader_creator* shader_creator_ref = new shader_creator(
            shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
            "shaders/vertex_shader.glsl", 
            "shaders/fragment_shader.glsl");

        color_vector my_color_value;
        my_color_value.r = 1.0f;
        my_color_value.g = 0.2f;
        my_color_value.b = 0.7f;

        position_vector pos_vec;
        pos_vec.x = 0.0f;
        pos_vec.y = 0.0f;
        shader_creator_ref->add_uniform("color_input");
        shader_creator_ref->add_uniform("uniformTextureCoord");
        shader_creator_ref->set_uniform2d("uniformTextureCoord", pos_vec);
        shader_creator_ref->use_program();

        double current_time = glfwGetTime();
        float should_walk = false;
        while(!glfwWindowShouldClose(window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.0f, 0.4f, 0.0f, 1.0f);

            fps_counter_ref->display_fps();
            keyboard_ref->poll();
            game_char->handle_character();
            test_text->write("I LOVE TONY");
            glfwSwapBuffers(window);
            glfwPollEvents();
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
