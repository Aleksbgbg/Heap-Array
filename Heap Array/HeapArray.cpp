#include "HeapArray.h"

template<typename T>
HeapArray<T>::HeapArray(const int size)
	:
	size{ size },
	array{ std::make_unique<T[]>(size) }
{
}

template<typename T>
HeapArray<T>::HeapArray(const HeapArray<T>& source)
{
	*this = source;
}

template<typename T>
HeapArray<T>& HeapArray<T>::operator=(const HeapArray<T>& source)
{
	if (this != &source)
	{
		if (size != source.size)
		{
			size = source.size;
			array = std::make_unique<T[]>(size);
		}

		for (int index = 0; index < size; ++index)
		{
			(*this)[index] = source[index];
		}
	}

	return *this;
}

template<typename T>
T& HeapArray<T>::operator[](const int index)
{
	return array[index];
}

template<typename T>
const T& HeapArray<T>::operator[](const int index) const
{
	return array[index];
}

template<typename T>
int HeapArray<T>::GetSize() const
{
	return size;
}

template<typename T>
T* HeapArray<T>::begin() const
{
	return array.get();
}

template<typename T>
T* HeapArray<T>::end() const
{
	return array.get() + size;
}

// Any templated usages go here
template class HeapArray<int>;