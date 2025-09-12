#ifndef _BEE_HIVE_ENGINE_H_
#define _BEE_HIVE_ENGINE_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <imgui.h>
#include <implot.h>

#include <Camera.h>
#include <DebugCamera.h>
#include <Shader.h>
#include <Prop.h>
#include <IDrawable.h>

#include <unordered_map>
#include <memory>

using Prop_ptr   = std::shared_ptr<Prop>;
using Entity_ptr = std::shared_ptr<Entity>;
using Camera_ptr = std::shared_ptr<Camera>;
using Shader_ptr = std::shared_ptr<Shader>;

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
    public:
        class Mouse
        {
        public:
            static glm::vec2 lastPos;
            static glm::vec2 offset;
            static bool firstMouse;
            static bool newOffset;
            static bool isLeftButton_Pressed;
            static bool isRightButton_Pressed;

            static void mouseCallback(GLFWwindow*, double, double);
            static void mouseButtonCallback(GLFWwindow*, int, int, int);
            static void updateOffset();
        };
    };

    class Graphic
    {
    public:
        Graphic()                          = delete;
        Graphic(const Graphic&)            = delete;
        Graphic(Graphic&&)                 = delete;
        Graphic& operator=(const Graphic&) = delete;
        Graphic& operator=(Graphic&&)      = delete;

        static Camera* currentCamera;
        static Shader defaultShader;
        static std::unordered_map<Shader*, std::vector<std::shared_ptr<IDrawable>>> drawable_map;
        static void drawIDrawables();
        static void setCurrentCamera(Camera*);
        template <typename T>
        static void bindShader(std::shared_ptr<T> entity, Shader* shader = &defaultShader) {
            if constexpr (std::is_base_of_v<IDrawable, T>)
                Graphic::drawable_map[shader].push_back(std::static_pointer_cast<IDrawable>(entity));
        }
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
        auto newEntity = std::make_shared<T>(std::forward<Args>(args)...);
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