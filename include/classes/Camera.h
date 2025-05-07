#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <Entity.h>
#include <glm/glm.hpp>

enum Projection
{
    PERSPECTIVE,
    ORTHOGRAPHIC
};
class Camera: Entity
{
public:
    Projection projection;

    Camera();
    ~Camera();

    glm::mat4 getPojection();
    glm::mat4 getView();


};
#endif