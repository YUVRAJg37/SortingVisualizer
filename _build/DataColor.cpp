#include "DataColor.h"

DataColor::DataColor(int size, Color dataColor)
{
	Color DataColor[size + 1]{dataColor};

	m_ColorData = DataColor;
}
