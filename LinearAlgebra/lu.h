#ifndef LU_H
#define LU_H
#include <vector>
#include "matrix.h"
class LU
{
public:
    LU(){}
    LU(const Matrix& A);
    LU(const Matrix& L, const Matrix& U);
    ~LU();
public:
    double Determinator();
    Matrix Reverse() const;
    std::vector<double> SolveEqutation(const std::vector<double>& b);
    Matrix GetL() const;
    Matrix GetU() const;
private:
    Matrix L;
    Matrix U;
    uint32_t dim;
};

#endif // LU_H
