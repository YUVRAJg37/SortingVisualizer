#pragma once
#include "../Sort.h"


class BubbleSort : public Sort
{
public:

	std::vector<int> SortData(std::vector<int> &data, int size,Cache& cache) override;
};
