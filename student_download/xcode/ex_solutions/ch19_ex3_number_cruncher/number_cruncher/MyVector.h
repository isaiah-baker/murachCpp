#ifndef MURACH_MYVECTOR_H
#define MURACH_MYVECTOR_H

template <typename T>
class MyVector {
private:
    T * elem = nullptr;      // pointer to memory for elements
    std::size_t arraySize;   // actual number of elements (size)
    std::size_t space;       // space allocated for elements (capacity)
public:
    // Member types
    using size_type = std::size_t;
    using value_type = T;
    using reference = T & ;
    using const_reference = const T&;
    using iterator = T * ;
    using const_iterator = const T*;

    // Constructors 
    MyVector() { elem = nullptr; arraySize = 0; space = 0; }   // inline 
    MyVector(const MyVector& tobecopied);    // copy constructor
    MyVector(MyVector&& tobemoved);          // move constructor
    MyVector(int initialSize);               // set initial size
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
    size_type size() const { return arraySize; }               // inline
    size_type capacity() const { return space; }               // inline

    reference at(int index);
    const_reference at(int index) const;

    void reserve(int newSize);
    void push_back(T val);
    void resize(int newSize);

    iterator begin() { return elem; }                          // inline
    const_iterator cbegin() const { return elem; }             // inline
    iterator end() { return elem + arraySize; }                // inline
    const_iterator cend() const { return elem + arraySize; }   // inline
};


// copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector& tobecopied) {
    arraySize = space = tobecopied.arraySize;   // copy size and capacity
    elem = new T[arraySize];                    // allocate memory for array

                                                // copy the elements of tobecopied's array (could also use std::copy)
    for (int i = 0; i < arraySize; i++) {
        elem[i] = tobecopied.elem[i];
    }
}

// move constructor
template <typename T>
MyVector<T>::MyVector(MyVector&& tobemoved) {
    arraySize = tobemoved.arraySize;   // copy size 
    space = tobemoved.space;           // copy capacity 

    elem = tobemoved.elem;             // point to existing elements

                                       // empty the passed in vector 
    tobemoved.arraySize = 0;
    tobemoved.space = 0;
    tobemoved.elem = nullptr;
}

// constructor that accepts an integer value for initial size
template <typename T>
MyVector<T>::MyVector(int initialSize) {
    arraySize = space = initialSize;   // set initial size and capacity
    elem = new T[arraySize];           // allocate memory for array

                                       // initialize the array with default value of type
    for (int i = 0; i < initialSize; i++) {
        elem[i] = T();
    }
}

// constructor that accepts an initialization list
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list) {
    arraySize = space = list.size();   // copy size and capacity 
    elem = new T[arraySize];           // allocate memory for array

                                       // copy the elements in the list (could also use std::copy)
    for (int i = 0; i < arraySize; i++) {
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
    arraySize = space = tobecopied.arraySize;   // copy size and capacity

                                                // allocate new space
    T* newElem = new T[arraySize];

    // copy elements (could also use std::copy)
    for (int i = 0; i<arraySize; ++i) {
        newElem[i] = tobecopied.elem[i];
    }

    // deallocate old space
    delete[] elem;

    // assign new space
    elem = newElem;

    // return a self-reference
    return *this;
}

// move assignment
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& tobemoved) {
    if (this != &tobemoved) {
        arraySize = tobemoved.arraySize;       // copy size   
        space = tobemoved.space;               // copy capacity  

                                               // deallocate old space and then point to existing elements
        delete[] elem;
        elem = tobemoved.elem;

        // empty the passed in vector 
        tobemoved.arraySize = 0;
        tobemoved.space = 0;
        tobemoved.elem = nullptr;
    }

    // return a self-reference
    return *this;
}

// at()
template <typename T>
typename MyVector<T>::reference MyVector<T>::at(int i) {
    if (i < 0 || i >= arraySize)
        throw std::out_of_range("MyVector<T>::at() - index out of range");
    else return elem[i];
}
template <typename T>
typename MyVector<T>::const_reference MyVector<T>::at(int i) const {
    if (i < 0 || i >= arraySize)
        throw std::out_of_range("MyVector<T>::at() - index out of range");
    else return elem[i];
}

// reserve()
template <typename T>
void MyVector<T>::reserve(int newSize) {
    if (newSize <= space) return;       // never decrease allocation
    T* newElem = new T[newSize];        // allocate new space

    // copy old elements (could also use std::copy) 
    for (int i = 0; i<arraySize; ++i) {
        newElem[i] = elem[i];
    }

    delete[] elem;                     // deallocate old space
    elem = newElem;                    // assign new space
    space = newSize;                   // set new capacity value         
}

// push_back()
template <typename T>
void MyVector<T>::push_back(T item) {
    if (space == 0)
        reserve(1);              // start with capacity of 1
    else if (arraySize == space) // array full...
        reserve(2 * space);      // add more capacity (doubling is common)          

    elem[arraySize] = item;      // add item at end
    ++arraySize;                 // increment variable that tracks size      
}

// resize()
template <typename T>
void MyVector<T>::resize(int newSize) {
    reserve(newSize);     // set new capacity (won't make smaller)

    // initialize new elements (loop won't run if no new elements)
    for (int i = arraySize; i < newSize; ++i) {
        elem[i] = T();
    }

    // reset size variable to indicate new size (
    if (newSize > arraySize)
        arraySize = newSize;
}

#endif /* MURACH_MYVECTOR_H */