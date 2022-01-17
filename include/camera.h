#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
class camera
{
public:
    camera();
    camera(glm::vec3 initial_position);
    void zoom_in(float zoom_factor);
    void zoom_out(float zoom_factor);
    glm::mat4 get_mvp();
    void move_camera(glm::vec3 shift_amt);
    void display();
    glm::vec3 get_position() const {return camera_position;}
private:

    glm::vec3 camera_position;
    glm::vec4 camera_frustum;
    void reset_zoom_factor();
    void calculate();
    glm::mat4 projection;
    glm::mat4 view;

};


#endif /* CAMERA_H */