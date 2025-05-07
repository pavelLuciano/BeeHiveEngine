#ifndef _BEE_HIVE_ENGINE_H_
#define _BEE_HIVE_ENGINE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>
#include <implot.h>

namespace BeeHive
{
    //Elementos que se encargan de valores globales generales
    //TODO: ¿Sera necesario modificarlo a una infraestructura Singleton?
    class Clock
    {
    public:
        static double deltaTime();
        static void tick();

        Clock()                        = delete;
        Clock(const Clock&)            = delete;
        Clock(Clock&&)                 = delete;
        Clock& operator=(const Clock&) = delete;
        Clock& operator=(Clock&&)      = delete;
    private:
        static double lastFrame;
        static double currentFrame;
    };
    class Window
    {
    public:
        static int width;
        static int height;
        static GLFWwindow* window;
    };
    
    class Input
    {

    };

    //Funciones que manejan el motor 
    bool Init();
    bool Terminate();
    void NewFrame();
    void Render();
};

#endif