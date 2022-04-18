#include "texture_creator.h"
#include "stb_image.h"
#include <iostream>

#define NOT_TRANSPARENT             0xFF000000
#define MAKE_NOT_TRANSPARENT(pixel) (pixel | NOT_TRANSPARENT)

texture_creator::texture_creator()
{
    glGenTextures(1, &texture_id);    
}

void texture_creator::unbind_texture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture_creator::bind_texture()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}

void texture_creator::create_texture_from_png(const std::string png_file_name)
{
    std::stringstream full_png_path;
    full_png_path << "sprites/" << png_file_name;
    png_loader_ref = new png_loader(full_png_path.str().c_str());

    std::vector<unsigned int> color_vector= png_loader_ref->get_png_colors();

    unsigned int background_color = color_vector[0];
    std::vector<unsigned int> color_vector_transparent = 
        make_texture_background_transparent(background_color, color_vector);

    png_loader::png_info_t sprite_sheet_info = png_loader_ref->get_png_info();
    current_png_info = png_loader_ref->get_png_info();
    std::pair<std::string, png_loader::png_info_t> texture_info_map_entry = 
        std::make_pair(png_file_name, sprite_sheet_info);

    texture_info_map.insert(texture_info_map_entry);

    
    glBindTexture(GL_TEXTURE_2D, texture_id);   
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    pixel_colors = color_vector_transparent;

    glTexImage2D(
        GL_TEXTURE_2D,
        0, 
        GL_RGBA, 
        sprite_sheet_info.image_width,
        sprite_sheet_info.image_height, 
        0,
        GL_BGRA, 
        GL_UNSIGNED_BYTE, 
        pixel_colors.data());
    glGenerateMipmap(GL_TEXTURE_2D);
}

void texture_creator::alter_texture(std::vector<unsigned int> pixel_colors)
{
    bind_texture();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(
        GL_TEXTURE_2D,
        0, 
        GL_RGBA, 
        current_png_info.image_width,
        current_png_info.image_height, 
        0,
        GL_BGRA, 
        GL_UNSIGNED_BYTE, 
        pixel_colors.data());

    glGenerateMipmap(GL_TEXTURE_2D);
    unbind_texture();
}

std::vector<unsigned int> texture_creator::make_texture_background_transparent(
    unsigned int background_color,
    std::vector<unsigned int> pixels)
{
    std::vector<unsigned int> transparent_pixels;
    for (int i = 0; i < pixels.size(); i++)
    {
        if (pixels[i] != background_color)
        {
            transparent_pixels.push_back(MAKE_NOT_TRANSPARENT(pixels[i]));
        }
        else
        {
            transparent_pixels.push_back(0);
        }
    }

    return transparent_pixels;
}

png_loader::png_info_t texture_creator::get_png_info(
    const std::string texture_info_key)
{
    png_loader::png_info_t return_info = png_loader::png_info_t();
    try
    {
        return_info = texture_info_map.at(texture_info_key);
    }
    catch (std::out_of_range& exec)
    {
        return_info.color_type = -1;    
        std::cout << exec.what() << std::endl;
    }

    return return_info;
}


void  texture_creator::flip_texture_on_x_axis()
{
    std::vector<unsigned int> x_flipped_pixel_colors;

    for (int height_index = 0; height_index < current_png_info.image_height; height_index++)
    {
        for (int width_index = (current_png_info.image_width - 1); width_index >= 0; width_index--)
        {
            x_flipped_pixel_colors.push_back( pixel_colors[ current_png_info.image_width * height_index + width_index] );
        }
    }
    std::cout << pixel_colors.size() << std::endl;
    std::cout << x_flipped_pixel_colors.size() << std::endl;
    pixel_colors = x_flipped_pixel_colors;
}
