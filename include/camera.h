#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
class camera
{
public:
    camera();
private:
    glm::vec3 postion;
    void zoom();
    glm::mat4 get_mvp();

};


#endif /* CAMERA_H */