#ifndef MURACH_HEAP_ARRAY_H
#define MURACH_HEAP_ARRAY_H

template<typename T>
class HeapArray {
private:
    int array_size;
    T* arr;
    
public:
    // declarations
    HeapArray(const int);                   // constructor
    HeapArray(const HeapArray& tocopy);     // copy constructor
    HeapArray(HeapArray&& tomove);          // move constructor
    ~HeapArray();                           // destructor
    HeapArray& operator=(const HeapArray& tocopy);  // copy assignment
    HeapArray& operator=(HeapArray&& tomove);       // move assignment
    
    // inline definitions
    T& operator[](int i) { return arr[i]; }  // subscript operator
    int size() const { return array_size; }  // member function
    T* begin() { return arr; }
    T* end() { return arr + array_size; }
    
};

// ----- CONSTRUCTORS ----- //
template<typename T>
HeapArray<T>::HeapArray(const int size) {
    array_size = size;                      // set array size property
    arr = new T[array_size];                // allocate memory on heap
    for (int i = 0; i < array_size; i++) {  // initialize array values
        arr[i] = T();
    }
}

template<typename T>
HeapArray<T>::HeapArray(const HeapArray& tocopy) {          // COPY
    array_size = tocopy.array_size;         // copy size
    arr = new T[array_size];                // allocate memory on heap
    for (int i = 0; i < array_size; i++) {  // copy array values
        arr[i] = tocopy.arr[i];
    }
}

template<typename T>
HeapArray<T>::HeapArray(HeapArray&& tomove) {               // MOVE
    array_size = tomove.array_size;         // copy size
    arr = tomove.arr;                       // reset array pointer
    tomove.array_size = 0;                  // empty passed in container
    tomove.arr = nullptr;
}

// ----- DESTRUCTOR ----- //
template<typename T>
HeapArray<T>::~HeapArray() {
    delete[] arr;  // deallocate memory - safe to run delete on nullptr
}

// ----- ASSIGNMENT OPERATORS ----- //
template<typename T>
HeapArray<T>& HeapArray<T>::operator=(const HeapArray& tocopy) { // COPY
    array_size = tocopy.array_size;          // copy size
    T* newArr = new T[array_size];           // allocate memory on heap
    for (int i = 0; i < array_size; ++i) {   // copy array values
        newArr[i] = tocopy.arr[i];
    }
    delete[] arr;                            // deallocate old memory
    arr = newArr;                            // assign new memory
    return *this;                            // return a self-reference
}

template<typename T>
HeapArray<T>& HeapArray<T>::operator=(HeapArray&& tomove) {      // MOVE
    if (this != &tomove) {                  // don't move if passed self
        array_size = tomove.array_size;     // copy size
        delete[] arr;                       // deallocate old memory
        arr = tomove.arr;                   // reset array pointer
        tomove.array_size = 0;              // empty passed in container
        tomove.arr = nullptr;
    }
    return *this;                           // return a self-reference
}

#endif // MURACH_HEAP_ARRAY_H

