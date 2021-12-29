
#include "vertex_manager.h"
#include <sstream>
#include <algorithm>

void vertex_manager::generate_vertex_array()
{
    glGenVertexArrays(1, &vertex_array_id);
}

void vertex_manager::unbind_vertex_array()
{
    glBindVertexArray(VERTEX_MANAGER_UNBIND);
}

void vertex_manager::bind_vertex_array()
{
    glBindVertexArray(vertex_array_id);
}

void vertex_manager::delete_vertex_array()
{
    glDeleteVertexArrays(1, &vertex_array_id);
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
