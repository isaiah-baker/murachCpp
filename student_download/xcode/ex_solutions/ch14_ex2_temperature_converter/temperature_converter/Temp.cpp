#include <cmath>
#include "Temp.h"

using namespace std;

Temp::Temp() {
    celsius = 0.0;
    fahrenheit = 32.0;
}

void Temp::set_celsius(double celsius_param) {
    celsius = celsius_param;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
}

double Temp::get_celcius() const {
    double c = round(celsius * 10) / 10;
    return c;
}

void Temp::set_fahrenheit(double fahrenheit_param) {
    fahrenheit = fahrenheit_param;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

}

double Temp::get_fahrenheit() const {
    double f = round(fahrenheit * 10) / 10;
    return f;
}
