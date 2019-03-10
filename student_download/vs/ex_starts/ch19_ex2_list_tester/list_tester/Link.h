#ifndef MURACH_LINK_H
#define MURACH_LINK_H

template <typename T>
struct Link {
    T value;            // the value in the link
    Link* prev;         // pointer to the previous link
    Link* next;         // pointer to the next link

    Link(T val) {       // constructor
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

#endif /* MURACH_LINK_H */