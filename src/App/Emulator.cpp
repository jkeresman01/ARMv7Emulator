#include "Emulator.h"

#include <string>
#include <vector>

#include "../Util/ColorsUtil.h"
#include "../Util/RandomUtil.h"

namespace emulator6502
{

void Emulator6502::Init()
{
    InitComponents();
    glfwInit();
    InitWindow();
    glfwMakeContextCurrent(m_Window);
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init();
}

void Emulator6502::InitComponents()
{
    Random::Init();
    //m_CPU->Init();
    m_AsmEditor->Init();
    m_MemoryLayout->Init();
    m_PixelDisplay->Init();
    m_HEXDisplay->Init();
    m_LEDs->Init();
    m_SwitchPanel->Init();
}

void Emulator6502::InitWindow()
{
    GLFWmonitor *primary = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(primary);
    m_Window = glfwCreateWindow(mode->width, mode->height, "6502 Emulator", NULL, NULL);
}

void Emulator6502::Run()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        Render();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_Window);
    }
}

void Emulator6502::Render()
{
    RenderComponents();
    RenderCPUStatusWindow();
    RenderDissasemblyPopup();
    RenderControlButtonsWindow();
}

void Emulator6502::RenderCPUStatusWindow()
{
    ImGui::Begin("CPU Registers");

    // TODO: Add status flags

    ImGui::End();
}

void Emulator6502::RenderComponents()
{
    m_AsmEditor->Render();
    m_PixelDisplay->Render();
    m_MemoryLayout->Render();
    m_HEXDisplay->Render();
    m_LEDs->Render();
    m_SwitchPanel->Render();
}

void Emulator6502::RenderControlButtonsWindow()
{
    ImGui::Begin("Controls");

    if (ImGui::Button("Assemble"))
    {
        // TODO
    }

    ImGui::SameLine();
    if (ImGui::Button("Disassemble"))
    {
        //OpenDissasemblyPopup();
    }

    ImGui::SameLine();
    if (ImGui::Button("Run"))
    {
        // TODO: Execution
    }

    ImGui::SameLine();
    if (ImGui::Button("Reset"))
    {
        // TODO
    }

    ImGui::SameLine();
    if (ImGui::Button("Step"))
    {
        //m_CPU->Step();
    }

    ImGui::End();
}

void Emulator6502::OpenDissasemblyPopup()
{

}

void Emulator6502::LoadProgramIntoMemory()
{
}

void Emulator6502::Shutdown()
{
    DestroyComponents();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Emulator6502::DestroyComponents()
{
    m_AsmEditor->Destroy();
    m_PixelDisplay->Destroy();
    m_MemoryLayout->Destroy();
    m_HEXDisplay->Destroy();
    m_LEDs->Destroy();
    m_SwitchPanel->Destroy();
}

} // namespace emulator6502
