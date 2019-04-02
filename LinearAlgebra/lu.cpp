#include <chrono>
#include "lu.h"
#include "matrix.h"
#include "logger.h"

LU::~LU(){}
LU::LU(const Matrix& l, const Matrix& u, const std::vector<int> p) : L(l), U(u), P(p), dim(L.GetDim()){}
LU::LU(const Matrix& m)
{
    Logger log_file("../LinearAlgebra/Logs/lu.txt");
    dim = m.GetDim();
    U = m;
    L = Matrix(dim, 0);
    P = std::vector<int>(dim, 0);
    for(uint32_t i = 0; i < dim; ++i)
    {
        int max_index = i;
        for(int t = i; t < dim; ++t)
        {
            if(U[t][i] > U[max_index][i])
                max_index = t;
        }
        if(U[max_index][i] != 0)
        {
            std::swap(U[i], U[max_index]);
            std::swap(L[i], L[max_index]);
            P[i] = max_index;
        }
        else
            continue;
        L[i][i] = 1;
        for(uint32_t j = i + 1; j < dim; ++j)
        {
            double m = U[j][i] / U[i][i];
//            U[j][i] = 0;
            L[j][i] = m;
            for(uint32_t k = i; k < dim; ++k)
            {
                U[j][k] -= m * U[i][k];
            }
        }
        log_file.Write("L");
        log_file.Write(L);
        log_file.Write("U");
        log_file.Write(U);
        log_file.Write("-----------");
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

std::vector<int> LU::GetP() const
{
    return P;
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
