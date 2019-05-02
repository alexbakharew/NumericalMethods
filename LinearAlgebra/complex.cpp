#include "complex.h"
#include <iostream>
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
