#include <iostream>
#include "HeapArray.h"

using namespace std;

template<typename T>
void display_array(HeapArray<T>& arr, int size);

template<typename T>
int linear_search(HeapArray<T>& arr, int counter, T value_to_find);

int main()
{
	const int size = 6;

	HeapArray<int> numbers(size);
	for (int i = 0; i < size; ++i) {
		numbers[i] = (i + 1) * 10;
	}
	int index = linear_search(numbers, size, 40);
	cout << "Numbers array: ";
	display_array(numbers, size);
	cout << "\nThe number 40 was found at index " << index << "\n\n";

	HeapArray<double> prices(size);
	for (int i = 0; i < size; ++i) {
		prices[i] = i + .99;
	}
	index = linear_search(prices, size, 1.99);
	cout << "Prices array: ";
	display_array(prices, size);
	cout << "\nThe price 1.99 was found at index " << index << "\n\n";
}

template<typename T>
void display_array(HeapArray<T>& arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
}

template<typename T>
int linear_search(HeapArray<T>& arr, int counter, T value_to_find) {
	for (int i = 0; i < counter; ++i) {
		if (arr[i] == value_to_find) {
			return i;  // value found - return index
		}
	}
	return -1;         // value not found - return -1
}
