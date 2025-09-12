#include <iostream>
#include <BeeHiveEngine.h>
#include <Prop.h>
#include <Camera.h>
#include <Model.h>

#include <glm/gtc/matrix_transform.hpp>

#define BACKPACK "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/backpack/backpack.obj"
#define VIVI "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/Vivi/0044_player05out.dae"
#define PENGUIN "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/Penguin/Penguin.obj"
#define CHERCAN "/home/pavel/Dev/BeeHiveEngine/resources/assets/models/chercan_v01/low_poly_model_(compress).obj"

int main(int argc, char** argv)
{
    BeeHive::Init();
    auto miProp = BeeHive::createEntity<Prop>(PENGUIN);
    BeeHive::Graphic::bindShader(miProp);
    
    Camera myCamera;
    BeeHive::Graphic::setCurrentCamera(&myCamera);
    float aux = 5.0f;
    //miProp->transform->TranslateYTo(-7.0f);
    //miProp->transform->eulerRotateX_Global(3.14f);
    miProp->transform->scaleAll({3.0f, 3.0f, 3.0f});
    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        BeeHive::NewFrame();
        miProp->transform->rotateY_Local(aux);
        BeeHive::Render();
    }
    BeeHive::Terminate();
}