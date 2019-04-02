#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "lu.h"
#include "tridiagonal.h"
int main()
{
    int method = 0;
//    std::cin >> method;

    Matrix m;
    std::ifstream is("../LinearAlgebra/input.txt");
    std::fstream out("../LinearAlgebra/output.txt", std::fstream::out);
    if(is.is_open())
        is >> m;
    else
    {
        std::cout << "Fail while read file. Exit\n";
        return -1;
    }
    if(!out.is_open())
    {
        std::cout << "Fail while open out file. Exit\n";
        return -1;
    }

    switch(method)
    {
        case 0:
        {
            LU lu(m);
            Matrix L =  lu.GetL();
            Matrix U = lu.GetU();
            std::vector<int> P = lu.GetP();
            out << "Matrix L\n" << L;
            out << "Matrix U\n" << U;
            out << "Vector P = {";
            for(int i = 0; i < P.size(); ++i)
            {
                out << P[i];
                if(i == P.size() - 1)
                    out <<"}\n";
                else
                    out << " ";
            }
            out << "d = " << lu.Determinator() << "\n";

            Matrix mult = L * U;
            out << "Matrix L * U\n" << mult;
            std::vector<double> b{2, 5, 6};
            auto solve = lu.SolveEqutation(b);
            out << "x = ";
            for(auto i : solve)
            {
                out << i << " ";
            }
            out << "\n";
            std::cout <<"OK\n";
            break;
        }
        case 1:
        {
            Tridiagonal td(m);
            std::vector<double> x = td.SolveEqutation(std::vector<double>{6, 3, 8, 5});
            out << "x = ";
            for(auto i : x)
            {
                out << i << " ";
            }
            out << "\n";
            std::cout << "OK\n";
            break;
        }
    }


    return 0;
}
