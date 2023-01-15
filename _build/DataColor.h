#pragma once
#include <vector>

#include "Cache.h"
#include "raylib.h"

class DataColor
{
public:

	DataColor(int size, Color dataColor = WHITE);

private:

	std::vector<Color> m_DataColor;

public:

	void UpdateDataColor(Cache* cache);
	std::vector<Color> GetDataColor(){return m_DataColor;}
};

