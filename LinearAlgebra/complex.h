#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex
{
public:
    Complex(){}
    Complex(double re, double im) : real(re), image(im) {}
    Complex(double val) : real(val), image(0) {}
    friend std::ostream& operator << (std::ostream& os, const Complex& val);
    friend std::istream& operator >> (std::istream& is, Complex& val);
private:
    double real;
    double image;
};

#endif // COMPLEX_H
