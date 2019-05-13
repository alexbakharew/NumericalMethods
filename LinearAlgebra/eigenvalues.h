#ifndef ROTATIONMETHOD_H
#define ROTATIONMETHOD_H
#include "matrix.h"
#include "complex.h"
#include <array>
#include <vector>
std::vector<Complex> SquareEqutation(double x_11, double x_12, double x_21, double x_22);
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
    std::vector<Complex> FindEigenvalues(const Matrix& m, const double epsilon);
private:
    std::array<Matrix, 2> FindQR(const Matrix& m);
//    std::vector<Complex> SquareEqutation(double a_11, double a_12, double a_21, double a_22);
};

#endif // ROTATIONMETHOD_H
