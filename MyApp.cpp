#include <iostream>
#include <BeeHiveEngine.h>
#include <Prop.h>
#include <Camera.h>
#include <Model.h>

#include <glm/gtc/matrix_transform.hpp>

#define BACKPACK "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/backpack/backpack.obj"
#define VIVI "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/Vivi/0044_player05out.dae"
#define PENGUIN "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/Penguin/Penguin.obj"

int main(int argc, char** argv)
{
    BeeHive::Init();
    auto miProp = BeeHive::createEntity<Prop>(VIVI);

    
    Camera myCamera;
    float aux = 0.05f;

    std::cout << "HOLA\n";
    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        BeeHive::NewFrame();
        BeeHive::Graphic::defaultShader.use();
        BeeHive::Graphic::defaultShader.setCamera(myCamera);
        miProp->transform->eulerRotateY_Global(aux);
        BeeHive::Render();
    }
    BeeHive::Terminate();
}