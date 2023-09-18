#include "hurtbox.h"

hurtbox::hurtbox()
{
    hurtbox_vertex = std::make_unique<vertex_manager>(vertex_manager());
    hurtbox_buffer = std::make_unique<buffer_manager>(buffer_manager());

    //generate_and_bind_vertex_array();
    generate_and_bind_vertex_and_index_buffer();
    set_buffer_data();
}

void hurtbox::generate_and_bind_vertex_array()
{
    hurtbox_vertex->generate_vertex_array();
    hurtbox_vertex->bind_vertex_array();
}

void hurtbox::generate_and_bind_vertex_and_index_buffer()
{
    hurtbox_buffer->generate_vertex_buffer();
    hurtbox_buffer->bind_vertex_buffer();

    hurtbox_buffer->generate_index_buffer();
    hurtbox_buffer->bind_index_buffer();
}

void hurtbox::set_buffer_data()
{
    vertex_indices = {0,1,3,1,2,3};
    hurtbox_buffer->set_index_buffer_data(vertex_indices);
}

void hurtbox::draw_hurtbox()
{
        ///////////////
        // TOP RIGHT //
        ///////////////
        current_quad[0].color_vec = {0.0f, 1.0f, 1.0f};
        current_quad[0].vertex_coord = {
            -0.3f, 
            0.5f, 
            0.0f};

        //////////////////
        // BOTTOM RIGHT //
        //////////////////
        current_quad[1].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[1].vertex_coord = {
            -0.3f, 
            0.0f, 
            0.0f};

        /////////////////
        // BOTTOM LEFT //
        /////////////////
        current_quad[2].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[2].vertex_coord = {
            -0.5f,
            0.0f,
            0.0f};

        //////////////
        // TOP LEFT //
        //////////////
        current_quad[3].color_vec = {1.0f, 1.0f, 1.0f};
        current_quad[3].vertex_coord = {
            -0.5f, 
            0.5f, 
            0.0f};

        for (int i = 0; i < 4; i++)
        {
            quads.push_back(current_quad[i]);
        }
        hurtbox_buffer->set_no_texture_vertex_buffer_data(quads);
        set_buffer_data();
        hurtbox_buffer->render_no_texture_buffer_content();
}

