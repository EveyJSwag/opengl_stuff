#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "font_renderer.h"
#include "font_info.h"

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

        // Initialize GLEW
        glewExperimental = GL_TRUE; glewInit();
        populate_font_info();
        vertex_quad init_vertex_quad;
        init_vertex_quad.bottom_left = {-1.0f, -0.75f, 0.0f};
        init_vertex_quad.bottom_right = {-0.9f, -0.75f, 0.0f};
        init_vertex_quad.top_left = {-1.0f, -0.5f, 0.0f};
        init_vertex_quad.top_right = {-0.9f, -0.5f, 0.0f};

        pixel_offsets font_off;
        font_off.x = 3;
        font_off.y = 4;

        pixel_offsets char_dimension;
        char_dimension.x = 10;
        char_dimension.y = 14;

        pixel_offsets char_dist;
        char_dist.x = 2;
        char_dist.y = 5;

        std::unique_ptr<font_renderer> f_ren = 
            std::make_unique<font_renderer>(
                font_renderer(
                    "font.png", 
                    init_vertex_quad, 
                    font_off, 
                    char_dimension, 
                    char_dist, 
                    font_char_loc));

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
        double end_time;
        unsigned int amount_of_frames = 0;
        unsigned int amount_of_frames_in_second = 0;
        bool shift_right = true;
        int animation_frame_count = 0;
        double start_time = glfwGetTime();
        unsigned int row_size = 0;
        std::string font_string = "Words words WoRDz";

        while(!glfwWindowShouldClose(window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.0f, 0.4f, 0.0f, 1.0f);

            f_ren->write_string(font_string);

            glfwSwapBuffers(window);
            glfwPollEvents();
            amount_of_frames++;
            if (glfwGetTime() - current_time >= 1.0f)
            {
                row_size++;
                std::cout << amount_of_frames_in_second << std::endl;
                amount_of_frames_in_second = 0;
                current_time = glfwGetTime();
            }
            amount_of_frames_in_second++;
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
