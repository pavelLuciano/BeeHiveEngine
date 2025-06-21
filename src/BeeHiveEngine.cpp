#include <BeeHiveEngine.h>
#include <iostream>

//CLOCK
double BeeHive::Clock::lastFrame    = 0;
double BeeHive::Clock::currentFrame = 0;
double BeeHive::Clock::deltaTime()
{
    return currentFrame - lastFrame;
}
void BeeHive::Clock::tick()
{
    lastFrame = currentFrame;
    currentFrame = glfwGetTime();
}

//WINDOW
int BeeHive::Window::width                 = 800;
int BeeHive::Window::height                = 600;
int BeeHive::Window::frameBufferSizeWidth  = 0;
int BeeHive::Window::frameBufferSizeHeight = 0;
GLFWwindow* BeeHive::Window::window = NULL;

//INPUT

//GRAPHIC
Shader BeeHive::Graphic::defaultShader;

//Funciones generales
bool BeeHive::Init()
{ 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    Window::window = glfwCreateWindow(Window::width, Window::height, "BeeHive", nullptr, nullptr);
    if (!Window::window)
    {
        std::cerr << "Error al crear la ventana\n";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(Window::window);
    glfwSwapInterval(1);
    //glfwSetFramebufferSizeCallback(window.self, framebuffer_size_callback);
    //glfwSetCursorPosCallback(window.self, mouse_callback);
    //glfwSetScrollCallback(window.self, scroll_callback);
    // tell GLFW to capture our mouse
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    //glewExperimental = GL_TRUE; // no se para que sirve esta linea
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Error al inicializar GLEW\n";
        return false;
    }
    
    glfwGetFramebufferSize(Window::window, &Window::frameBufferSizeWidth, &Window::frameBufferSizeHeight);
    glViewport(0, 0, Window::frameBufferSizeWidth, Window::frameBufferSizeHeight);
    std::cout << "OpenGL iniciado correctamente\nVersion: " << glGetString(GL_VERSION) << std::endl;
    glEnable(GL_DEPTH_TEST);


    //
    // BEEHIVE ENGINE
    //
    Graphic::defaultShader.loadFile(DEFAULT_VERTEX_SHADER, DEFAULT_FRAGMENT_SHADER);
    //
    // IMGUI & IMPLOT
    //
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // IF using Multi-Viewport (?)

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(Window::window, true);
    ImGui_ImplOpenGL3_Init();


    //std::cout << Window::window << std::endl;

    return true;
}
bool BeeHive::Terminate()
{
    glDeleteProgram(Graphic::defaultShader.id);
    /*ImPlot::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();*/
    glfwDestroyWindow(Window::window);
    glfwTerminate();
    return true;
}
void BeeHive::NewFrame()
{
    Clock::tick();
    glfwPollEvents();

    glClearColor(0.0f, 0.2f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*
    if (glfwGetWindowAttrib(BeeHive::Window::window, GLFW_ICONIFIED) != 0)
    {
        ImGui_ImplGlfw_Sleep(10);
        continue;
    }*/
}

void BeeHive::Render()
{
    //ImGui::Render();
    glfwGetFramebufferSize(Window::window, &Window::frameBufferSizeWidth, &Window::frameBufferSizeHeight);
    glViewport(0, 0, Window::frameBufferSizeWidth, Window::frameBufferSizeHeight);
    //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(Window::window);
}