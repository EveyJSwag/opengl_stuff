
#include "vertex_manager.h"
#include <sstream>
#include <algorithm>

void vertex_manager::generate_vertex_array(int amount)
{
    GLuint* tmp_vertex_ids = new GLuint(amount);
    glGenVertexArrays(amount, tmp_vertex_ids);

    while(*tmp_vertex_ids)
    {
        vertex_arrays.push_back(*tmp_vertex_ids);
        tmp_vertex_ids++;
    }
}

void vertex_manager::unbind_vertex_array()
{
    glBindVertexArray(VERTEX_MANAGER_UNBIND);
}

bool vertex_manager::verify_vertex_id_exists(GLuint vertex_array_id)
{
    std::vector<GLuint>::iterator found_vertex_itr = std::find(vertex_arrays.begin(), vertex_arrays.end(), vertex_array_id);
    return found_vertex_itr != vertex_arrays.end();
}

void vertex_manager::bind_vertex_array(GLuint vertex_array_id)
{
    if (!verify_vertex_id_exists(vertex_array_id))
    {
        throw vertex_manager_exception(__LINE__, __FILE__, "BIND: Vertex id is not registered");
    }
    else
    {
        glBindVertexArray(vertex_array_id);
    }
}

void vertex_manager::delete_vertex_array(GLuint vertex_array_id)
{
    if (!verify_vertex_id_exists(vertex_array_id))
    {
        throw vertex_manager_exception(__LINE__, __FILE__, "DELETE: Vertex id is not registered");
    }
    else
    {   
        std::remove(vertex_arrays.begin(), vertex_arrays.end(), vertex_array_id);
        glDeleteVertexArrays(1, &vertex_array_id);
    }
}

vertex_manager::vertex_manager_exception::vertex_manager_exception(
    int line,
    const char* file, 
    std::string reason)
{
    std::stringstream full_reason_stream;
    full_reason_stream << "vertex_manager_exception thrown: " << std::endl <<
        "\t" << file << ":" << line << std::endl <<
        "\t" << reason;

    full_reason_string = full_reason_stream.str(); 
}

const char* vertex_manager::vertex_manager_exception::what() const noexcept
{
    return "vertex_manager exception";
}
