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
    Prop myProp(PENGUIN);
    Camera myCamera;
    float aux = 0.05f;

    std::vector<Vertex> vert =
    {
        {glm::vec3( 0.0f,  0.5f,  0.0f) ,glm::vec3(1.0f), glm::vec2(1.0f), glm::vec3(1.0f), glm::vec3(1.0f), {0,0,0,0}, {0.0f, 0.0f, 0.0f, 0.0f}},
        {glm::vec3( 0.5f, -0.5f,  0.5f) ,glm::vec3(1.0f), glm::vec2(1.0f), glm::vec3(1.0f), glm::vec3(1.0f), {0,0,0,0}, {0.0f, 0.0f, 0.0f, 0.0f}},
        {glm::vec3(-0.5f, -0.5f,  0.5f) ,glm::vec3(1.0f), glm::vec2(1.0f), glm::vec3(1.0f), glm::vec3(1.0f), {0,0,0,0}, {0.0f, 0.0f, 0.0f, 0.0f}},
        {glm::vec3(-0.5f, -0.5f, -0.5f) ,glm::vec3(1.0f), glm::vec2(1.0f), glm::vec3(1.0f), glm::vec3(1.0f), {0,0,0,0}, {0.0f, 0.0f, 0.0f, 0.0f}},
        {glm::vec3( 0.5f, -0.5f, -0.5f) ,glm::vec3(1.0f), glm::vec2(1.0f), glm::vec3(1.0f), glm::vec3(1.0f), {0,0,0,0}, {0.0f, 0.0f, 0.0f, 0.0f}}    
    };
    std::vector<unsigned int> ind =
    {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 1,
        1, 2, 3,
        3, 4, 1
    };
    std::vector<Texture> tex = {};
    Mesh mymesh( vert, ind, tex );


    myProp.transform->TranslateTo(glm::vec3(0,-4,0));
    myProp.transform->scaleAll(glm::vec3(10.0f, 10.0f, 10.0f));

    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        BeeHive::NewFrame();
        BeeHive::Graphic::defaultShader.use();
        BeeHive::Graphic::defaultShader.setCamera(myCamera);
        myProp.transform->eulerRotateY_Global(aux);
        myProp.draw(BeeHive::Graphic::defaultShader);
        BeeHive::Render();
    }
    BeeHive::Terminate();
}