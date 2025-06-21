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
    //Prop myProp("./resources/assets/models/Vivi/0044_player05out.obj");
    Camera myCamera;
    float aux = 0.0f;

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



    Model mod(PENGUIN);

    std::cout << mod.meshes.size() << std::endl;
    std::cout << mod.texturesLoaded.size() << std::endl;

    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        aux+= 0.05f;
        BeeHive::NewFrame();
        BeeHive::Graphic::defaultShader.use();
        BeeHive::Graphic::defaultShader.setCamera(myCamera);
        glm::mat4 miMat(1.0f);
        miMat = glm::translate(miMat, glm::vec3(0,-3,0));
        //miMat = glm::rotate(miMat, (float)M_PI , glm::vec3(1,0,0));
        miMat = glm::rotate(miMat, aux, glm::vec3(0,1,0));
        miMat = glm::scale(miMat, glm::vec3(5.0f, 5.0f, 5.0f));
        BeeHive::Graphic::defaultShader.setMat4("model", miMat);
        //mymesh.draw(BeeHive::Graphic::defaultShader);
        mod.draw(BeeHive::Graphic::defaultShader);
        BeeHive::Render();
    }
    BeeHive::Terminate();
}