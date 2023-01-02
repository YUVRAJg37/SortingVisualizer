#include "Sort.h"

std::vector<int> Sort::SortData(std::vector<int> &data, int size,Cache& cache)
{
	return {0};
}

template <typename type>
void Sort::Swap(type *first, type *second)
{
	type temp = *first;
	*first = *second;
	*second = temp;
}
