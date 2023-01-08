#include "Menu.h"

#include <iostream>

#include "Screen.h"

Menu::Menu(int spacing_x, int spacing_y) :
m_TotalButtonCount(0),
m_Pos_X(0),
m_ButtonHeight(0),
m_ButtonWidth(0),
m_CurrentPressedButtonIndex(-1)
{
    ScreenInfo screenInfo;

    m_Spacing_Y = spacing_y;

    m_ButtonWidth = screenInfo.menuWidth - 2*spacing_x;
    m_Pos_X = screenInfo.visualizerWidth + (screenInfo.menuWidth - m_ButtonWidth)/2;
}

void Menu::AddButton(const char* buttonName)
{
    m_TotalButtonCount++;
    m_ButtonNames.push(buttonName);
}

void Menu::PushButton()
{
    m_TotalButtonCount = 0;
    m_Buttons.clear();
}

void Menu::PopButton()
{
    DrawButtons();
    CollisionTest();
}

void Menu::DrawButtons()
{
    ScreenInfo screenInfo;
    m_ButtonHeight = (screenInfo.screenHeight - (m_TotalButtonCount + 1)*m_Spacing_Y)/m_TotalButtonCount;
    int FontSize = 30;
    int Padding = 3;
    
    for(int i=0; i<m_TotalButtonCount; i++)
    {
        int Pos_Y = (m_ButtonHeight + m_Spacing_Y)*i + m_Spacing_Y;
        Rectangle Button, Border;

        Button.x = m_Pos_X;
        Button.y = Pos_Y;
        Button.height = m_ButtonHeight;
        Button.width = m_ButtonWidth;
        Border.x = m_Pos_X + Padding;
        Border.y = Pos_Y + Padding;
        Border.width = m_ButtonWidth - 2*Padding;
        Border.height = m_ButtonHeight - 2*Padding;

        Color BorderColor = m_CurrentHoveredButtonIndex == i ? DARKBLUE : LIGHTGRAY;
        Color TextColor = m_CurrentHoveredButtonIndex == i ? DARKBLUE : GRAY;
        Color ButtonColor = m_CurrentHoveredButtonIndex == i ? SKYBLUE : LIGHTGRAY;

        
        DrawRectangleRec(Button,BorderColor);
        DrawRectangleRec(Border, ButtonColor);
        m_Buttons.push_back(Button);
        DrawText(m_ButtonNames.front(), screenInfo.visualizerWidth + screenInfo.menuWidth/2 - FontSize - FontSize/2, Pos_Y + m_ButtonHeight/2 - FontSize/2, FontSize, TextColor);
        m_ButtonNames.pop();
    }

    m_CurrentHoveredButtonIndex = CollisionTest();
}

int Menu::CollisionTest()
{
    for(int i=0; i<m_Buttons.size(); i++)
    {
        if(CheckCollisionPointRec(GetMousePosition(), m_Buttons[i]))
        {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                m_CurrentPressedButtonIndex = i;
            return i;
        }
    }
    return -1;
}





