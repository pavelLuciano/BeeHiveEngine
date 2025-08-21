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
glm::vec2 BeeHive::Input::Mouse::lastPos = {0.0f, 0.0f};
glm::vec2 BeeHive::Input::Mouse::offset  = {0.0f, 0.0f}; 
bool BeeHive::Input::Mouse::firstMouse   = true;
bool BeeHive::Input::Mouse::newOffset    = false;
void BeeHive::Input::Mouse::updateOffset()
{
    if (!newOffset)
    {
        BeeHive::Input::Mouse::offset = {0.0f, 0.0f};
        newOffset = false;
    }
}
void BeeHive::Input::Mouse::mouseCallback(GLFWwindow* _win, double xposIn, double yposIn)
{
    glm::vec2 newPos = {
        static_cast<float>(xposIn),
        static_cast<float>(yposIn)
    };
    if (firstMouse)
    {
        lastPos = newPos;
        firstMouse = false;
    }
    offset = newPos - lastPos;
    lastPos = newPos;
    newOffset = true;
}

//GRAPHIC
Shader BeeHive::Graphic::defaultShader;
Camera* BeeHive::Graphic::currentCamera = NULL;
std::unordered_map<Shader*, std::vector<std::shared_ptr<IDrawable>>> BeeHive::Graphic::drawable_map{};
void BeeHive::Graphic::drawIDrawables()
{
    for(auto [shader, drawables]: drawable_map)
    {
        shader->use();
        shader->setCamera(BeeHive::Graphic::currentCamera);
        for (auto& drawable: drawables) drawable->draw(*shader);
    }
}
void BeeHive::Graphic::setCurrentCamera(Camera* cam_)
{
    BeeHive::Graphic::currentCamera = cam_;
}

//ENGINE
std::vector<Entity_ptr> BeeHive::Engine::entity_list{};
void BeeHive::Engine::updateEntities()
{
    for (auto& e: entity_list) e->update();
}

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
    
    Input::Mouse::updateOffset();

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
    Engine::updateEntities();
    Graphic::drawIDrawables();
    glfwGetFramebufferSize(Window::window, &Window::frameBufferSizeWidth, &Window::frameBufferSizeHeight);
    glViewport(0, 0, Window::frameBufferSizeWidth, Window::frameBufferSizeHeight);
    //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(Window::window);
}