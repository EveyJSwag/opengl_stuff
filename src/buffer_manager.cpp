#include "buffer_manager.h"

#define BUFFER_MANAGER_UNBIND 0

void buffer_manager::generate_vertex_buffer()
{
    glGenBuffers(1, &vertex_buffer_id);
}

void buffer_manager::bind_vertex_buffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id);
}

void buffer_manager::generate_index_buffer()
{
    glGenBuffers(1, &index_buffer_id);
}

void buffer_manager::bind_index_buffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
}

void buffer_manager::unbind_vertex_buffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, BUFFER_MANAGER_UNBIND);
}

void buffer_manager::unbind_index_buffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BUFFER_MANAGER_UNBIND);
}

void buffer_manager::set_index_buffer_data(std::vector<unsigned int> indices_vector)
{
    indices = indices_vector;
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, 
        indices.size() * sizeof(unsigned int), 
        &(indices[0]), 
        GL_DYNAMIC_DRAW);
}

void buffer_manager::set_initial_vertex_buffer_data(std::vector<standard_vertex_info> initial_vertex_info)
{
    vertex_info = initial_vertex_info;
    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(standard_vertex_info) * vertex_info.size(),
        vertex_info.data(), 
        GL_DYNAMIC_DRAW);
}

void buffer_manager::set_no_texture_vertex_buffer_data(std::vector<no_texture_vertex_info> no_tex_vertex_info)
{
    nt_vertex_info = no_tex_vertex_info;
    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(no_texture_vertex_info) * nt_vertex_info.size(),
        nt_vertex_info.data(), 
        GL_DYNAMIC_DRAW);
}

void buffer_manager::update_colors(std::vector <color_vector3> updated_colors)
{
    for (int i = 0; i < vertex_info.size(); i++)
    {
        vertex_info[i].color_vec = updated_colors[i];
    }

    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(standard_vertex_info) * vertex_info.size(),
        vertex_info.data(), 
        GL_DYNAMIC_DRAW);
}

void buffer_manager::update_vertex_coords(std::vector <vertex_coordinate3> updated_vertex_coords)
{
    for (int i = 0; i < vertex_info.size(); i++)
    {
        vertex_info[i].vertex_coord = updated_vertex_coords[i];
    }

    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(standard_vertex_info) * vertex_info.size(),
        vertex_info.data(), 
        GL_DYNAMIC_DRAW);
}

void buffer_manager::update_texture_coords(std::vector <texture_coordinate2> updated_texture_coords)
{
    for (int i = 0; i < vertex_info.size(); i++)
    {
        vertex_info[i].texture_coord = updated_texture_coords[i];
    }

    glBufferData(
        GL_ARRAY_BUFFER, 
        sizeof(standard_vertex_info) * vertex_info.size(),
        vertex_info.data(), 
        GL_DYNAMIC_DRAW);
}

std::vector <color_vector3> buffer_manager::get_current_colors()
{
    std::vector <color_vector3> return_vector;
    for (int i = 0; i < vertex_info.size(); i++)
    {
        return_vector.push_back(vertex_info[i].color_vec);
    }
    return return_vector;
}

std::vector <vertex_coordinate3> buffer_manager::get_current_vertex_coords()
{
    std::vector <vertex_coordinate3> return_vector;
    for (int i = 0; i < vertex_info.size(); i++)
    {
        return_vector.push_back(vertex_info[i].vertex_coord);
    }
    return return_vector;
}

std::vector <texture_coordinate2> buffer_manager::get_current_texture_coords()
{
    std::vector <texture_coordinate2> return_vector;
    for (int i = 0; i < vertex_info.size(); i++)
    {
        return_vector.push_back(vertex_info[i].texture_coord);
    }
    return return_vector;
}

void buffer_manager::set_standard_buffer_attributes()
{
    for (int attrib_index = 0; attrib_index < STANDARD_ATTRIBUTE_AMOUNT; attrib_index ++)
    {
        glEnableVertexAttribArray(attrib_index);
    }

    glVertexAttribPointer(
        0, 
        3, 
        GL_FLOAT, 
        GL_FALSE, 
        sizeof(standard_vertex_info), 
        (void*)0);

    glVertexAttribPointer(
        1, 
        3, 
        GL_FLOAT, 
        GL_FALSE, 
        sizeof(standard_vertex_info), 
        (void*)(sizeof(vertex_coordinate3)));

    glVertexAttribPointer(
        2, 
        2, 
        GL_FLOAT, 
        GL_FALSE, 
        sizeof(standard_vertex_info), 
        (void*)(sizeof(vertex_coordinate3) * 2));
}

void buffer_manager::set_no_texture_buffer_attributes()
{
    for (int attrib_index = 0; attrib_index < NO_TEXTURE_ATTRIBUTE_AMOUNT; attrib_index ++)
    {
        glEnableVertexAttribArray(attrib_index);
    }

    glVertexAttribPointer(
        0, 
        3, 
        GL_FLOAT, 
        GL_FALSE, 
        sizeof(no_texture_vertex_info), 
        (void*)0);

    glVertexAttribPointer(
        1, 
        3, 
        GL_FLOAT, 
        GL_FALSE, 
        sizeof(no_texture_vertex_info), 
        (void*)(sizeof(vertex_coordinate3)));
}

void buffer_manager::draw()
{
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (void*)0);
}

void buffer_manager::unset_standard_buffer_attributes()
{
    for (int attrib_index = 0; attrib_index < STANDARD_ATTRIBUTE_AMOUNT; attrib_index ++)
    {
        glDisableVertexAttribArray(attrib_index);
    }
}

void buffer_manager::unset_no_texture_buffer_attributes()
{
    for (int attrib_index = 0; attrib_index < NO_TEXTURE_ATTRIBUTE_AMOUNT; attrib_index ++)
    {
        glDisableVertexAttribArray(attrib_index);
    }
}

void buffer_manager::render_no_texture_buffer_content()
{
    set_no_texture_buffer_attributes();
    draw();
    unset_no_texture_buffer_attributes();
}

void buffer_manager::render_buffer_content()
{
    set_standard_buffer_attributes();
    draw();
    unset_standard_buffer_attributes();
}

