#pragma once

#include <memory>

template<typename T>
class HeapArray
{
public:
	HeapArray() = default;
	
	explicit HeapArray(const int size);
	
	HeapArray(const HeapArray<T>& source);
	HeapArray(HeapArray<T>&& source) noexcept = default;

	~HeapArray() = default;
	
	HeapArray<T>& operator=(const HeapArray<T>& source);
	HeapArray<T>& operator=(HeapArray<T>&& source) noexcept = default;
	
	T& operator[](const int index);
	const T& operator[](const int index) const;

	// TODO: Implement comparison operators
	// bool operator==(const HeapArray<T>& source) const;
	// bool operator!=(const HeapArray<T>& source) const;
	// bool operator<(const HeapArray<T>& source) const;
	// bool operator>(const HeapArray<T>& source) const;
	// bool operator<=(const HeapArray<T>& source) const;
	// bool operator>=(const HeapArray<T>& source) const;

	int GetSize() const;
	
	// ReSharper disable CppInconsistentNaming
	T* begin() const;
	T* end() const;
	// ReSharper restore CppInconsistentNaming

private:
	int size = 0;
	std::unique_ptr<T[]> array;
};