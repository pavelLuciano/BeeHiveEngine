#include <iostream>
#include <BeeHiveEngine.h>
#include <Prop.h>
#include <Camera.h>

int main(int argc, char** argv)
{
    BeeHive::Init();
    Prop prop("./resources/assets/models/box.shape");
    Camera camera;



    while(!glfwWindowShouldClose(BeeHive::Window::window))
    {
        BeeHive::NewFrame();

        BeeHive::Graphic::defaultShader.use();

        //prop.draw(BeeHive::Graphic::defaultShader);
        BeeHive::Render();
    }
    BeeHive::Terminate();
}

/*
int main (int argc, char* argv[])
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImPlot Demo", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // vsync

    // Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext(); // <- Inicializa ImPlot

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //Mostrar Demo IMGUI
        //ImGui::ShowDemoWindow();
        // Mostrar demo
        //ImGui::Begin("ImPlot Demo");
        //ImPlot::ShowDemoWindow();
        //ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Limpieza
    ImPlot::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}*/

