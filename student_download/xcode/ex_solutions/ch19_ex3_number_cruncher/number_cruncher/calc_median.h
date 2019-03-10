#ifndef MURACH_CALCMEDIAN_H
#define MURACH_CALCMEDIAN_H

template<typename BidirIter>
double calc_median(BidirIter begin, BidirIter end) {
    // if range is empty, return -1.0
    if (begin == end) throw std::invalid_argument("Range can't be empty");

    // find midpoint 
    // by alternate decrementing end and incrementing begin 
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

    // calculate median
    double median;
    if (counter % 2 == 0) {  // even - median is sum of midpoint and prev divided by 2
        double mid_val = *begin;
        double prev_val = *(--begin);
        median = (mid_val + prev_val) / 2;
    }
    else {                   // odd - median is same as midpoint
        median = *begin;
    }
    return median;
}

#endif /* MURACH_CALCMEDIAN_H */
