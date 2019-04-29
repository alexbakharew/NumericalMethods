#ifndef EQUTATIONSOLVER_H
#define EQUTATIONSOLVER_H


class EqutationSolver
{
public:
    EqutationSolver(){}
    EqutationSolver(double left_margin, double right_margin);
    ~EqutationSolver(){}
    double NewtonMethod(const double epsilon);
    double SimpleIterationMethod(const double epsilon);
    double Function(const double x); // Place your function here
    double FirstDerivation(const double x);
    double SecondDerivation(const double x);
private:
    double a;
    double b;
};

#endif // EQUTATIONSOLVER_H
