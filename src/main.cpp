#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

//#include "shader_creator.h"
//#include "buffer_manager.h"
//#include "texture_creator.h"
//#include "vertex_manager.h"
//#include "vector_types.h"
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

        vertex_quad init_vertex_quad;
        init_vertex_quad.bottom_left = {0.0f, -1.0f, 0.0f};
        init_vertex_quad.bottom_right = {0.5f, -1.0f, 0.0f};
        init_vertex_quad.top_left = {0.0f, 0.0f, 0.0f};
        init_vertex_quad.top_right = {0.5f, 0.0f, 0.0f};

        pixel_offsets font_off;
        font_off.x = 3;
        font_off.y = 3;

        pixel_offsets char_dimension;
        char_dimension.x = 12;
        char_dimension.y = 14;

        std::unique_ptr<font_renderer> f_ren = 
            std::make_unique<font_renderer>(
                font_renderer("font.png", init_vertex_quad, font_off, char_dimension));


        /*

        std::unique_ptr<vertex_manager> font_vertex_ref = std::make_unique<vertex_manager>(vertex_manager());

        font_vertex_ref->generate_vertex_array();
        font_vertex_ref->bind_vertex_array();


        std::unique_ptr<texture_creator> font_texture_ref = std::make_unique<texture_creator>(texture_creator());
        font_texture_ref->create_texture_from_png("font.png");
        png_loader::png_info_t font_png_info = font_texture_ref->get_png_info("font.png");

        float sprite_sheet_ratio = 
            (float)(font_png_info.image_width)/(float)(font_png_info.image_height);

        float max_y_coordinate = 1.0f;
        float min_y_coordinate = -1.0f;

        float max_x_coordinate = -0.6f;
        float min_x_coordinate = -1.0f;
        float x_shift = 0.4f;

        const float square_x_max = 50.f/(float)(font_png_info.image_width);
        const float square_y_max = 18.0f/(float)(font_png_info.image_height);

        const float square_y_min = 4.0f/(float)(font_png_info.image_height);

        standard_vertex_info init_vertces[] = {
            { {max_x_coordinate, max_y_coordinate, 0.0f},           {1.0f, 0.0f, 0.0f},              {square_x_max,         square_y_min               }  },
            { {max_x_coordinate, min_y_coordinate, 0.0f},           {1.0f, 1.0f, 0.0f},              {square_x_max,         square_y_max}  }, 
            { {min_x_coordinate, min_y_coordinate, 0.0f},                   {0.0f, 0.0f, 1.0f},      {0.0f, square_y_max}  },
            { {min_x_coordinate, max_y_coordinate, 0.0f},             {1.0f, 1.0f, 0.0f},            {0.0f, square_y_min       }  }, 
            { {max_x_coordinate + x_shift, max_y_coordinate, 0.0f},   {1.0f, 0.0f, 0.0f},            {square_x_max, 0.0f         } },
            { {max_x_coordinate + x_shift, min_y_coordinate, 0.0f},   {0.0f, 1.0f, 0.0f},            {square_x_max, square_y_max } },
            { {max_x_coordinate,                    min_y_coordinate, 0.0f},   {0.0f, 0.0f, 1.0f},   {square_x_max + square_x_max, square_y_max } },
            { {max_x_coordinate,                    max_y_coordinate, 0.0f},   {1.0f, 1.0f, 0.0f},   {square_x_max + square_x_max, 0.0f         } }
        };

        std::vector<standard_vertex_info> vert_info_vec;
        for (int j = 0; j < 8; j++)
        {
            vert_info_vec.push_back(init_vertces[j]);
        }


        GLuint vertex_buffer_id;

        
        std::vector <unsigned int> vec_indicies({0, 1, 3, 1, 2, 3, 4, 5, 7, 5, 6, 7});

        const unsigned int indices[] = 
        {
            0, 1, 3, 
            1, 2, 3,

            4, 5, 7,
            5, 6, 7
        };

        std::unique_ptr<buffer_manager> font_buffer = std::make_unique<buffer_manager>(buffer_manager());

        font_buffer->generate_vertex_buffer();
        font_buffer->bind_vertex_buffer();
        font_buffer->generate_index_buffer();
        font_buffer->bind_index_buffer();
        font_buffer->set_index_buffer_data(vec_indicies);
        font_buffer->set_initial_vertex_buffer_data(vert_info_vec);
      
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
        */

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

        /*
        unsigned int amount_of_frames = 0;
        unsigned int amount_of_frames_in_second = 0;
        const unsigned int amount_of_idle_frames = 4;
        std::vector<float> shift_amounts;
        shift_amounts.push_back(square_x_max);
        shift_amounts.push_back(62.0f/785.0f);
        shift_amounts.push_back(60.0f/785.0f);
        */



        double current_time = glfwGetTime();
        double end_time;
        unsigned int amount_of_frames = 0;
        unsigned int amount_of_frames_in_second = 0;
        bool shift_right = true;
        int animation_frame_count = 0;
        double start_time = glfwGetTime();
        unsigned int row_size = 0;


        while(!glfwWindowShouldClose(window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.0f, 0.4f, 0.0f, 1.0f);
            /*
            font_buffer->render_buffer_content();
            */

            f_ren->write_string("dum");

            glfwSwapBuffers(window);
            glfwPollEvents();
            amount_of_frames++;
            if (glfwGetTime() - current_time >= 1.0f)
            {
                row_size++;
                std::cout << amount_of_frames_in_second << std::endl;
                amount_of_frames_in_second = 0;
                current_time = glfwGetTime();
                /*
                std::vector<vertex_coordinate3> vert_coords = font_buffer->get_current_vertex_coords();
                for (int k = 0; k < vert_coords.size(); k++)
                {
                    vert_coords[k].x += 0.01;
                }
                font_buffer->update_vertex_coords(vert_coords);
                */
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
