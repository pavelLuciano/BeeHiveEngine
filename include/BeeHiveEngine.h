#ifndef _BEE_HIVE_ENGINE_H_
#define _BEE_HIVE_ENGINE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>


namespace BeeHive
{
    //Elementos que se encargan de valores globales generales
    //TODO: ¿Sera necesario modificarlo a una infraestructura Singleton?
    class Clock
    {
    public:
        double lastFrame;
        double currentFrame;

        double deltaTime();
        void tick();
    } clock;
    class Window
    {
    public:
        int width;
        int height;
        GLFWwindow* self;

    } window;
    class Input
    {

    } inputHandler;

    //Funciones que manejan el motor 
    bool Init();
    void Terminate();
    void UpdateFrame();

};

#endif