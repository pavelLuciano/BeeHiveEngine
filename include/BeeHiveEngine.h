#ifndef _BEE_HIVE_ENGINE_H_
#define _BEE_HIVE_ENGINE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>
#include <implot.h>

#include <Camera.h>
#include <Shader.h>

#define DEFAULT_FRAGMENT_SHADER "./resources/shaders/defaultFragment.glsl"
#define DEFAULT_VERTEX_SHADER   "./resources/shaders/defaultVertex.glsl"

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
        static int frameBufferSizeWidth;
        static int frameBufferSizeHeight;
        static GLFWwindow* window;
    };
    
    class Input
    {

    };

    class Graphic
    {
    public:
        static Shader defaultShader;
    };

    class Engine
    {
    public:
        static std::vector<Entity*> entity_list;
    };
    
    
    //Funciones que manejan el motor 
    bool Init();
    bool Terminate();
    void NewFrame();
    void Render();

    void addEntity(Entity*);
    void addEntity(Entity&);

    //
    // WINDOWS
    //
    void engineUI();
    void enityInspector();
    
};

#endif