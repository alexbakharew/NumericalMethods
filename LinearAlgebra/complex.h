#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex
{
public:
    Complex(){}
    Complex(double re, double im) : real(re), image(im), power(1) {}
    Complex(double val) : real(val), image(0) {}
    Complex operator / (double val);
    Complex operator + (double val);
    Complex operator - (double val);
    Complex operator * (double val);
    Complex sqrtc();
    double module();
    friend std::ostream& operator << (std::ostream& os, const Complex& val);
    friend std::istream& operator >> (std::istream& is, Complex& val);
private:
    double real;
    double image;
    double power;
};

#endif // COMPLEX_H
