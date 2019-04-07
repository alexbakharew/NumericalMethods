#include "logger.h"
#include <iomanip>
Logger::Logger(const std::string& file_name)
{
    out_file = std::fstream(file_name, std::fstream::out);
}

size_t Logger::Write(const std::vector<double> &v)
{
    size_t size = 0;
    for(auto i : v)
    {
        out_file << std::setprecision(3) << i << "   ";
        ++size;
    }
    out_file << "\n";
    return size;
}

size_t Logger::Write(const Matrix &m)
{
    size_t size = 0;
    for(auto i : m.matrix)
    {
        size += Write(i);
    }
    out_file << "\n";
    return size;
}

size_t Logger::Write(const Tridiagonal &td)
{
    size_t size = 0;
    for(auto i : td.coeffs)
    {
        size += Write(i);
    }
    return size;
}
size_t Logger::Write(const std::string &text)
{
    out_file << text << "\n";
    return text.size();
}
