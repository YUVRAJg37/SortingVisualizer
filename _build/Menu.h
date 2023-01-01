#pragma once
#include <complex.h>

class Menu
{
public:
    
    Menu(int totalMenus, int spacing_x, int spacing_y);
    void Init();

private:
    
    int ButtonWidth;
    int ButtonHeight;
    int TotalMenus;
    int Spacing_X;
    int Spacing_Y;

public:

    inline int getButtonWidth() const{return ButtonWidth;}
    inline int getButtonHeight() const{return ButtonHeight;}
    
};

