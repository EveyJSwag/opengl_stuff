#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "font_renderer.h"

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

        character_locations font_character_locations;
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('A', {0,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('B', {1,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('C', {2,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('D', {3,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('E', {4,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('F', {5,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('G', {6,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('H', {7,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('I', {8,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('J', {9,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('K', {10,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('L', {11,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('M', {12,0}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('N', {0,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('O', {1,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('P', {2,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('Q', {3,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('R', {4,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('S', {5,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('T', {6,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('U', {7,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('V', {8,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('W', {9,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('X', {10,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('Y', {11,2}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('Z', {12,2}));


        font_character_locations.insert(std::make_pair<char, pixel_offsets>('a', {0,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('b', {1,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('c', {2,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('d', {3,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('e', {4,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('f', {5,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('g', {6,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('h', {7,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('i', {8,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('j', {9,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('k', {10,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('l', {11,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('m', {12,1}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('n', {0,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('o', {1,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('p', {2,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('q', {3,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('r', {4,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('s', {5,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('t', {6,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('u', {7,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('v', {8,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('w', {9,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('x', {10,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('y', {11,3}));
        font_character_locations.insert(std::make_pair<char, pixel_offsets>('z', {12,3}));

        vertex_quad init_vertex_quad;
        init_vertex_quad.bottom_left = {-1.0f, -1.0f, 0.0f};
        init_vertex_quad.bottom_right = {-0.8f, -1.0f, 0.0f};
        init_vertex_quad.top_left = {-1.0f, -0.5f, 0.0f};
        init_vertex_quad.top_right = {-0.8f, -0.5f, 0.0f};

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
                    font_character_locations));

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
        std::string font_string = "TEST";

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
