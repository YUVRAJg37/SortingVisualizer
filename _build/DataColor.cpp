#include "DataColor.h"

#include <vector>

DataColor::DataColor(int size, Color dataColor)
{
	m_DataColor.resize(size + 1);
	for(int i=0; i<size+1; i++)
	{
		m_DataColor[i] = dataColor;
	}
}
