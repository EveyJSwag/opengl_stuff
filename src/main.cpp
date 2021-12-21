#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "shader_creator.h"

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

        const GLfloat vertcies[] = 
        {
            -0.5f, -0.5f, 0.0f,
             1.0f, -1.0f, 0.0f,
             0.0f,  1.0f, 0.0f
        };

        GLuint vertex_buffer_id;
        glGenBuffers(1, &vertex_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertcies), vertcies, GL_STATIC_DRAW);

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

            glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0 );
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glDisableVertexAttribArray(0);

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
    catch (std::exception& exec)
    {
        std::cout << exec.what() << std::endl;;
    }
}
