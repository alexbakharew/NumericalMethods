#include "complex.h"
#include <iostream>
#include <cmath>
std::ostream& operator << (std::ostream& os, const Complex& val)
{
    os << val.real;
    if(val.image != 0)
    {
        if(val.image > 0)
        {
            os << "+";
        }
        os << val.image;
    }
    return os;
}
std::istream& operator >> (std::istream& is, Complex& val)
{
    is >> val.real >> val.image;
    return is;
}
Complex Complex::operator / (const double val)
{
    Complex res = *this;
    res.real /= val;
    res.image /= val;
    return res;
}
Complex Complex::operator + (double val)
{
    Complex res;
    res.image = this->image;
    res.real = this->real + val;
    return res;
}
Complex Complex::sqrtc()
{
    Complex res;
    if(real > 0)
    {
        res.real = sqrt(this->real);
    }
    else if(real < 0)
    {
        res.real = sqrt(this->real);
        res.image = 1;
        return res;
    }
    else
    {
        return *this;
    }
}
