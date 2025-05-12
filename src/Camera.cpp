#include <Camera.h>
#include <glm/gtc/matrix_transform.hpp>
Camera::Camera()
{
    projection = PERSPECTIVE;
    FOV = 60.0f;
    transform = new Transform();
}
Camera::~Camera()
{
    delete transform;
}
void Camera::setProjection(Projection _projection)
{
    projection = _projection;
}
void Camera::setFOV(float _fov)
{
    FOV = _fov;
}
glm::mat4 Camera::getProjection()
{
    //TODO: ajustar las medidas del viewport
    if (projection == ORTHOGRAPHIC) return glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
    else return glm::perspective(glm::radians(FOV), 600.0f / 600.0f, 0.1f, 100.0f);
}
glm::mat4 Camera::getView()
{
    return glm::lookAt(transform->pos, glm::vec3(0,0,0), glm::vec3(0,1,0));
}
