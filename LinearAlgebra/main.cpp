#include <iostream>
#include "matrix.cpp"
#include "lu.h"
int main()
{
    Matrix m;
    std::cin >> m;
    LU lu(m);
    Matrix L =  lu.GetL();
    Matrix U = lu.GetU();
    std::cout << "Matrix L\n" << L;
    std::cout << "Matrix U\n" << U;
    std::cout << "d = " << lu.Determinator() << std::endl;

    Matrix mult = L * U;
    std::cout << "Matrix L * U\n" << mult;
//    std::vector<double> b{2, 5, 6};
//    auto solve = lu.SolveEqutation(b);
//    std::cout << "x = ";
//    for(auto i : solve)
//    {
//        std::cout << i << " ";
//    }
//    std::cout << "\n";
    return 0;
}
