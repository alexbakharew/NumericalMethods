#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
class Reader
{
public:
    Reader(){}

    friend std::ostream& operator << (std::ostream& os, const Reader& rd)
    {
        for(auto i : rd.buffer)
        {
            os << i << " ";
        }
        os << "\n";
        return os;
    }

    friend std::istream& operator >> (std::istream& is, Reader& rd)
    {
        std::string tmp;
        int count = 0;
        while(count < 5)
        {
            is >> tmp;
            rd.buffer.push_back(tmp);
            ++count;
        }
        return is;
    }

private:

    std::vector<std::string> buffer;
};

int main()
{
    Reader rd;
    // std::fstream is(std::ctime(0));
    // is >> rd;
    // std::cout << rd;
    time_t t = std::time(0);
    std::string date = std::ctime(&t) + std::string("LU");
    std::cout << date << std::endl;
    return 0;
}