#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>

class Matrix
{
public:
    Matrix(){}
    Matrix(const Matrix& copy);
    Matrix(uint32_t size);
    Matrix(uint32_t size, double val);
    Matrix(const std::string& input_file);
    ~Matrix(){}

    friend class Logger;
public:
    friend std::ostream& operator << (std::ostream& os, Matrix& m);
    friend std::istream& operator >> (std::istream& is, Matrix& m);
    void operator= (const Matrix& other);
//    std::vector<double>& operator[] (uint32_t) const;
    Matrix operator* (Matrix& other);
    std::vector<double>& operator[] (uint32_t idx);
public:
    inline uint32_t GetDim() const {return dim;}
private:
    std::vector<std::vector<double>> matrix;
    uint32_t dim;
};

#endif // MATRIX_H
