#include <algorithm>

#include "HeapArray.h"
#include <iostream>
#include <iterator>

int main()
{
	{
		HeapArray<int> numbers{ 500 };

		std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>{ std::cout, "\n" });
	}

	_CrtDumpMemoryLeaks();

	system("pause");

	return 0;
}