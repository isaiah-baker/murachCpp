#ifndef MURACH_MYVECTOR_H
#define MURACH_MYVECTOR_H

template <typename T>
class MyVector {
private:
    T * elem = nullptr;      // pointer to memory for elements
    std::size_t array_size;  // actual number of elements (size)
    std::size_t space;       // space allocated for elements (capacity)
public:
    // Member types
    using size_type = std::size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using iterator = T*;
    using const_iterator = const T*;

    // Constructors 
    MyVector() {                             // default - inline 
        elem = nullptr;
        array_size = 0;
        space = 0;
    }
    MyVector(const MyVector& tobecopied);    // copy constructor
    MyVector(MyVector&& tobemoved);          // move constructor
    MyVector(int initial_size);              // set initial size
    MyVector(std::initializer_list<T> list); // initialization list 

    // Destructor
    ~MyVector();

    // Assignment operator
    MyVector& operator=(const MyVector& tobecopied); // copy assignment
    MyVector& operator=(MyVector&& tobemoved);       // move assignment

    // Subscript operator 
    reference operator[](int i) { return elem[i]; }            // inline         
    const_reference operator[](int i) const { return elem[i]; }// inline    

    // Member functions
    size_type size() const { return array_size; }              // inline
    size_type capacity() const { return space; }               // inline

    reference at(int index);
    const_reference at(int index) const;

    void reserve(int new_size);
    void push_back(T val);
    void resize(int new_size);

    iterator begin() { return elem; }                          // inline
    const_iterator cbegin() const { return elem; }             // inline
    iterator end() { return elem + array_size; }               // inline
    const_iterator cend() const { return elem + array_size; }  // inline
};


// copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector& tobecopied) {
    array_size = space = tobecopied.array_size;  // copy size and capacity
    elem = new T[array_size];                    // allocate memory for array

    // copy the elements of tobecopied's array (could also use std::copy)
    for (int i = 0; i < array_size; ++i) {
        elem[i] = tobecopied.elem[i];
    }
}

// move constructor
template <typename T>
MyVector<T>::MyVector(MyVector&& tobemoved) {
    array_size = tobemoved.array_size; // copy size 
    space = tobemoved.space;           // copy capacity 
    elem = tobemoved.elem;             // point to existing elements

    // empty the passed in vector 
    tobemoved.array_size = 0;
    tobemoved.space = 0;
    tobemoved.elem = nullptr;
}

// constructor that accepts an integer value for initial size
template <typename T>
MyVector<T>::MyVector(int initial_size) {
    array_size = space = initial_size;  // set initial size and capacity
    elem = new T[array_size];           // allocate memory for array

    // initialize the array with default value of type
    for (int i = 0; i < initial_size; ++i) {
        elem[i] = T();
    }
}

// constructor that accepts an initialization list
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list) {
    array_size = space = list.size();   // set initialize size and capacity
    elem = new T[array_size];           // allocate memory for array

    // copy the elements in the list (could also use std::copy)
    for (int i = 0; i < array_size; ++i) {
        elem[i] = list.begin()[i];
    }
}

// destructor
template <typename T>
MyVector<T>::~MyVector() {
    delete[] elem;  // OK even if elem is nullptr
}

// copy assignment
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& tobecopied) {
    array_size = tobecopied.array_size; // copy size
    space = tobecopied.array_size;      // set capacity

    // allocate new space
    T* new_elem = new T[array_size];

    // copy elements (could also use std::copy)
    for (int i = 0; i<array_size; ++i) {
        new_elem[i] = tobecopied.elem[i];
    }

    // deallocate old space
    delete[] elem;

    // assign new space
    elem = new_elem;

    // return a self-reference
    return *this;
}

// move assignment
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& tobemoved) {
    if (this != &tobemoved) {
        array_size = tobemoved.array_size;       // copy size   
        space = tobemoved.space;               // copy capacity  

        // deallocate old space and then point to existing elements
        delete[] elem;
        elem = tobemoved.elem;

        // empty the passed in vector 
        tobemoved.array_size = 0;
        tobemoved.space = 0;
        tobemoved.elem = nullptr;
    }

    // return a self-reference
    return *this;
}

// at()
template <typename T>
typename MyVector<T>::reference MyVector<T>::at(int i) {
    if (i < 0 || i >= array_size)
        throw std::out_of_range("MyVector<T>::at() - index out of range");
    else
        return elem[i];
}

template <typename T>
typename MyVector<T>::const_reference MyVector<T>::at(int i) const {
    if (i < 0 || i >= array_size)
        throw std::out_of_range("MyVector<T>::at() - index out of range");
    else
        return elem[i];
}

// reserve()
template <typename T>
void MyVector<T>::reserve(int new_size) {
    if (new_size <= space) return;         // never decrease allocation
    T* new_elem = new T[new_size];         // allocate new space    
    for (int i = 0; i < array_size; ++i) { // copy old elements
        new_elem[i] = elem[i];
    }
    delete[] elem;                     // deallocate old space
    elem = new_elem;                   // assign new space
    space = new_size;                  // set new capacity value         
}

// push_back()
template <typename T>
void MyVector<T>::push_back(T item) {
    if (space == 0)               // if array empty,
        reserve(1);               // start with capacity of 1
    else if (array_size == space) // if array full,
        reserve(2 * space);       // add more capacity (doubling is common)          

    elem[array_size] = item;      // add item at end
    ++array_size;                 // increment variable that tracks size      
}

// resize()
template <typename T>
void MyVector<T>::resize(int new_size) {
    reserve(new_size);    // set new capacity (won't make smaller)    
    for (int i = array_size; i < new_size; ++i) {  // init new elements
        elem[i] = T();
    }

    // reset size variable to indicate new size (
    if (new_size > array_size)
        array_size = new_size;
}

#endif /* MURACH_MYVECTOR_H */