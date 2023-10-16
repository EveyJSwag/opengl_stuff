#ifndef TEXTURE_CREATOR_H
#define TEXTURE_CREATOR_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include "png_loader.h"

class texture_creator
{
public:

    texture_creator();

    void create_texture_from_png(const std::string png_file_name);

    void create_texture_with_stbi(const std::string png_file_name);

    png_loader::png_info_t get_png_info(const std::string texture_info_key);
    std::vector<unsigned int> get_pixel_colors(){return pixel_colors;}
    GLuint get_texture_id() {return texture_id;}
    png_loader::png_info_t get_current_png_info() {return current_png_info;}
    void unbind_texture();
    void bind_texture();

    void alter_texture(std::vector<unsigned int> pixel_colors);

private:


    GLuint texture_id;
    png_loader* png_loader_ref;
    png_loader::png_info_t current_png_info;
    std::map<std::string, png_loader::png_info_t> texture_info_map;

    std::vector<unsigned int> pixel_colors;

    void flip_texture_on_x_axis();

    std::vector<unsigned int> make_texture_background_transparent(
        unsigned int background_color, 
        std::vector<unsigned int> pixels);

};

#endif /* TEXTURE_CREATOR_H */