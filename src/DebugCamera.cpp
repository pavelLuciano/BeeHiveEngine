#include "DebugCamera.h"
#include "BeeHiveEngine.h"

void DebugCamera::update()
{
    //void MyCamera::processInput(GLFWwindow* window,float deltaTime)

    glm::vec3 direction = glm::vec3(0.0f);
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_W) == GLFW_PRESS)
        direction += glm::vec3(0.0f, 0.0f, -1.0f); 
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_S) == GLFW_PRESS)
        direction += glm::vec3(0.0f, 0.0f, 1.0f); 
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_A) == GLFW_PRESS)
        direction += glm::vec3(-1.0f, 0.0f, 0.0f); 
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_D) == GLFW_PRESS)
        direction += glm::vec3(1.0f, 0.0f, 0.0f); 
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_Q) == GLFW_PRESS)
        direction += glm::vec3(0.0f, 1.0f, 0.0f); 
    if (glfwGetKey(BeeHive::Window::window, GLFW_KEY_E) == GLFW_PRESS)
        direction -= glm::vec3(0.0f, 1.0f, 0.0f); 

    if (direction != glm::vec3(0.0f))
    {
        direction = glm::normalize(direction);
        glm::vec3 translation = (float)BeeHive::Clock::deltaTime() * 5.0f * direction;
        transform->TranslateTo(translation);
    }

    
}