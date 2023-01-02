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
    
    int ButtonWidth;
    int ButtonHeight;
    int TotalButtonCount;
    int Spacing_Y;
    int Pos_X;
    std::vector<Rectangle> Buttons;
    int CurrentTouchedButtonIndex;

    std::queue<const char*> ButtonNames;
    int CollisionTest();
    void DrawButtons();

public:

    inline int getButtonWidth() const{return ButtonWidth;}
    inline int getButtonHeight() const{return ButtonHeight;}
    
};

