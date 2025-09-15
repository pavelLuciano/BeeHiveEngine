#include <BeeHiveEngine.h>
#include <GameMaster.h>
int main()
{
    BeeHive::Init();
    //
    GameMaster game;
    DebugCamera miCam;
    miCam.transform->TranslateTo({0.0f, 15.0f, 0.0f});
    miCam.transform->rotateX_Local(-90.0f);
    BeeHive::Graphic::setCurrentCamera(&miCam);
    game.startGame();

    //
    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        BeeHive::NewFrame();
        ///
        







        ///
        miCam.update();
        
        BeeHive::Render();
    }
    game.endGame();
    BeeHive::Terminate();
    
}