#ifndef EQUTATIONSOLVER_H
#define EQUTATIONSOLVER_H


class EqutationSolver
{
public:
    EqutationSolver(){}
    EqutationSolver(double left_margin, double right_margin);
    ~EqutationSolver(){}
    double NewtonMethod(double epsilon);
    double SimpleIterationMethod(double epsilon);
    double Function(double x); // Place your function here
    double FirstDerivation(double x);
    double SecondDerivation(double x);
private:
    double a;
    double b;
};

#endif // EQUTATIONSOLVER_H
