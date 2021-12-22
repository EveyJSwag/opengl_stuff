#include "texture_creator.h"
#include "stb_image.h"

texture_creator::texture_creator()
{
    glGenTextures(1, &texture_id);

    glBindTexture(GL_TEXTURE_2D, texture_id);
}


void texture_creator::create_texture_from_png(const std::string png_file_name)
{
    const unsigned char* png_data;
    std::stringstream full_png_path;
    full_png_path << "sprites/" << png_file_name;
    int w;
    int h;
    int comp;
    unsigned char* image = stbi_load(full_png_path.str().c_str(), &w, &h, &comp, STBI_rgb);
    png_loader_ref = new png_loader(full_png_path.str().c_str());
    png_data = png_loader_ref->get_raw_png_bytes();
    
    

    png_loader::png_info_t sprite_sheet_info = png_loader_ref->get_png_info();

    std::pair<std::string, png_loader::png_info_t> texture_info_map_entry = 
        std::make_pair(png_file_name, sprite_sheet_info);

    texture_info_map.insert(texture_info_map_entry);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        GL_RGB, 
        sprite_sheet_info.image_width,
        sprite_sheet_info.image_height, 
        0,
        GL_RGB, 
        GL_UNSIGNED_BYTE, 
        png_data);



    glGenerateMipmap(GL_TEXTURE_2D);
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
