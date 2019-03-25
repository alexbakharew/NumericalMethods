#include <iostream>
#include "matrix.cpp"
#include "lu.h"
int main()
{
    Matrix m, n, k;
    std::cin >> m;
//    n = m;
//    k = m;
//    std::cout << n;


    LU lu(m);
    Matrix L =  lu.GetL();
    Matrix U = lu.GetU();
    std::cout << "Matrix L\n" << L;
    std::cout << "Matrix U\n" << U;
    std::cout << "d = " << lu.Determinator() << std::endl;
    return 0;
}
