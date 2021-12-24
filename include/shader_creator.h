#ifndef SHADER_CREATOR_H
#define SHADER_CREATOR_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <exception>
#include "vector_types.h"

class shader_creator
{

public:
    typedef enum shader_type_t
    {
        VERTEX_AND_FRAGMENT_SHADER_FILE_PATH = 1 ,
        VERTEX_AND_FRAGMENT_SHADER_RAW_STRING
    } shader_type_t;
    
    shader_creator(
        const shader_type_t& shader_type,
        const std::string vertex_shader_data,
        const std::string fragment_shader_data);


    void use_program();

    void add_uniform(std::string uniform_name);

    void set_uniform(
        std::string uniform_name, 
        color_vector color_values);

    void set_uniform2d(
        std::string uniform_name,
        position_vector pos_vec);


    class shader_creator_exception : public std::exception
    {
    public:
        shader_creator_exception(
            int line, 
            const char* file, 
            std::string reason);

        std::string get_full_reason_string() noexcept
        {
            return full_reason_string;
        }
        const char* what() const noexcept;

    private:
        std::string full_reason_string;
    };

private:
    GLuint vertex_shader_id;
    GLuint fragment_shader_id;
    GLuint program_id;

    std::map<std::string, GLint> uniform_location_map;



    shader_creator();

    shader_creator* build_vertex_shader_from_file();
    shader_creator* build_fragment_shader_from_file();

    void build_shaders_from_file();
    void compile_shaders(
        const char* vertex_shader_bytes,
        const char* fragment_shader_bytes);

    void create_program();

    void get_shader_compilation_info(const GLuint& shader_id);

    void get_program_linking_info(const GLuint& a_program_id);

    std::string vertex_shader_file_path;
    std::string fragment_shader_file_path;

    std::string vertex_shader_file_data;
    std::string fragment_shader_file_data;

};

#endif  /* SHADER_CREATOR_H */
