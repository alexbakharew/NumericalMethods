#include <iostream>
#include <cstdlib>
#include <vector>
class Vector
{
public:
    Vector(){}
    Vector(uint32_t size, double val) : dim(size)
    {
        buffer = std::vector<double>(size, val);
    }

    double& operator [] (uint32_t idx)
    {
        return buffer[idx];
    }
    const double& operator [] (uint32_t idx) const
    {
        return buffer[idx];
    }

    friend std::ostream& operator << (std::ostream& os, const Vector& v)
    {
        for(int i = 0; i < v.dim; ++i)
        {
            os << v.buffer[i] << " ";
        }
        return os;
    }

    friend std::istream& operator >> (std::istream& is, Vector& v)
    {
        v.buffer.clear();
        is >> v.dim;

        double val;
        int count = 0;
        while(count++ < v.dim)
        {
            is >> val;
            v.buffer.push_back(val);
        }
        return is;
    }

    inline size_t GetDim() const {return buffer.size();}

private:
    std::vector<double> buffer;
    uint32_t dim;
};
void ReadVector(const Vector& v)
{
    for(int i = 0; i != v.GetDim(); ++i)
    {
        std::cout << v[i] << std::endl;
        // v[i] = 5;
    }
}
int main()
{
    Vector v(10, 89);
    ReadVector(v);
    return 0;
}