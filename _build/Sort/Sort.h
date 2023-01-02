#pragma once
#include "raylib.h"
#include "vector"
#include "../Cache.h"

class Sort
{
public:
	virtual std::vector<int> SortData(std::vector<int> &data, int size, Cache& cache);
protected:
	template <typename type>
	void Swap(type *first, type *second);
};
