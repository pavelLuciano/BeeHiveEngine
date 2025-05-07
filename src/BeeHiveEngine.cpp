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
int BeeHive::Window::width          = 800;
int BeeHive::Window::height         = 600;
GLFWwindow* BeeHive::Window::window = nullptr;

//INPUT

//Funciones generales
bool BeeHive::Init()
{
    // GLFW & GLEW
    if (!glfwInit())
    {
        std::cerr << "ERROR::NO_SE_PUDO_INICIAR_GLFW" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    Window::window = glfwCreateWindow(Window::width, Window::height, "BeeHive", NULL, NULL);
    if (!Window::window)
    {
        std::cerr << "No se pudo crear la ventana" << std::endl;
        glfwTerminate();
        return false;
    };
    glfwMakeContextCurrent(Window::window);
    glfwSwapInterval(1);
    //glfwSetFramebufferSizeCallback(window.self, framebuffer_size_callback);
    //glfwSetCursorPosCallback(window.self, mouse_callback);
    //glfwSetScrollCallback(window.self, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    
    if (glewInit() != GLEW_OK) 
    {
        std::cerr << "ERROR::NO_SE_PUDO_INICIAR_GLEW" << std::endl;
        glfwTerminate();
        return false;
    }
    glViewport(0, 0, Window::width, Window::height);
    std::cout << "OpenGL iniciado correctamente\nVersion: " << glGetString(GL_VERSION) << std::endl;
    glEnable(GL_DEPTH_TEST);

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
}

bool BeeHive::Terminate()
{
    ImPlot::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(Window::window);
    glfwTerminate();
}