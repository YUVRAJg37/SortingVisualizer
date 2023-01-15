#include "SelectionSort.h"

std::vector<int> SelectionSort::SortData(std::vector<int>& data, int size, Cache& cache)
{
    if(cache.i<size-1)
    {
       cache.j = cache.i;
        for (int i = cache.i + 1; i < size; i++)\
        {
            if (data[i] < data[cache.j])
                cache.j = i;
        }

        Swap(&data[cache.j], &data[cache.i]);
     
        cache.i++;
        return data;
    }
    
    return data;
}
