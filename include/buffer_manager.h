#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H
#include <GL/glew.h>
#include <vector>
#include "vector_types.h"

class buffer_manager
{

public:
    void generate_vertex_buffer();
    void bind_vertex_buffer();
    void generate_index_buffer();
    void bind_index_buffer();
    void unbind_vertex_buffer();
    void unbind_index_buffer();

    void set_index_buffer_data(std::vector<unsigned int> indices_vector);
    void set_initial_vertex_buffer_data(std::vector<standard_vertex_info> initial_vertex_info);
    void set_no_texture_vertex_buffer_data(std::vector<no_texture_vertex_info> no_tex_vertex_info);
    
    void update_colors(std::vector <color_vector3> updated_colors);
    void update_vertex_coords(std::vector <vertex_coordinate3> updated_vertex_coords);
    void update_texture_coords(std::vector <texture_coordinate2> updated_texture_coords);

    std::vector <color_vector3> get_current_colors();
    std::vector <vertex_coordinate3> get_current_vertex_coords();
    std::vector <texture_coordinate2> get_current_texture_coords();

    void render_buffer_content();
    void render_no_texture_buffer_content();

private:
    GLuint vertex_buffer_id;
    GLuint index_buffer_id;

    std::vector<unsigned int> indices;

    std::vector<standard_vertex_info> vertex_info;
    std::vector<no_texture_vertex_info> nt_vertex_info;

    void set_standard_buffer_attributes();

    void set_no_texture_buffer_attributes();

    void draw();

    void unset_standard_buffer_attributes();

    void unset_no_texture_buffer_attributes();

};

#endif /* BUFFER_MANAGER_H */