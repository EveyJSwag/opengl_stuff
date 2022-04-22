#ifndef VECTOR_TYPES_H
#define VECTOR_TYPES_H

#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <map>
#include <vector>

typedef struct color_vector
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
} color_vector;

typedef struct position_vector
{
    float x;
    float y;
}position_vector;


//
// Standard vertex setup:
//  3 floats for vertex postion/coordinate
//  3 floats for color
//  2 floats for texture coordinate
const int STANDARD_ATTRIBUTE_AMOUNT = 3;

const int NO_TEXTURE_ATTRIBUTE_AMOUNT = 2;

typedef struct vertex_coordinate3
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} vertex_coordinate3;

typedef struct color_vector3
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
} color_vector3;

typedef struct texture_coordinate2
{
    GLfloat x;
    GLfloat y;
} texture_coordinate2;

typedef struct standard_vertex_information
{
    vertex_coordinate3 vertex_coord;
    color_vector3 color_vec;
    texture_coordinate2 texture_coord;
} standard_vertex_info;


typedef struct no_texture_vertex_info
{
    vertex_coordinate3 vertex_coord;
    color_vector3 color_vec;
} no_texture_vertex_info;

typedef struct pixel_offsets
{
    int x;
    int y;
} pixel_offsets;

typedef struct character_dimensions
{
    int width;
    int height;
} character_dimensions;

typedef struct pixel_font_info
{
    pixel_offsets        pixel_coord;
    character_dimensions char_dimension;
    float                x_offset;
} pixel_font_info, pixel_sprite_info;

typedef struct vertex_coord2
{
    float x;
    float y;
} vertex_coord2;

typedef struct vertex_quad
{
    vertex_coordinate3 top_left;
    vertex_coordinate3 top_right;
    vertex_coordinate3 bottom_left;
    vertex_coordinate3 bottom_right;
} vertex_quad;

typedef std::map<char, pixel_offsets> character_locations;
typedef std::pair<char, pixel_offsets> character_location;

typedef std::map<char, pixel_font_info> font_char_locations; 
typedef std::pair<char, pixel_font_info> font_char_location;


typedef std::map<unsigned int, pixel_sprite_info> sprite_quad_locations;
typedef std::map<std::string, sprite_quad_locations> animation_name_location_map;


#endif /* VECTOR_TYPES_H */