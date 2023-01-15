#include "DataColor.h"

#include <vector>

#include "Cache.h"

DataColor::DataColor(int size, Color dataColor)
{
	m_DataColor.resize(size + 1);
	for(int i=0; i<size+1; i++)
	{
		m_DataColor[i] = dataColor;
	}
}

void DataColor::UpdateDataColor(Cache* cache)
{
	m_DataColor[cache->i+1] = RED;
	m_DataColor[cache->j] = WHITE;
	m_DataColor[cache->j+1] = GREEN;
	
}
