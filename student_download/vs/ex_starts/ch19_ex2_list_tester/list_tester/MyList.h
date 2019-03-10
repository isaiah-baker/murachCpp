#ifndef MURACH_MYLIST_H
#define MURACH_MYLIST_H

#include "MyIterator.h"

template <typename T>
class MyList {
private:
    Link<T>* head;            // A pointer to the first link in the list
    Link<T>* tail;            // A pointer to the last link in the list
    std::size_t list_size;    // The number of nodes in the list

    // helper function
    void initialize() {
        head = nullptr;
        tail = nullptr;
        list_size = 0;
    }

public:
    // Member types
    using size_type = std::size_t;
    using value_type = T;
    using reference = T & ;
    using iterator = MyIterator<T>;

    // Constructor
    MyList() { initialize(); }                      // inline 

                                                    // Destructor
    ~MyList();

    // Member functions
    size_type size() const { return list_size; }     // inline 
    void push_back(T);
    void pop_back();
    reference at(int index);
    void remove(T);

    iterator begin() { return iterator(head); }       // inline
    iterator end() { return iterator(nullptr); }      // inline
};

template <typename T>
MyList<T>::~MyList() { // deallocate the memory for each element in the list

    Link<T>* iter;     // to traverse the list
    Link<T>* next;     // to point to the next link in the list

    iter = head;
    while (iter) {     // that is, while iter != nullptr
        next = iter->next;
        delete iter;
        iter = next;
    }
}

// push_back()
template <typename T>
void MyList<T>::push_back(T item) {
    Link<T>* new_link = new Link<T>(item);  // allocate memory

    if (!head) {                            // if empty
        head = new_link;
        tail = new_link;
    }
    else {                                  // if elements exist
        new_link->prev = tail;
        tail->next = new_link;
        tail = new_link;
    }
    ++list_size;
}

// pop_back()
template <typename T>
void MyList<T>::pop_back() {
    if (tail) {                              // if elements exist
        if (head == tail) {                  // if one element
            delete head;
            initialize();
        }
        else {                               // if multiple elements
            Link<T>* todelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete todelete;
            --list_size;
        }
    }
}

// at()
template <typename T>
typename MyList<T>::reference MyList<T>::at(int index) {
    if (index < 0 || index >= list_size) {
        throw std::out_of_range("MyLinkedList<T>::at() - out of range");
    }
    else {
        Link<T>* iter = head;               // start at first link
        for (int i = 0; i < index; i++) {   // iterate to desired link
            iter = iter->next;
        }
        return iter->value;                 // return value of link
    }
}

// remove()
template <typename T>
void MyList<T>::remove(T val) {
    Link<T>* iter = head;                 // pointer to traverse list

    while (iter) {
        if (iter->value == val) {
            if (head == tail) {           // if there's only one link
                delete head;
                initialize();
                break;
            }
            else {                        // if there are multiple links
                if (iter == head) {            // if first of multiple links
                    head = iter->next;
                    head->prev = nullptr;
                }
                else if (iter == tail) {       // if last of multiple links
                    tail = iter->prev;
                    tail->next = nullptr;
                }
                else {                        // if between other links
                    iter->prev->next = iter->next;
                    iter->next->prev = iter->prev;
                }
				Link<T>* next = iter->next;   // store next element in link
                delete iter;                  // deallocate memory
				iter = next;                  // move to next link
                --list_size;                  // decrement size
            }
        }
		else { // current element doesn't match 
			iter = iter->next;                // move to next link
		}
    }
}

#endif /* MURACH_MYLIST_H */