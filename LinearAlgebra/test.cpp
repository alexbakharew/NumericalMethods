#include <iostream>
#include <cstdlib>
#include <vector>
#include "matrix.h"
#include <variant>
#include <cassert>
int main()
{
    std::variant<Matrix, double> val;
    val = 8;
    UnitMatrix m(3);
    // val = m;
    std::cout << std::get<0>(val) << std::endl;

    bool is_matrix = false;

    try 
    {
      std::get<double>(val); // w contains int, not float: will throw
    }
    catch (const std::bad_variant_access&) {is_matrix = true;}
    if(is_matrix)
    {
        std::cout << "MATRIX\n";
        std::cout << std::get<0>(val) << std::endl;
    }
    else
    {
        std::cout << "DOUBLE\n";
        std::cout << std::get<double>(val) << std::endl;
    }
    
}