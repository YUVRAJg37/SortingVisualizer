#include "BubbleSort.h"

std::vector<int> BubbleSort::SortData(std::vector<int> &data, int size,Cache& cache)
{
	if(cache.i < size - 1 )
	{
		while(cache.j< size - cache.i - 1)
		{
			if(data[cache.j] > data[cache.j + 1])
			{
				int Temp = data[cache.j];
				data[cache.j] = data[cache.j+1];
				data[cache.j+1] = Temp;
			}

			cache.j++;
			return data;
		}
		cache.i++;
		cache.j = 0;
	}

	return data;
}


