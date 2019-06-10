#ifndef BOOSTEDMATRIX_H
#define BOOSTEDMATRIX_H
#include <iostream>
#include <vector>
template <class T>
class BoostedMatrix
{
public:
    BoostedMatrix(){}
    ~BoostedMatrix(){}
    BoostedMatrix(size_t m_dim, size_t n_dim) : m(m_dim), n(n_dim){}
    void operator += (const BoostedMatrix<T>& m);
    template <typename U>
    friend std::ostream& operator << (std::ostream& os, const BoostedMatrix<U>& m);
    template <typename U>
    friend std::istream& operator >> (std::istream& is, BoostedMatrix<U>& m);
private:
    std::vector<std::vector<T>> matrix;
    size_t m;
    size_t n;
};

#endif // BOOSTEDMATRIX_H
