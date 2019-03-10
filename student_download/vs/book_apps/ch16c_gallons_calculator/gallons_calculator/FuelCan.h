#ifndef MURACH_FUEL_CAN_H
#define MURACH_FUEL_CAN_H

class FuelTank;   // forward declaration of FuelTank class

class FuelCan
{
private:
    double gallons = 0;
public:
    FuelCan(double gallons_param = 0) { gallons = gallons_param; }
    double get_gallons() { return gallons; }
    friend void pour(FuelTank& tank, FuelCan& can);
};

#endif // MURACH_FUEL_CAN_H