#include <cmath>
#include "complex.h"
#include "eigenvalues.h"
inline int sign(double val) {return val < 0 ? -1 : 1;}

std::vector<Complex> SquareEqutation(double x_11, double x_12, double x_21, double x_22)
{
    std::vector<Complex> res;
    double a = 1;
    double b = - x_11 - x_22;
    double c = (x_11 * x_22) - (x_21 * x_12);
    double D = b * b - 4 * a * c;
    if(D > 0)
    {
        res.reserve(2);
        res[0] = ((- b) + sqrt(D)) / 2 * a;
        res[1] = ((- b) - sqrt(D)) / 2 * a;
    }
    else if(D == 0)
    {
        res.push_back((- b) / 2 * a);
    }
    else
    {
        res.resize(2);
        res[0] = (Complex(D).sqrtc() - b) / (2 * a);
        res[1] = ((Complex(D).sqrtc() + b) * (-1)) / (2 * a);

    }
    return res;
}

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
        double fi = 0.5 * atan(2 * A[x][y] / (A[x][x] - A[y][y]));
        U[x][x] = cos(fi);
        U[x][y] = -sin(fi);
        U[y][x] = sin(fi);
        U[y][y] = cos(fi);

        A = U.Transposing() * A * U;

        curr_epsilon = 0;
        for(int t = 0; t < dim; ++t)
        {
            for(int r = 0; r < t; ++r)
            {
                curr_epsilon += A[t][r] * A[t][r];
            }
        }
        curr_epsilon = sqrt(curr_epsilon);
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
    return std::array<Matrix, 2>{Q, A};
}


std::vector<Complex> QR::FindEigenvalues(const Matrix& m, const double epsilon)
{
    Matrix A = m;
    auto get_epsilon = [&A](int column)
    {
        double res = 0;
        for(int i = 0; i < A.GetDim() - 1; ++i)
        {
            res += A[i + 1][column] * A[i + 1][column];
        }
        return sqrt(res);
    };

    double curr_epsilon = get_epsilon(0);
    int col = 0;//current column
    Complex prev_lambda = 10000000;
    while(col != A.GetDim() - 1)
    {
        std::array<Matrix, 2> qr = QR::FindQR(A);
        A = qr[1] * qr[0] ;
        curr_epsilon = get_epsilon(col);
        if(curr_epsilon < epsilon)
            ++col;// real root
        else// complex root
        {
            Complex curr_lambda;
            auto res = SquareEqutation(A[col][col], A[col][col+1], A[col+1][col], A[col+1][col+1]);
            curr_lambda = res[0];
            if(curr_lambda.module() - prev_lambda.module() < epsilon)
            {
                col += 2;
            }
            else
            {
                prev_lambda = curr_lambda;
            }
        }
    }
    std::vector<Complex> solution;
    for(int i = 0; i < A.GetDim(); ++i)
    {

        if(i == A.GetDim() - 1)
        {
            solution.push_back(Complex(A[i][i]));
        }
        else if(fabs(A[i + 1][i]) > epsilon) //complex value
        {
            auto res = SquareEqutation(A[i][i], A[i][i+1], A[i+1][i], A[i+1][i+1]);
            for(auto i : res)
            {
                solution.push_back(i);
            }
            i += 1;
        }
        else
        {
            solution.push_back(Complex(A[i][i]));
        }
    }
    return solution;
}
