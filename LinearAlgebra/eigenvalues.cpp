#include <cmath>
#include "eigenvalues.h"
inline int sign(double val) {return val < 0 ? -1 : 1;}
std::vector<double> RotationMethod::FindEigenvalues(const Matrix& m, const double epsilon)
{
    Matrix A = m;
    double curr_epsilon = 0;
    auto dim = A.GetDim();
    do
    {
        int x = 0, y = 1;
        for(int i = 0; i < dim; ++i)
        {
            for(int j = 0; j < dim; ++j)
            {
                if(i == j)
                    continue;
                if(fabs(A[i][j]) > fabs(A[x][y]))
                {
                    x = i;
                    y = j;
                }
            }
        }
        Matrix U(dim, 0);
        for(int k = 0; k < dim; ++k)
        {
            U[k][k] = 1;
        }
        double fi = 0.5 * atanf(2 * A[x][y] / (A[x][x] - A[y][y]));
        U[x][x] = cosf(fi);
        U[x][y] = -sinf(fi);
        U[y][x] = sinf(fi);
        U[y][y] = cosf(fi);

        A = U.Transposing() * A * U;

        curr_epsilon = 0;
        for(int t = 0; t < dim; ++t)
        {
            for(int r = 0; r < t; ++r)
            {
                curr_epsilon += A[t][r] * A[t][r];
            }
        }
        curr_epsilon = sqrtf(curr_epsilon);
    }
    while(curr_epsilon > epsilon);
    std::vector<double> res(dim);
    for(int i = 0; i < dim; ++i)
    {
        res[i] = A[i][i];
    }
    return res;
}

std::array<Matrix, 2> QR::FindQR(const Matrix &m)
{
    Matrix A = m;
    std::cout << A << std::endl;
    std::cout << "----------------\n";
    auto dim = A.GetDim();
    Matrix Q(dim);
    for(int i = 0; i < dim; ++i)
    {
        Vector v(dim);
        for(int j = 0; j < dim; ++j)
        {
            if(j < i)
            {
                v[j] = 0;
            }
            else if(j == i)// diagonal element
            {
                double norm = 0;
                for(int j1 = j; j1 < dim; ++j1)
                {
                    norm += A[j1][j] * A[j1][j];
                }
                norm = sqrt(norm);
                v[j] = A[i][j] + sign(A[i][j]) * norm;
            }
            else
            {
                v[j] = A[j][i];
            }
        }
        UnitMatrix E(dim);
        Matrix H = E - (std::get<0>(v * v.Transposed()) / std::get<1>(v.Transposed() * v)) * 2;
        if(i == 0)
        {
            Q = H;
        }
        else
        {
            Q = Q * H;
        }
        A = H * A;
    }
    std::cout << Q << "\n" << A << std::endl;
    std::cout << Q * A << std::endl;
    return std::array<Matrix, 2>{Q, A};
}
double QR::GetEpsilon(const Matrix& A)
{
    double res = 0;
    for(int i  = 0; i < A.GetDim(); ++i)
    {
        res += A[0][i] * A[0][i];
    }
}
std::vector<double> QR::FindEigenvalues(const Matrix& m, const double epsilon)
{
    Matrix A = m;
    double curr_epsilon;

    std::array<Matrix, 2> qr = QR::FindQR(A);
    std::cout << qr[0] << " " << qr[1] << std::endl;
    return std::vector<double> {1, 2};
}
