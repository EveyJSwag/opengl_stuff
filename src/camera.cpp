#include "camera.h"

camera::camera()
{
    camera_frustum = glm::vec4(-1.0, 1.0f, -1.0f, 1.0f);
    camera_postion = glm::vec3(0.0f, 0.0f, 0.0f);
    projection = glm::ortho(
                    camera_frustum.x, 
                    camera_frustum.y, 
                    camera_frustum.z, 
                    camera_frustum.w, -1.0f, 1.0f);
    view = glm::translate(glm::mat4(1.0f), camera_postion);
}

void camera::zoom_in(glm::vec4 zoom_factor)
{
    camera_frustum -= zoom_factor;
}

void camera::zoom_out(glm::vec4 zoom_factor)
{
    camera_frustum += zoom_factor;
}

void camera::display()
{
    calculate();
}

void camera::move_camera(glm::vec3 shift_amt)
{
    camera_postion.x += (-1.0f * shift_amt.x);
    camera_postion.y += shift_amt.y;
}

void camera::calculate()
{
    projection = glm::ortho(
                    camera_frustum.x, 
                    camera_frustum.y, 
                    camera_frustum.z, 
                    camera_frustum.w, -1.0f, 1.0f);
    view =  glm::translate(glm::mat4(1.0f), camera_postion);
}

glm::mat4 camera::get_mvp()
{
    return projection * view;
}
