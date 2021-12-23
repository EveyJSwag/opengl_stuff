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

        float max_x_coordinate = (float)sprite_sheet_ratio / 2.0f;
        float min_x_coordinate = (-1.0f) * ((float)sprite_sheet_ratio / 2.0f);

        float vertcies[] = {
            // positions                                // colors           // texture coords
            max_x_coordinate, max_y_coordinate, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f,   0.0f,   // top right
            max_x_coordinate, min_y_coordinate, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f,   1.0f, // bottom right
            min_x_coordinate, min_y_coordinate, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f,   1.0f, // bottom left
            min_x_coordinate, max_y_coordinate, 0.0f,   1.0f, 1.0f, 0.0f,   1.0f, 0.0f    // top left 
        };
        GLuint vertex_buffer_id;
        glGenBuffers(1, &vertex_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertcies), vertcies,GL_STATIC_DRAW);

        const unsigned int indices[] = 
        {
            0, 1, 3, 
            1, 2, 3
        };

        GLuint index_buffer_id;
        glGenBuffers(1, &index_buffer_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &(indices[0]), GL_STATIC_DRAW);

        shader_creator* shader_creator_ref = new shader_creator(
            shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
            "shaders/vertex_shader.glsl", 
            "shaders/fragment_shader.glsl");

        color_vector my_color_value;
        my_color_value.r = 1.0f;
        my_color_value.g = 0.2f;
        my_color_value.b = 0.7f;


        shader_creator_ref->add_uniform("color_input");



        while(!glfwWindowShouldClose(window)) 
        {           
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(0.1f, 0.5f, 0.0f, 1.0f);
            
            shader_creator_ref->use_program();
            
            if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
            {
                if (my_color_value.g <= 1.0f)
                {
                    my_color_value.g+=0.02f;
                }
            }
            if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
            {
                if (my_color_value.g >= 0.0f)
                {
                    my_color_value.g-=0.02f;
                }
            }

            shader_creator_ref->set_uniform("color_input", my_color_value);
            
            

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
