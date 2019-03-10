#include <iostream>
#include "FuelTank.h"
#include "FuelCan.h"

using namespace std;

int main()
{
    FuelTank tank(500);
    FuelCan can(2);
    cout << "TANK: " << tank.get_gallons() << endl;
    cout << "CAN: " << can.get_gallons() << endl;
    pour(tank, can);
    cout << "TANK after pour: " << tank.get_gallons() << endl;
    cout << "CAN after pour: " << can.get_gallons() << endl << endl;
    
    FuelTank tank1(100);
    cout << "TANK 1" << endl
    << "  Gallons: " << tank1.get_gallons() << endl
    << "  Liters:  " << tank1.get_liters() << endl << endl;
    
    FuelTank tank2(200);
    cout << "TANK 2" << endl
    << "  Gallons: " << tank2.get_gallons() << endl
    << "  Liters:  " << tank2.get_liters() << endl << endl;
    
    FuelTank tank3 = tank2 + tank1;
    // FuelTank tank3 = tank2.operator+(tank1);    // alternate syntax
    
    cout << "TANK 3" << endl
    << "  Gallons: " << tank3.get_gallons() << endl
    << "  Liters:  " << tank3.get_liters() << endl << endl;
    
    cout << "Tank 1 pre  increment: " << tank1++.get_gallons() << endl;
    cout << "Tank 1 post increment: " << tank1.get_gallons() << endl;
    
    if (tank1 < tank2) {
        cout << "Tank 1 has less fuel than tank 2.\n\n";
    }
    else if (tank1 > tank2) {
        cout << "Tank 1 has more fuel than tank 2.\n\n";
    }
    else if (tank1 == tank2) {
        cout << "Tank 1 has the same amount of fuel as tank 2.\n\n";
    }
    
    FuelTank tank4, tank5;
    tank4.set_gallons(400);
    tank5.set_gallons(500);
    // cin >> tank4 >> tank5;       // uncomment to test extraction operator
    cout << "TANK 4\n" << tank4;
    cout << "TANK 5\n" << tank5;
    
    return 0;
}

