#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <string>
Matrix::Matrix(const Matrix& m)
{
    dim = m.dim;
    matrix = m.matrix;
}

Matrix::Matrix(uint32_t size) : dim(size)
{
    matrix = std::vector<std::vector<double>> (dim, std::vector<double>(dim, 0));
}
Matrix::Matrix(uint32_t size, double val)
{
    dim = size;
    matrix = std::vector<std::vector<double>> (dim, std::vector<double>(dim, val));
}
std::vector<double>& Matrix::operator[](uint32_t idx)
{
    return matrix[idx];
}
void Matrix::operator=(const Matrix& rval)
{
    matrix = rval.matrix;
    dim = rval.dim;
}
std::ostream& operator << (std::ostream& os, Matrix& m)
{
    auto size = m.matrix.size();
    for(uint32_t i = 0; i < size; ++i)
    {
        for(uint32_t j = 0; j < size; ++j)
        {
            os << std::setprecision(5) << m[i][j];
            if( j == size - 1)
            {
                os << "\n";
            }
            else
            {
                os << " ";
            }
        }
    }
    return os;
}
std::istream& operator >> (std::istream& is, Matrix& m)
{
    is >> m.dim;
    m.matrix.assign(m.dim, std::vector<double>(m.dim, 0));
    for(uint32_t i = 0; i < m.dim; ++i)
    {
        for(uint32_t j = 0; j < m.dim; ++j)
        {
            is >> m[i][j];
        }
    }
    return is;
}
Matrix Matrix::operator*(Matrix &other)
{
    Matrix answer(dim);
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            double res = 0;
            for(int k = 0; k < dim; ++k)
            {
                res += matrix[i][k] * other.matrix[k][j];
            }
            answer[i][j] = res;
        }
    }
    return answer;
}











