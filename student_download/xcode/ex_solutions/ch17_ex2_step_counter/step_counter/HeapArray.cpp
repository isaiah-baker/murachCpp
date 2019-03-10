#include "HeapArray.h"

// ----- CONSTRUCTORS ----- //
HeapArray::HeapArray(const int size) {
	array_size = size;                       // set array size property
	arr = new int[array_size] {0};           // allocate memory on heap
}

HeapArray::HeapArray(const HeapArray& tocopy) {
	array_size = tocopy.array_size;         // copy size
	arr = new int[array_size];              // allocate memory on heap

	for (int i = 0; i < array_size; i++) {  // copy array values
		arr[i] = tocopy.arr[i];
	}
}

// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

// ----- COPY ASSIGNMENT OPERATOR ----- //
HeapArray& HeapArray::operator= (const HeapArray& tocopy) {
	array_size = tocopy.array_size;          // copy size 
	int* new_arr = new int[array_size];      // allocate memory on heap    

	for (int i = 0; i < array_size; ++i) {   // copy array values
		new_arr[i] = tocopy.arr[i];
	}

	delete[] arr;                            // deallocate old memory
	arr = new_arr;                           // assign pointer to new memory
	return *this;                            // return a self-reference
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return array_size; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + array_size; }