#include "Menu.h"

#include <iostream>

#include "Screen.h"

Menu::Menu(int spacing_x, int spacing_y) :
TotalButtonCount(0),
Pos_X(0),
ButtonHeight(0),
ButtonWidth(0)
{
    ScreenInfo screenInfo;

    Spacing_Y = spacing_y;

    ButtonWidth = screenInfo.menuWidth - 2*spacing_x;
    Pos_X = screenInfo.visualizerWidth + (screenInfo.menuWidth - ButtonWidth)/2;
}

void Menu::AddButton(const char* buttonName)
{
    TotalButtonCount++;
    ButtonNames.push(buttonName);
}

void Menu::PushButton()
{
    TotalButtonCount = 0;
    Buttons.clear();
}

void Menu::PopButton()
{
    DrawButtons();
    CollisionTest();
}

void Menu::DrawButtons()
{
    ScreenInfo screenInfo;
    ButtonHeight = (screenInfo.screenHeight - (TotalButtonCount + 1)*Spacing_Y)/TotalButtonCount;
    int fontSize = 30;
    int padding = 3;
    
    for(int i=0; i<TotalButtonCount; i++)
    {
        int Pos_Y = (ButtonHeight + Spacing_Y)*i + Spacing_Y;
        Rectangle button, border;

        button.x = Pos_X;
        button.y = Pos_Y;
        button.height = ButtonHeight;
        button.width = ButtonWidth;
        border.x = Pos_X + padding;
        border.y = Pos_Y + padding;
        border.width = ButtonWidth - 2*padding;
        border.height = ButtonHeight - 2*padding;

        Color BorderColor = CurrentTouchedButtonIndex == i ? DARKBLUE : LIGHTGRAY;
        Color TextColor = CurrentTouchedButtonIndex == i ? DARKBLUE : GRAY;
        Color ButtonColor = CurrentTouchedButtonIndex == i ? SKYBLUE : LIGHTGRAY;

        
        DrawRectangleRec( button ,BorderColor);
        DrawRectangleRec(border, ButtonColor);
        Buttons.push_back(button);
        DrawText(ButtonNames.front(), screenInfo.visualizerWidth + screenInfo.menuWidth/2 - fontSize - fontSize/2, Pos_Y + ButtonHeight/2 - fontSize/2, fontSize, TextColor);
        ButtonNames.pop();
    }

    CurrentTouchedButtonIndex = CollisionTest();
}

int Menu::CollisionTest()
{
    for(int i=0; i<Buttons.size(); i++)
    {
        if(CheckCollisionPointRec(GetMousePosition(), Buttons[i]))
        {
            return i;
        }
    }
    return -1;
}





