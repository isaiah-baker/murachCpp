#include "HeapArray.h"

// ----- CONSTRUCTOR ----- //
HeapArray::HeapArray(const int size) {
	array_size = size;                       // set array size property
	arr = new int[array_size] {0};           // allocate memory on heap
}

// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return array_size; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + array_size; }