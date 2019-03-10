#ifndef MURACH_TEMP_H
#define MURACH_TEMP_H

class Temp
{
private:
    double celsius;
    double fahrenheit;
public:
    Temp();
    void set_celsius(double celsius_param);
    double get_celcius() const;
    void set_fahrenheit(double fahrenheit_param);
    double get_fahrenheit() const;
};

#endif // MURACH_TEMP_H