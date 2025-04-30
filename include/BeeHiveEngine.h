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
        static double lastFrame;
        static double currentFrame;

        static double deltaTime();
        static void tick();
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
    void Terminate();
    void UpdateFrame();
};

#endif