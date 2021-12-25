#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "shader_creator.h"
#include "texture_creator.h"

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

        GLuint vertex_array_id;
        glGenVertexArrays(1, &vertex_array_id);
        glBindVertexArray(vertex_array_id);

        texture_creator* tex_creator_ref = new texture_creator();
        tex_creator_ref->create_texture_from_png("ryu_sheet.png");
        float sprite_sheet_ratio = 
            (float)(tex_creator_ref->get_png_info("ryu_sheet.png").image_width)/(float)(tex_creator_ref->get_png_info("ryu_sheet.png").image_height);

        float max_y_coordinate = 0.90f;
        float min_y_coordinate = -0.90f;

        float max_x_coordinate = 51.0f/87.0f;//(float)sprite_sheet_ratio / 2.0f;
        float min_x_coordinate = -1.0f * max_x_coordinate;//(-1.0f) * ((float)sprite_sheet_ratio / 2.0f);

        const float square_x_max = 1.0f;//59.0f/785.0f;
        const float square_y_max = 1.0f;//87.0f/2138.0f;


        float vertcies[] = {
            // positions                                // colors           // texture coords
            max_x_coordinate, max_y_coordinate, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // top right
            max_x_coordinate, min_y_coordinate, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, square_y_max, // bottom right
            min_x_coordinate, min_y_coordinate, 0.0f,   0.0f, 0.0f, 1.0f,   square_x_max, square_y_max, // bottom left
            min_x_coordinate, max_y_coordinate, 0.0f,   1.0f, 1.0f, 0.0f,   square_x_max, 0.0f    // top left 
        };
        GLuint vertex_buffer_id;
        glGenBuffers(1, &vertex_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertcies), vertcies,GL_DYNAMIC_DRAW);

        const unsigned int indices[] = 
        {
            0, 1, 3, 
            1, 2, 3
        };

        GLuint index_buffer_id;
        glGenBuffers(1, &index_buffer_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &(indices[0]), GL_DYNAMIC_DRAW);

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
        //double start_time = glfwGetTime();
        double end_time;

        unsigned int amount_of_frames = 0;
        unsigned int amount_of_frames_in_second = 0;
        const unsigned int amount_of_idle_frames = 4;
        std::vector<float> shift_amounts;
        shift_amounts.push_back(square_x_max);
        shift_amounts.push_back(62.0f/785.0f);
        shift_amounts.push_back(60.0f/785.0f);

        bool shift_right = true;
        int animation_frame_count = 0;
        //glfwSwapInterval(1);
        double start_time = glfwGetTime();
        unsigned int row_size = 0;
        while(!glfwWindowShouldClose(window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


            //glPixelStorei(GL_UNPACK_ROW_LENGTH,  785/5);
            glTexSubImage2D(
                GL_TEXTURE_2D,
                0,
                0,
                0, 
                row_size,
                2138 / 5, 
                GL_BGRA, 
                GL_UNSIGNED_BYTE, 
            tex_creator_ref->get_pixel_colors().data());
            glBindTexture(GL_TEXTURE_2D, tex_creator_ref->get_texture_id());
            /*
            if (amount_of_frames % 20 == 0)
            {
                float shift_right = 0.0f;
                if (animation_frame_count == shift_amounts.size())
                {
                    animation_frame_count = 0;
                    float shift_back_amount = 0.0f;
                    for (int index = 0; index < shift_amounts.size(); index++)
                    {
                        shift_back_amount+=shift_amounts[index];
                    }
                    shift_right = (-1.0f) * (shift_back_amount);
                }
                else
                {
                    shift_right = shift_amounts[animation_frame_count];
                    animation_frame_count++;
                }
                pos_vec.x += shift_right;
                shader_creator_ref->set_uniform2d("uniformTextureCoord", pos_vec);
            }
            */

            

            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glEnableVertexAttribArray(2);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0 );
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

            glDisableVertexAttribArray(0);
            glDisableVertexAttribArray(1);
            glDisableVertexAttribArray(2);

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
        delete shader_creator_ref;
        // Terminate GLFW
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
