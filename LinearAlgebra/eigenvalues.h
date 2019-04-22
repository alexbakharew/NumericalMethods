#ifndef ROTATIONMETHOD_H
#define ROTATIONMETHOD_H
#include "matrix.h"
#include <array>
#include <vector>
class RotationMethod
{
public:
    RotationMethod(){}
    ~RotationMethod(){}
    static std::vector<double> FindEigenvalues(const Matrix& m, const double epsilon);
};

class QR
{
public:
    static std::vector<double> FindEigenvalues(const Matrix& m, const double epsilon);
private:
    static std::array<Matrix, 2> FindQR(const Matrix& m);
    double GetEpsilon(const Matrix& A);
};

#endif // ROTATIONMETHOD_H
