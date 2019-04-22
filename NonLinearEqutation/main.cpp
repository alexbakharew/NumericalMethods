#include <iostream>
#include "equtationsolver.h"

int main()
{
    EqutationSolver instance1(-1.5, -0.5);
    EqutationSolver instance2(-0.5, 0.5);
    std::cout << instance1.NewtonMethod(0.01) << std::endl;
    std::cout << instance2.NewtonMethod(0.01) << std::endl;
//    std::cout << instance.SimpleIterationMethod(0.01) << std::endl;
    return 0;
}
