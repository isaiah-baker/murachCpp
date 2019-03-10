#include "Link.h"

template<typename T>
class MyIterator {
private:
    Link<T>* current = nullptr;
public:
    // iterator traits
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = T & ;
    using pointer = T * ;

    // constructor
    MyIterator(Link<T>* curr) {
        current = curr;
    }

    // operators
    MyIterator& operator=(const MyIterator& tobecopied) {  // assignment
        current = tobecopied.current;
        return *this;
    }

    T& operator*() const { return current->value; }        // indirection
    bool operator==(const MyIterator& other) const {       // equal
        return current == other.current;
    }

    bool operator!=(const MyIterator& other) const {       // not equal
        return current != other.current;
    }

    MyIterator& operator++() {                    // increment - prefix
        current = current->next;
        return *this;
    }

    MyIterator operator++(int unused) {           // increment - postfix
        auto temp = *this;
        current = current->next;
        return temp;
    }

    MyIterator& operator--() {                    // decrement - prefix
        current = current->prev;
        return *this;
    }

    MyIterator operator--(int unused) {           // decrement - postfix
        auto temp = *this;
        current = current->prev;
        return temp;
    }
};