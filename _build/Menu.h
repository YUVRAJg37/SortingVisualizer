#pragma once

#include <queue>

#include "raylib.h"

class Menu
{
public:
    
    Menu(int spacing_x, int spacing_y);
    
    void AddButton(const char* buttonName);
    void PushButton();
    void PopButton();

private:
    
    int m_ButtonWidth;
    int m_ButtonHeight;
    int m_TotalButtonCount;
    int m_Spacing_Y;
    int m_Pos_X;
    std::vector<Rectangle> m_Buttons;
    int m_CurrentHoveredButtonIndex;
    int m_CurrentPressedButtonIndex;

    std::queue<const char*> m_ButtonNames;
    int CollisionTest();
    void DrawButtons();

public:

    inline int getButtonWidth() const{return m_ButtonWidth;}
    inline int getButtonHeight() const{return m_ButtonHeight;}
    inline int getCurrentPressedButtonIndex() const {return m_CurrentPressedButtonIndex;}
    
};

