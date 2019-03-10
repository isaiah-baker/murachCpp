#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

class HeapArray {
private:
	int array_size;
	int* arr = nullptr;

public:
	// constructor
	HeapArray(const int);

	// destructor
	~HeapArray();

	// subscript operator 
	int& operator[] (int i);

	// Member functions
	int size() const;
	int* begin();
	int* end();
};

#endif /* MURACH_HEAPARRAY_H */
