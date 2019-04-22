#include <cmath>
#include <iostream>
#include <limits>
#include "equtationsolver.h"

EqutationSolver::EqutationSolver(double left_margin, double right_margin) : a(left_margin), b(right_margin) {}

double EqutationSolver::Function(const double x)
{
    double res;
    try
    {
        res = sqrt(1 - x * x) - exp(x) + 0.01;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return std::numeric_limits<double>::max();
    }
    return res;
}
double EqutationSolver::FirstDerivation(double x)
{
    double res;
    try
    {
        res = - ((1 / sqrt(1 - x * x)) + exp(x));
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return std::numeric_limits<double>::max();
    }
    return res;
}
double EqutationSolver::SecondDerivation(const double x)
{
    double res;
    try
    {
        res = - (sqrt(pow((1 - x * x), 3)) + exp(x));
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return std::numeric_limits<double>::max();
    }
    return res;
}
double EqutationSolver::NewtonMethod(double epsilon)
{
    double x_0;
    for(double i = a; i < b; i += epsilon)
    {
        if(Function(i) * SecondDerivation(i) < 0)
        {
            x_0 = i;
            break;
        }
    }
    double curr_epsilon;
    double curr_x;
    double prev_x = x_0;
    do
    {
        curr_x = prev_x - (Function(prev_x) / FirstDerivation(prev_x));
        curr_epsilon = curr_x - prev_x;
        prev_x = curr_x;
    }
    while(fabs(curr_epsilon) > fabs(epsilon));
    return curr_x;
}
