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
#include <Prop.h>
#include <IDrawable.h>

#include <unordered_map>
#include <memory>

using Prop_sptr   = std::shared_ptr<Prop>;
using Entity_sptr = std::shared_ptr<Entity>;

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

        Window()                         = delete;
        Window(const Window&)            = delete;
        Window(Window&&)                 = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&)      = delete;
    };
    
    class Input
    {

    };

    class Graphic
    {
    public:
        Graphic()                          = delete;
        Graphic(const Graphic&)            = delete;
        Graphic(Graphic&&)                 = delete;
        Graphic& operator=(const Graphic&) = delete;
        Graphic& operator=(Graphic&&)      = delete;

        static Shader defaultShader;
        static std::unordered_map<Shader*, std::vector<std::shared_ptr<IDrawable>>> drawable_map;
        static void drawIDrawables();
    };

    class Engine
    {
    public:
        static std::vector<std::shared_ptr<Entity>> entity_list;
        static void updateEntities();
    };
    
    
    //Funciones que manejan el motor 
    bool Init();
    bool Terminate();
    void NewFrame();
    void Render();

    template <typename T, typename... Args>
    std::shared_ptr<T> createEntity(Args&&... args)
    {
        static_assert(std::is_base_of_v<Entity, T>, "Create Entity solo puede crear instancias de \"Entity\" o heredadas");
        // Buscar si alguno de los argumentos es un Shader
        Shader* shader = &Graphic::defaultShader;
        ([&] {
            if constexpr (std::is_same_v<std::decay_t<Args>, Shader*>) {
                shader = args;
            }
        }(), ...); // fold expression
        
        auto newEntity = std::make_shared<T>(std::forward<Args>(args)...);
        if constexpr(std::is_base_of_v<IDrawable, T>)
        {
            Graphic::drawable_map[shader].push_back(std::static_pointer_cast<IDrawable>(newEntity));
        }
        Engine::entity_list.push_back(std::static_pointer_cast<Entity>(newEntity));
        return newEntity;
    }
    
    //
    // WINDOWS
    //
    void engineUI();
    void enityInspector();
    
};

#endif