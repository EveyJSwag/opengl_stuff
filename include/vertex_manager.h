#ifndef VERTEX_MANAGER_H
#define VERTEX_MANAGER_H
#include <GL/glew.h> 
#include <vector>
#include <string>

#define VERTEX_MANAGER_UNBIND 0

class vertex_manager
{
public:
    void generate_vertex_array();
    void bind_vertex_array();
    void unbind_vertex_array();
    void delete_vertex_array();

    class vertex_manager_exception : public std::exception
    {
    public:
        vertex_manager_exception(
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
    std::vector<GLuint> vertex_arrays;
    GLuint vertex_array_id;
};

#endif /* VERTEX_MANAGER_H */