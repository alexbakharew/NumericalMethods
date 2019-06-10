#include "boostedmatrix.h"
#include <thread>
#include <iostream>
#include <functional>
template <typename T>
void add(std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if(lhs.size() != rhs.size())
        return;

    for(int i = 0; i < lhs.size(); ++i)
    {
        lhs[i] += rhs[i];
    }
}
template <class T>
void BoostedMatrix<T>::operator +=(const BoostedMatrix<T>& mat)
{
    std::vector<std::thread> threads(m);
    for(int t = 0; t < m; ++t)
    {
        threads[t] = std::thread(add<T>, std::ref(this->matrix[t]), std::ref(mat.matrix[t]));
    }
    for(int t = 0; t < m; ++t)
    {
        threads[t].join();
    }
//    for(int t = 0; t < m; ++t)
//    {
//        add(this->matrix[t], mat.matrix[t]);
//    }
}
template <class T>
std::ostream& operator << (std::ostream& os, const BoostedMatrix<T>& mat)
{
    for(int i = 0; i < mat.m; ++i)
    {
        for(int j = 0; j < mat.n; ++j)
        {
            os << mat.matrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
template <class T>
std::istream& operator >> (std::istream& is, BoostedMatrix<T>& mat)
{
    is >> mat.m >> mat.n;
    mat.matrix = std::vector<std::vector<T>>(mat.m, std::vector<T>(mat.n));
    for(int i = 0; i < mat.m; ++i)
    {
        for(int j = 0; j < mat.n; ++j)
        {
            is >> mat.matrix[i][j];
        }
    }
    return is;
}
//BoostedMatrix<double> TemplateInitializer();
