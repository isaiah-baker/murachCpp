#ifndef MURACH_FUEL_TANK_H
#define MURACH_FUEL_TANK_H

#include "FuelCan.h"

class FuelTank {
private:
    double gallons;
public:
    FuelTank(double gallons_param = 0) {
        gallons = gallons_param;
    }

    void set_gallons(double gallons_param) { 
        gallons = gallons_param;
    }

    double get_gallons() const {
        return gallons;
    }

    double get_liters() const;

    FuelTank operator+ (const FuelTank& right);
    FuelTank operator- (const FuelTank& right);

    FuelTank& operator++ ();                 // prefix
    FuelTank operator++ (int unused_param);  // postfix

    bool operator< (const FuelTank& right);
    bool operator> (const FuelTank& right);
    bool operator== (const FuelTank& right);

    friend void pour(FuelTank& tank, FuelCan& can);
    friend std::ostream& operator<< (std::ostream&, const FuelTank&);
    friend std::istream& operator>> (std::istream&, FuelTank&);
};

#endif // MURACH_FUEL_TANK_H
