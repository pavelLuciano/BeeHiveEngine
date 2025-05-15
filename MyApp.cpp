#include <iostream>
#include <BeeHiveEngine.h>
#include <Prop.h>
#include <Camera.h>

int main(int argc, char** argv)
{
    BeeHive::Init();
    Prop myProp("./resources/assets/models/box.shape");
    Camera myCamera;
    float aux = 0.0f;

    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        aux += 0.01f;
        BeeHive::NewFrame();
        BeeHive::Graphic::defaultShader.use();
        BeeHive::Graphic::defaultShader.setCamera(myCamera);
        myProp.transform->rotation.head = aux;
        myProp.draw();
        BeeHive::Render();
    }
    BeeHive::Terminate();
}