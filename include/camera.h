#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
class camera
{
public:
    camera();

    void zoom_in(glm::vec4 zoom_factor);
    void zoom_out(glm::vec4 zoom_factor);
    glm::mat4 get_mvp();
    void move_camera(glm::vec3 shift_amt);
    void display();
private:

    glm::vec3 camera_postion;
    glm::vec4 camera_frustum;
    void reset_zoom_factor();
    void calculate();
    glm::mat4 projection;
    glm::mat4 view;

};


#endif /* CAMERA_H */