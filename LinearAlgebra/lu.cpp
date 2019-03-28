#include "lu.h"
#include "matrix.h"
LU::~LU(){}
LU::LU(const Matrix& l, const Matrix& u) : L(l), U(u), dim(L.GetDim()){}
LU::LU(const Matrix& m)
{
    dim = m.GetDim();
    U = m;
    L = Matrix(dim, 0);
    for(uint32_t i = 0; i < dim; ++i)
    {
        L[i][i] = 1;
        for(uint32_t j = i + 1; j < dim; ++j)
        {
            double m = U[j][i] / U[i][i];
            U[j][i] = 0;
            L[j][i] = m;
            for(uint32_t k = i + 1; k < dim; ++k)
            {
                U[j][k] -= m * U[i][k];
            }
        }
    }
}

Matrix LU::GetL() const
{
    return L;
}
Matrix LU::GetU() const
{
    return U;
}

double LU::Determinator()
{
    double d = 1;
    for(int i = 0; i < dim; ++i)
    {
        d *= L[i][i] * U[i][i];
    }
    return d;
}

std::vector<double> LU::SolveEqutation(const std::vector<double> &b)
{
    // Ax = b, LUx = b
    // Ly = b, Ux = y
    std::vector<double> y(dim, 0);
    y[0] = b[0];
    for(int i = 1; i < dim; ++i)
    {
        double res = b[i];
        for(int j = 0; j < i; ++j)
        {
            res -= L[i][j] * y[j];
        }
        y[i] = res;
    }
    std::vector<double> x(dim, 0);

    x[dim - 1] = y[dim - 1] / U[dim - 1][dim - 1];
    for(int i = dim - 2; i >= 0; --i)
    {
        double res = y[i];
        for(int j = i + 1; j < dim; ++j)
        {
            res -= U[i][j] * x[j];
        }
        x[i] = res / U[i][i];
    }
    return x;
}
