#pragma once
#include "raylib.h"

class DataColor
{
public:

	DataColor(int size, Color dataColor = WHITE);

private:

	Color* m_ColorData;
};

