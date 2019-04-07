#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdarg>
#include "matrix.h"
#include "tridiagonal.h"
class Logger
{
public:
    Logger(){}
    Logger(const std::string& file_name);
//    friend std::fstream& operator << (std::fstream& os, const Logger file);
    size_t Write(const std::vector<double>& v);
    size_t Write(const Matrix& m);
    size_t Write(const Tridiagonal& td);
    size_t Write(const std::string& text);
public:
    std::fstream out_file;
};

#endif // LOGGER_H
