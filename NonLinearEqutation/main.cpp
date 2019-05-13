#include <iostream>
#include "equtationsolver.h"

int main()
{
    EqutationSolver instance1(-1, -0.8);
    EqutationSolver instance2(-0.2, 0.2);
    std::cout << instance1.NewtonMethod(0.00001) << std::endl;
    std::cout << instance2.NewtonMethod(0.00001) << std::endl;

    //--------------------------------------------------------

    EqutationSolver instance3(-1, -0.8);
    EqutationSolver instance4(0, 0.15);
    std::cout << instance3.SimpleIterationMethod(0.01)<< std::endl;
    std::cout << instance4.SimpleIterationMethod(0.01) << std::endl;
    return 0;
}
