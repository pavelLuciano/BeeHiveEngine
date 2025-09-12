#include <BeeHiveEngine.h>
#include <GameMaster.h>
int main()
{
    BeeHive::Init();
    //
    GameMaster game;
    DebugCamera miCam;
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