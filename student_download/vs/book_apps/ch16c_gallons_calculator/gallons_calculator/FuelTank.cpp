#include <iostream>
#include "FuelTank.h"

using namespace std;

double FuelTank::get_liters() const {
    double liters = gallons * 3.7854;
    return liters;
}

FuelTank FuelTank::operator+ (const FuelTank& right) {
    FuelTank t;
    t.set_gallons(gallons + right.gallons);
    return t;
}

FuelTank FuelTank::operator- (const FuelTank& right) {
    FuelTank t;
    t.set_gallons(gallons - right.gallons);
    return t;
}

// prefix overload
FuelTank& FuelTank::operator++ () {
    ++gallons;                // increment data member
    return *this;             // return current object with incremented values
}

// postfix overload
/*
FuelTank FuelTank::operator++ (int unused_param) {
    FuelTank temp = *this;    // make copy of current object
    ++gallons;                // increment the current object
    return temp;              // return the copy with pre-increment values
}
*/

// another possible postfix overload -- better for incrementing multiple data members
FuelTank FuelTank::operator++ (int unused_param) {
    FuelTank temp = *this;    // make copy of current object
    ++*this;                  // increment the current object
    return temp;              // return the copy with pre-increment values
}

bool FuelTank::operator< (const FuelTank& right) {
    if (gallons < right.gallons)
        return true;
    else
        return false;
}

bool FuelTank::operator> (const FuelTank& right) {
    return (gallons > right.gallons);
}

bool FuelTank::operator== (const FuelTank& right) {
    return (gallons == right.gallons);
}