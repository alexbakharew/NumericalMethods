#ifndef ROTATIONMETHOD_H
#define ROTATIONMETHOD_H
#include "matrix.h"
#include "complex.h"
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
    std::vector<Complex> SquareEqutation(double a_11, double a_12, double a_21, double a_22);
};

#endif // ROTATIONMETHOD_H
