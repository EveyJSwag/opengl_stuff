#include "camera.h"

camera::camera()
{
    camera_frustum = glm::vec4(-1.0, 1.0f, -1.0f, 1.0f);
    camera_position = glm::vec3(0.0f, 0.0f, 0.0f);
    projection = glm::ortho(
                    camera_frustum.x, 
                    camera_frustum.y, 
                    camera_frustum.z, 
                    camera_frustum.w, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), camera_position);
}

camera::camera(glm::vec3 initial_position)
{
    camera_frustum = glm::vec4(-1.0, 1.0f, -1.0f, 1.0f);
    camera_position = initial_position;
    projection = glm::ortho(
                    camera_frustum.x, 
                    camera_frustum.y, 
                    camera_frustum.z, 
                    camera_frustum.w, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), camera_position);
}

void camera::zoom_in(float zoom_factor)
{
    camera_frustum.x += zoom_factor;
    camera_frustum.y -= zoom_factor;
    camera_frustum.z += zoom_factor;
    camera_frustum.w -= zoom_factor;
}

void camera::zoom_out(float zoom_factor)
{
    camera_frustum.x -= zoom_factor;
    camera_frustum.y += zoom_factor;
    camera_frustum.z -= zoom_factor;
    camera_frustum.w += zoom_factor;
}

void camera::display()
{
    calculate();
}

void camera::move_camera(glm::vec3 shift_amt)
{
    camera_position.x += (-1.0f * shift_amt.x);
    camera_position.y += shift_amt.y;
}

void camera::calculate()
{
    projection = glm::ortho(
                    camera_frustum.x, 
                    camera_frustum.y, 
                    camera_frustum.z, 
                    camera_frustum.w, -1.0f, 1.0f);
    view =  glm::translate(glm::mat4(1.0f), camera_position);
}

glm::mat4 camera::get_mvp()
{
    return projection * view;
}


