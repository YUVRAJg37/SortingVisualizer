#include "Menu.h"
#include "raylib.h"
#include "Screen.h"

Menu::Menu(int totalMenus, int spacing_x, int spacing_y)
{
    TotalMenus = totalMenus;
    Spacing_X = spacing_x;
    Spacing_Y = spacing_y;
}

void Menu::Init()
{
    ScreenInfo screenInfo;
    
    ButtonWidth = screenInfo.menuWidth - 2*Spacing_X;
    ButtonHeight = (screenInfo.screenHeight - (TotalMenus + 1)*Spacing_Y)/TotalMenus;
    for(int i=0; i<TotalMenus; i++)
    {
        int posX = screenInfo.visualizerWidth + (screenInfo.menuWidth - ButtonWidth)/2;
        int posY = (ButtonHeight + Spacing_Y)*i + Spacing_Y;
        DrawRectangle( posX, posY, ButtonWidth, ButtonHeight, WHITE);
    }
}

