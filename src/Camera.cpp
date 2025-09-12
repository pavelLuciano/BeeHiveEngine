#include <Camera.h>
#include <BeeHiveEngine.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
Camera::Camera()
{
    projection = PERSPECTIVE;
    FOV        = 60.0f;
    transform  = new Transform();

    transform->TranslateZTo(15.0f);
    std::cout <<"["<< entityID <<"] " << "Camera Creada" << std::endl;
}
Camera::~Camera()
{
    delete transform;
    std::cout <<"["<< entityID <<"] " << "Camera Destruida" << std::endl;
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
    else return glm::perspective(glm::radians(FOV),
                                 (float) BeeHive::Window::frameBufferSizeWidth / (float) BeeHive::Window::frameBufferSizeHeight, 
                                 0.1f,
                                 100.0f);
}
glm::mat4 Camera::getView()
{
    return glm::lookAt(transform->pos, transform->pos - transform->getLocalZAxis(), glm::vec3(0.0f, 1.0f, 0.0f));
}
