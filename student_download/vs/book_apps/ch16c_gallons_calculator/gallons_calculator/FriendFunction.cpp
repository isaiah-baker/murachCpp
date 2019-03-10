#include <iostream>
#include "FuelCan.h"
#include "FuelTank.h"

using namespace std;

void pour(FuelTank& tank, FuelCan& can) {
    tank.gallons += can.gallons;   // access private data members
    can.gallons = 0;               // access private data memeber
}

ostream& operator << (ostream& out, const FuelTank& tank) {
    out << "   Gallons: " << tank.gallons << endl
        << "   Liters:  " << tank.get_liters() << endl
        << endl;
    return out;
}

istream& operator >> (istream& in, FuelTank& tank) {
    cout << "Enter gallons: ";
    in >> tank.gallons;
    return in;
}