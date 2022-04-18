#ifndef HURTBOX_H
#define HURTBOX_H

#include "vector_types.h"
#include "vertex_manager.h"
#include "buffer_manager.h"

class hurtbox
{
public:
    hurtbox();
    void draw_hurtbox();

private:
    vertex_coordinate3 hurtbox_location;
    standard_vertex_info current_quad[4];
    std::vector<standard_vertex_info> quads;

    std::unique_ptr<buffer_manager> hurtbox_buffer;
    std::unique_ptr<vertex_manager> hurtbox_vertex;

    std::vector<unsigned int> vertex_indices;

    void generate_and_bind_vertex_array();
    void generate_and_bind_vertex_and_index_buffer();
    void set_buffer_data();
};

#endif