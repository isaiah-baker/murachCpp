#ifndef MURACH_FINDMIDPOINT_H
#define MURACH_FINDMIDPOINT_H

template<typename BidirIter>
BidirIter find_midpoint(BidirIter begin, BidirIter end) {
    // if range is empty, return the off-the-end iterator 
    if (begin == end) return end;

    // alternate decrementing end and incrementing begin 
    // until both point to the same element
    int counter = 0;
    while (begin != end) {
        if (counter % 2 == 0) {  // even
            --end;
        }
        else {
            ++begin;
        }
        ++counter;  // increment counter 
    }
    return begin;
}

#endif /* MURACH_FINDMIDPOINT_H */