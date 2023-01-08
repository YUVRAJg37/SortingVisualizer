#pragma once
#include <vector>

#include "raylib.h"

class DataColor
{
public:

	DataColor(int size, Color dataColor = WHITE);

private:

	std::vector<Color> m_DataColor;
};

