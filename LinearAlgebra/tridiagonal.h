#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H
#include "matrix.h"

class Tridiagonal
{
public:
    Tridiagonal(){}
    Tridiagonal( Matrix& m);

    std::vector<double> SolveEqutation(std::vector<double>& b);

private:
    std::vector<std::vector<int>> coeffs;// tridiagonal matrix
    uint32_t dim;
};

#endif // TRIDIAGONAL_H
