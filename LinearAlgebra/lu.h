#ifndef LU_H
#define LU_H
#include <vector>
#include "matrix.h"
class LU
{
public:
    LU(){}
    LU(const Matrix& A);
    LU(const Matrix& L, const Matrix& U, const std::vector<double> p);
    ~LU();
public:
    double Determinator() const;
    Matrix Reverse() const;
    Vector SolveEqutation(const Vector& b) const;
    Matrix GetL() const;
    Matrix GetU() const;
    Vector GetP() const;
private:
    Matrix L;
    Matrix U;
    std::vector<double> P;
    uint32_t dim;
};

#endif // LU_H
