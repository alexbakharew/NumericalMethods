#include "tridiagonal.h"
#include "matrix.h"
Tridiagonal::Tridiagonal(Matrix& m) : dim(m.GetDim())
{
    coeffs.resize(dim);
    coeffs[0].push_back(m[0][0]);
    coeffs[0][1] = m[0][1];
    for(int i = 1; i < m.GetDim() - 1; ++i)
    {

    }
}
std::vector<double> Tridiagonal::SolveEqutation(std::vector<double> &b)
{
    std::vector<double> P(dim);
    std::vector<double> Q(dim);
//    P[0] =
}
