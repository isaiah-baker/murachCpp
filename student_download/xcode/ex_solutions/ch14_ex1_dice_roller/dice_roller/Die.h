#ifndef MURACH_DIE_H
#define MURACH_DIE_H

#include <string>

class Die {
private:
    int value;

public:
    Die();
    void roll();
    int get_value() const;
    void set_value(int);
    std::string get_image() const;
};

#endif // MURACH_DIE_H