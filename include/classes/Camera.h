#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <Entity.h>
#include <glm/glm.hpp>
#include <Transform.h>

enum Projection
{
    PERSPECTIVE,
    ORTHOGRAPHIC
};
class Camera: Entity
{
public:
    Transform* transform;
    Projection projection;
    float FOV;

    glm::vec3 up;
    glm::vec3 front;

    Camera();
    ~Camera();

    glm::mat4 getProjection();
    glm::mat4 getView();
    void setProjection(Projection);
    void setFOV(float);

};
#endif