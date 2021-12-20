#include "shader_creator.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

shader_creator::shader_creator(
    const shader_type_t& shader_type,
    const std::string vertex_shader_data,
    const std::string fragment_shader_data)
{
    vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

    switch (shader_type)
    {
        case VERTEX_AND_FRAGMENT_SHADER_FILE_PATH:
            vertex_shader_file_path = vertex_shader_data;
            fragment_shader_file_path = fragment_shader_data;
            build_shaders_from_file();
            break;

        case VERTEX_AND_FRAGMENT_SHADER_RAW_STRING:
            vertex_shader_file_data = vertex_shader_data;
            fragment_shader_file_data = fragment_shader_data;
            compile_shaders(
                vertex_shader_file_data.c_str(),
                fragment_shader_file_data.c_str());
            break;
    }

    create_program();
    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);
}

void shader_creator::build_shaders_from_file()
{
    std::ifstream vertex_shader_file_stream(vertex_shader_file_path, std::ios::in);
    std::ifstream fragment_shader_file_stream(fragment_shader_file_path, std::ios::in);
    
    if (vertex_shader_file_stream.is_open() && 
        fragment_shader_file_stream.is_open())
    {
        std::stringstream vertex_shader_stringstream;
        std::stringstream fragment_shader_stringstream;
        vertex_shader_stringstream << vertex_shader_file_stream.rdbuf();
        fragment_shader_stringstream << fragment_shader_file_stream.rdbuf();
        compile_shaders(
            vertex_shader_stringstream.str().c_str(), 
            fragment_shader_stringstream.str().c_str());
    }
    else
    {
        throw new shader_creator_exception(
            __LINE__, 
            __FILE__,
            "Failed to open shaders");
    }
}

void shader_creator::compile_shaders(        
    const char* vertex_shader_bytes,
    const char* fragment_shader_bytes)
{
    glShaderSource(vertex_shader_id, 1, &vertex_shader_bytes, NULL);
    glCompileShader(vertex_shader_id);
    get_shader_compilation_info(vertex_shader_id);

    glShaderSource(fragment_shader_id, 1, &fragment_shader_bytes, NULL);
    glCompileShader(fragment_shader_id);
    get_shader_compilation_info(fragment_shader_id);
}

void shader_creator::get_shader_compilation_info(const GLuint& shader_id)
{
    GLint shader_compilation_result;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &shader_compilation_result);
    if (shader_compilation_result == GL_FALSE)
    {
        GLint shader_compilation_status_length;
        glGetShaderiv(
            shader_id, 
            GL_INFO_LOG_LENGTH, 
            &shader_compilation_status_length);

        std::vector<char> failure_reason(shader_compilation_result+1);        

        glGetShaderInfoLog(
            shader_id, 
            shader_compilation_status_length, 
            NULL, 
            &failure_reason[0]);

        throw new shader_creator_exception(
            __LINE__, 
            __FILE__, 
            std::string(&failure_reason[0]));
    }
}

void shader_creator::create_program()
{
    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);
    get_program_linking_info(program_id);
}

void shader_creator::get_program_linking_info(
    const GLuint& a_program_id)
{
    GLint linking_result;
    glGetProgramiv(a_program_id, GL_LINK_STATUS, &linking_result);
    if (linking_result == GL_FALSE)
    {
        GLint linking_status_length;
        glGetProgramiv(
            a_program_id, 
            GL_INFO_LOG_LENGTH, 
            &linking_status_length);

        std::vector<char> failure_reason(linking_status_length+1);
        glGetProgramInfoLog(
            a_program_id, 
            linking_status_length,
            NULL, 
            &failure_reason[0]);

        throw new shader_creator_exception(
            __LINE__, 
            __FILE__, 
            std::string(&failure_reason[0]));
    }
}

void shader_creator::use_program()
{
    glUseProgram(program_id);
}

shader_creator::shader_creator_exception::shader_creator_exception(
    int line, 
    const char* file, 
    std::string reason)
{
    std::stringstream reason_stream;
    reason_stream << "shader_creator_exception thrown:" << std::endl <<
        "\t" << file << ":" << line <<
        "\t" << reason;

    full_reason_string = reason_stream.str();
}

const char* shader_creator::shader_creator_exception::what() 
    const noexcept
{
    return "shader_creator_exception";
}