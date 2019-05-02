#include <iostream>
#include "equtationsolver.h"

int main()
{
    EqutationSolver instance1(-1, -0.8);
    EqutationSolver instance2(-0.2, 0.2);
    std::cout << instance1.NewtonMethod(0.00001) << std::endl;
    std::cout << instance2.NewtonMethod(0.00001) << std::endl;

    //--------------------------------------------------------

    EqutationSolver instance3(-0.4, -0.3);
//    std::cout << instance1.SimpleIterationMethod(0.00001) << std::endl;
//    std::cout << instance.SimpleIterationMethod(0.01) << std::endl;
    return 0;
}
