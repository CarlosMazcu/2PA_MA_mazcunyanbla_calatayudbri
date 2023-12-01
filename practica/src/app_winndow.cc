/**
 * @file window_class.cc
 * @author 
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "app_window.h"
/* #include "gsprite.h" */
#include "esat/time.h"
#include "esat/input.h"
#include "stdio.h"



void windowManager(int n)
{
    GameManager &GM = GameManager::Instance();
    switch (n)
    {
    case 0:
      GM.window_bool.welcome = true;
      GM.window_bool.credits = false;
      GM.window_bool.exit = false;
      GM.window_bool.parallax = false;
      GM.window_bool.transform = false;
      break;
    case 1:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = true;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = false;
        break;
    case 2:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = false;
        GM.window_bool.parallax = true;
        GM.window_bool.transform = false;
        break;
    case 3:
        GM.window_bool.welcome = false;
        GM.window_bool.credits = false;
        GM.window_bool.parallax = false;
        GM.window_bool.transform = true;
        break;
    default:
        break;
    }
}

void MainMenuBar()
{
  GameManager &GM = GameManager::Instance();
  static bool one_time = true;
  if(ImGui::BeginMainMenuBar()) 
  {
    for(float i = 0; i < 12; i++)
    {
      ImGui::Text(" ");
    }
    if (ImGui::BeginMenu("Theme"))
    {
        if(ImGui::Button("BoringDefault", ImVec2(100.0f, 20.0f)))
        {
          if(one_time = true)
          {
            themeBoring();
            one_time = false;
          }
        }
        if(ImGui::Button("DarkPurple", ImVec2(100.0f, 20.0f)))
        {
          if(one_time = true)
          {
            themePurple();
            one_time = false;
          }
        }
        if(ImGui::Button("LemonPie", ImVec2(100.0f, 20.0f)))
        {
          if(one_time = true)
          {
            themeLemonPie();
            one_time = false;
          }
        }
        if(ImGui::Button("B & W", ImVec2(100.0f, 20.0f)))
        {
          if(one_time = true)
          {
            themeBW();
            one_time = false;
          }
        }
        if(ImGui::Button("ESATtheme", ImVec2(100.0f, 20.0f)))
        {
          if(one_time = true)
          {
            darkTaronja();
            one_time = false;
          }
        }
        if (ImGui::Button("AkuaMarine", ImVec2(100.0f, 20.0f)))
        {
          if (one_time = true)
          {
            aquamarineTheme();
            one_time = false;
          }
        }
        if (ImGui::Button("HiBarbie", ImVec2(100.0f, 20.0f)))
        {
          if (one_time = true)
          {
            hiBarbieTheme();
            one_time = false;
          }
        }
        one_time = true;
        ImGui::EndMenu();
    }
    ImGui::Text("|");
    if(ImGui::BeginMenu("Settings Info"))
    {
      if(ImGui::BeginMenu("Resolution")){
          ImGui::Text("%d x %d", (int)GM.windowSize.x, (int)GM.windowSize.y);
          ImGui::EndMenu();
      }
      if(ImGui::BeginMenu("Fps")){
        float framerate = ImGui::GetIO().Framerate / 100.0f;
          ImGui::Text("%0.2f", framerate);
          ImGui::EndMenu();
      }
      
      
      ImGui::EndMenu();
    } 
    ImGui::Text("|");
    if (ImGui::BeginMenu("Contact"))
    {
        if (ImGui::BeginMenu("Lucas Calatayud"))
        {
            ImGui::Text("calatayudbri@esat-alumni.com");
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Carlos Mazcunan"))
        {
            ImGui::Text("mazcunyanbla@esat-alumni.com");
            ImGui::EndMenu();
        }
        ImGui::EndMenu();
    }
  ImGui::EndMainMenuBar();
  }
}

void welcomeWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(300, 400));
    ImGui::SetNextWindowPos(ImVec2(160, 200));

    ImGui::Begin("WELCOME", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);

    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
    if (ImGui::Button("Animation", ImVec2(100.0f, 20.0f)))
    {
      initAllEntityParallax();
      windowManager(2);

    }
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::SameLine(0.0f, 90.0f);
  
    if (ImGui::Button("Credits", ImVec2(100.0f, 20.0f)))
    {
        windowManager(1);
        // GM.credits = true;
    }
    for (int i = 0; i < 30; i++)
    {
        ImGui::Spacing();
    }
    ImGui::SameLine(0.0f, 90.0f);

    if (ImGui::Button("Exit", ImVec2(100.0f, 20.0f)))
    {
      GM.window_bool.exit = true;
    }
    ImGui::End();
}

void creditsWindow()
{
    GameManager &GM = GameManager::Instance();
    ImGui::SetNextWindowSize(ImVec2(230, 200));
    ImGui::SetNextWindowPos(ImVec2(205,100));
    ImGui::Begin("CREDITS", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize 
                | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

    ImGui::Text("ESAT Academic Project");
    ImGui::Text("made by: ");
    ImGui::Spacing();
    ImGui::Text("Lucas Calatayud");
    ImGui::Spacing();

    ImGui::Text("<calatayudbri@esat-alumni.com>");
    ImGui::Spacing();
    ImGui::Text("Carlos Mazcuñan");
    ImGui::Spacing();
    ImGui::Text("<mazcunyanbla@esat-alumni.com>");
    for (int i = 0; i < 12; i++)
    {
      ImGui::Spacing();
    }
    ImGui::SameLine(0.0f, 55.0f);
    if (ImGui::Button("Return", ImVec2(100.0f, 20.0f)))
    {
       windowManager(0);
    }
    ImGui::End();
}

void parallaxWindow()
{
  GameManager &GM = GameManager::Instance();
  ImGui::SetNextWindowSize(ImVec2(300.0f, 40.0f));
  ImGui::SetNextWindowPos(ImVec2(5.0f, GM.windowSize.y - 50.0f));
  ImGui::Begin("PARALLAX", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground);
  if (ImGui::Button("Return", ImVec2(100.0f, 20.0f)))
  {
    windowManager(0);
  }
  ImGui::SameLine();
  ImGui::SliderFloat("slider float", &GM.incrSpeed_, 0.0f, 2.0f, "%.2f");
  ImGui::End();
  //input
  inputSpeed();
  // move parallax
  updateParallax();
  //draw
  drawParallax();
}

void stateMachine()
{
    GameManager &GM = GameManager::Instance();

    if (GM.window_bool.welcome)
    {
      welcomeWindow();
    }
    if(GM.window_bool.credits)
    {
      creditsWindow();
    }
    if(GM.window_bool.parallax)
    {
      parallaxWindow();
    }

}

void themeLemonPie()
{
ImVec4* colors = ImGui::GetStyle().Colors;
colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
colors[ImGuiCol_WindowBg]               = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.71f);
colors[ImGuiCol_PopupBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.55f);
colors[ImGuiCol_Border]                 = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_FrameBg]                = ImVec4(0.55f, 0.56f, 0.30f, 0.46f);
colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.83f, 0.83f, 0.83f, 0.40f);
colors[ImGuiCol_FrameBgActive]          = ImVec4(0.84f, 0.84f, 0.84f, 0.67f);
colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
colors[ImGuiCol_TitleBgActive]          = ImVec4(0.53f, 0.53f, 0.53f, 1.00f);
colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.43f, 0.98f, 0.97f, 0.14f);
colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
colors[ImGuiCol_CheckMark]              = ImVec4(0.60f, 0.87f, 0.19f, 1.00f);
colors[ImGuiCol_SliderGrab]             = ImVec4(0.68f, 0.87f, 0.00f, 1.00f);
colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.62f, 0.70f, 0.43f, 0.67f);
colors[ImGuiCol_Button]                 = ImVec4(0.67f, 0.77f, 0.42f, 0.59f);
colors[ImGuiCol_ButtonHovered]          = ImVec4(0.76f, 0.90f, 0.18f, 0.76f);
colors[ImGuiCol_ButtonActive]           = ImVec4(0.68f, 0.69f, 0.70f, 1.00f);
colors[ImGuiCol_Header]                 = ImVec4(0.92f, 1.00f, 0.38f, 0.27f);
colors[ImGuiCol_HeaderHovered]          = ImVec4(0.94f, 0.96f, 0.98f, 0.80f);
colors[ImGuiCol_HeaderActive]           = ImVec4(0.08f, 0.10f, 0.13f, 1.00f);
colors[ImGuiCol_Separator]              = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
colors[ImGuiCol_SeparatorHovered]       = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
colors[ImGuiCol_SeparatorActive]        = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_ResizeGrip]             = ImVec4(0.52f, 0.52f, 0.52f, 0.56f);
colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.70f, 0.70f, 0.70f, 0.92f);
colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.00f, 0.00f, 0.00f, 0.95f);
colors[ImGuiCol_Tab]                    = ImVec4(0.22f, 0.34f, 0.06f, 0.86f);
colors[ImGuiCol_TabHovered]             = ImVec4(0.09f, 0.09f, 0.09f, 0.80f);
colors[ImGuiCol_TabActive]              = ImVec4(0.24f, 0.32f, 0.25f, 1.00f);
colors[ImGuiCol_TabUnfocused]           = ImVec4(0.27f, 0.27f, 0.27f, 0.97f);
colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.67f, 0.68f, 0.69f, 1.00f);
colors[ImGuiCol_PlotLines]              = ImVec4(0.67f, 0.66f, 0.66f, 1.00f);
colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 1.00f, 0.99f, 1.00f);
colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
colors[ImGuiCol_TableRowBg]             = ImVec4(0.41f, 0.41f, 0.41f, 0.00f);
colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.92f, 0.93f, 0.94f, 0.35f);
colors[ImGuiCol_DragDropTarget]         = ImVec4(0.57f, 0.57f, 0.57f, 0.90f);
colors[ImGuiCol_NavHighlight]           = ImVec4(0.74f, 0.74f, 0.74f, 1.00f);
colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void themePurple(){
  ImVec4 *colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
  colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
  colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.76f, 0.07f, 0.96f, 0.28f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(0.69f, 0.40f, 0.71f, 0.45f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.77f, 0.25f, 0.64f, 0.40f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.32f, 0.31f, 0.32f, 0.60f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.32f, 0.32f, 0.32f, 0.60f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.32f, 0.31f, 0.32f, 0.60f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
  colors[ImGuiCol_CheckMark] = ImVec4(0.51f, 0.93f, 0.56f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(0.62f, 0.28f, 0.67f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.87f, 0.47f, 0.90f, 1.00f);
  colors[ImGuiCol_Button] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.38f, 0.19f, 0.43f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.57f, 0.39f, 0.62f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(0.02f, 0.02f, 0.02f, 0.00f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.33f, 0.03f, 0.32f, 0.77f);
  colors[ImGuiCol_HeaderActive] = ImVec4(0.43f, 0.02f, 0.45f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(0.68f, 0.35f, 0.76f, 1.00f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
  colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TabHovered] = ImVec4(0.49f, 0.03f, 0.52f, 0.80f);
  colors[ImGuiCol_TabActive] = ImVec4(0.65f, 0.20f, 0.68f, 1.00f);
  colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
  colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
  colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
  colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
  colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void themeBoring(){
  ImVec4* colors = ImGui::GetStyle().Colors;
colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_FrameBg]                = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
colors[ImGuiCol_FrameBgActive]          = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
colors[ImGuiCol_TitleBgActive]          = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
colors[ImGuiCol_Button]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
colors[ImGuiCol_ButtonActive]           = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
colors[ImGuiCol_Separator]              = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
colors[ImGuiCol_Tab]                    = ImVec4(0.18f, 0.35f, 0.58f, 0.86f);
colors[ImGuiCol_TabHovered]             = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.41f, 0.68f, 1.00f);
colors[ImGuiCol_TabUnfocused]           = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);


}

void darkTaronja()
{
  ImVec4 *colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(1.00f, 0.50f, 0.00f, 0.14f);
  colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.00f);
  colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.51f, 0.30f, 0.05f, 0.94f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 0.57f, 0.00f, 1.00f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(1.00f, 0.43f, 0.00f, 1.00f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.56f, 0.00f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.66f, 0.00f, 0.86f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.99f, 0.52f, 0.00f, 0.65f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.20f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.93f, 0.48f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 0.64f, 0.02f, 0.46f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.46f, 0.00f, 1.00f);
  colors[ImGuiCol_Button] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.33f, 0.00f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.98f, 0.49f, 0.06f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(0.87f, 0.52f, 0.07f, 0.31f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.97f, 0.71f, 0.00f, 0.11f);
  colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 0.63f, 0.00f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.97f, 0.59f, 0.98f, 0.20f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 1.00f, 0.98f, 0.67f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 0.46f, 1.00f, 0.95f);
  colors[ImGuiCol_Tab] = ImVec4(0.65f, 0.45f, 0.00f, 0.86f);
  colors[ImGuiCol_TabHovered] = ImVec4(0.92f, 0.68f, 0.03f, 0.32f);
  colors[ImGuiCol_TabActive] = ImVec4(1.00f, 0.50f, 0.00f, 1.00f);
  colors[ImGuiCol_TabUnfocused] = ImVec4(1.00f, 0.76f, 0.00f, 0.97f);
  colors[ImGuiCol_TabUnfocusedActive] = ImVec4(1.00f, 0.40f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
  colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
  colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
  colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void themeBW()
{
 ImVec4* colors = ImGui::GetStyle().Colors;
colors[ImGuiCol_Text]                   = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
colors[ImGuiCol_WindowBg]               = ImVec4(0.73f, 0.73f, 0.73f, 1.00f);
colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.29f);
colors[ImGuiCol_PopupBg]                = ImVec4(1.00f, 1.00f, 1.00f, 0.57f);
colors[ImGuiCol_Border]                 = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_BorderShadow]           = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
colors[ImGuiCol_FrameBg]                = ImVec4(1.00f, 1.00f, 1.00f, 0.54f);
colors[ImGuiCol_FrameBgHovered]         = ImVec4(1.00f, 1.00f, 1.00f, 0.40f);
colors[ImGuiCol_FrameBgActive]          = ImVec4(1.00f, 1.00f, 1.00f, 0.67f);
colors[ImGuiCol_TitleBg]                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_TitleBgActive]          = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(1.00f, 1.00f, 1.00f, 0.65f);
colors[ImGuiCol_MenuBarBg]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_ScrollbarGrab]          = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
colors[ImGuiCol_CheckMark]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_SliderGrab]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.62f, 0.62f, 0.62f, 1.00f);
colors[ImGuiCol_Button]                 = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_ButtonHovered]          = ImVec4(1.00f, 1.00f, 1.00f, 0.66f);
colors[ImGuiCol_ButtonActive]           = ImVec4(1.00f, 1.00f, 1.00f, 0.21f);
colors[ImGuiCol_Header]                 = ImVec4(1.00f, 1.00f, 1.00f, 0.33f);
colors[ImGuiCol_HeaderHovered]          = ImVec4(0.82f, 0.82f, 0.82f, 0.80f);
colors[ImGuiCol_HeaderActive]           = ImVec4(0.10f, 0.10f, 0.10f, 0.48f);
colors[ImGuiCol_Separator]              = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
colors[ImGuiCol_SeparatorHovered]       = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
colors[ImGuiCol_SeparatorActive]        = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_ResizeGrip]             = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.00f, 0.00f, 0.00f, 0.67f);
colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.00f, 0.00f, 0.00f, 0.95f);
colors[ImGuiCol_Tab]                    = ImVec4(0.76f, 0.76f, 0.76f, 0.86f);
colors[ImGuiCol_TabHovered]             = ImVec4(0.29f, 0.32f, 0.35f, 0.80f);
colors[ImGuiCol_TabActive]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_TabUnfocused]           = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
colors[ImGuiCol_PlotLines]              = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.00f, 0.00f, 0.00f, 0.35f);
colors[ImGuiCol_DragDropTarget]         = ImVec4(0.00f, 0.00f, 0.00f, 0.90f);
colors[ImGuiCol_NavHighlight]           = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void aquamarineTheme(){
  ImVec4 *colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 1.00f, 0.98f, 0.70f);
  colors[ImGuiCol_ChildBg] = ImVec4(0.39f, 0.96f, 0.95f, 0.91f);
  colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.72f, 0.96f, 0.94f);
  colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.50f, 0.80f, 0.54f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.40f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.00f, 0.46f, 1.00f, 0.52f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.93f, 0.89f, 0.83f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.36f, 0.94f, 0.97f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.79f, 0.97f, 1.00f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(0.51f, 1.00f, 0.95f, 1.00f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.00f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
  colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
  colors[ImGuiCol_Button] = ImVec4(0.26f, 0.97f, 0.98f, 1.00f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(0.69f, 0.83f, 1.00f, 1.00f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
  colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.27f, 0.94f, 1.00f, 0.67f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
  colors[ImGuiCol_Tab] = ImVec4(0.27f, 1.00f, 0.89f, 1.00f);
  colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
  colors[ImGuiCol_TabActive] = ImVec4(0.00f, 0.92f, 1.00f, 1.00f);
  colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
  colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
  colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
  colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
  colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void hiBarbieTheme()
{
  ImVec4 *colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg] = ImVec4(1.00f, 0.37f, 0.83f, 0.81f);
  colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 0.33f, 0.95f, 1.00f);
  colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 0.52f, 1.00f, 1.00f);
  colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_FrameBg] = ImVec4(0.98f, 0.71f, 0.95f, 0.66f);
  colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.67f);
  colors[ImGuiCol_FrameBgActive] = ImVec4(0.98f, 0.42f, 0.96f, 0.62f);
  colors[ImGuiCol_TitleBg] = ImVec4(0.31f, 0.27f, 0.27f, 1.00f);
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.97f, 0.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.46f, 0.93f, 1.00f);
  colors[ImGuiCol_MenuBarBg] = ImVec4(1.00f, 0.00f, 0.96f, 1.00f);
  colors[ImGuiCol_ScrollbarBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.00f, 0.00f, 0.86f, 0.48f);
  colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 0.00f, 0.96f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.61f, 0.00f, 0.59f, 0.70f);
  colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_SliderGrabActive] = ImVec4(0.67f, 0.05f, 0.65f, 1.00f);
  colors[ImGuiCol_Button] = ImVec4(1.00f, 0.52f, 1.00f, 1.00f);
  colors[ImGuiCol_ButtonHovered] = ImVec4(0.99f, 0.37f, 0.97f, 1.00f);
  colors[ImGuiCol_ButtonActive] = ImVec4(0.94f, 0.00f, 1.00f, 1.00f);
  colors[ImGuiCol_Header] = ImVec4(1.00f, 1.00f, 1.00f, 0.31f);
  colors[ImGuiCol_HeaderHovered] = ImVec4(0.98f, 0.46f, 1.00f, 0.81f);
  colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 0.00f, 0.93f, 1.00f);
  colors[ImGuiCol_Separator] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
  colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.78f);
  colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
  colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
  colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
  colors[ImGuiCol_Tab] = ImVec4(1.00f, 0.41f, 0.98f, 0.86f);
  colors[ImGuiCol_TabHovered] = ImVec4(0.96f, 0.26f, 0.98f, 0.80f);
  colors[ImGuiCol_TabActive] = ImVec4(1.00f, 0.00f, 0.90f, 0.89f);
  colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
  colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
  colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
  colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
  colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
  colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

void inputSpeed()
{
  GameManager &GM = GameManager::Instance();
  if(esat::IsSpecialKeyDown(esat::kSpecialKey_Right) && GM.incrSpeed_ <= 2.0f)
  {
    printf("\n%f", GM.incrSpeed_);
    GM.incrSpeed_+=0.05f;
  }
  if(esat::IsSpecialKeyDown(esat::kSpecialKey_Left) && GM.incrSpeed_ >= 0.0f)
  {
    printf("\n%f", GM.incrSpeed_);
    GM.incrSpeed_-=0.05f;
  }

}