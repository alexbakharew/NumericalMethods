#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
class Matrix
{
public:
    Matrix(){}
    Matrix(const Matrix&);
    Matrix(uint32_t size);
    Matrix(uint32_t size, double val);
    ~Matrix(){}
public:
    friend std::ostream& operator << (std::ostream&, Matrix&);
    friend std::istream& operator >> (std::istream&, Matrix&);
    void operator= (const Matrix&);
    std::vector<double>& operator[] (uint32_t) ;
public:
    inline uint32_t GetDim() const {return dim;}
private:
    std::vector<std::vector<double>> matrix;
    uint32_t dim;
};

#endif // MATRIX_H
