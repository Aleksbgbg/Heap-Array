#include "HeapArray.h"

#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T>
void output(const HeapArray<T>& array)
{
	std::copy(array.begin(), array.end(), std::ostream_iterator<T>{ std::cout, "\n" });
}

int main()
{
	HeapArray<int> numbers{ 500 };

	numbers[499] = 10;

	{
		const HeapArray<int> numbers2{ numbers };
		output(numbers2);
	}

	{
		const HeapArray<int> numbers3{ std::move(numbers) };
		output(numbers3);
	}

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}