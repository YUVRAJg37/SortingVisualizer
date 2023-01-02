#pragma once
#include "../Sort.h"


class QuickSort : public Sort
{
public:

    std::vector<int> SortData(std::vector<int> &data, int size,Cache& cache) override;
};
