#ifndef EQUTATIONSOLVER_H
#define EQUTATIONSOLVER_H


class EqutationSolver
{
public:
    EqutationSolver(double a, double b);
    ~EqutationSolver();
    double NewtonMethod(double epsilon);
    double SimpleIterationMethod(double epsilon);
    double Function(double x) {return x;} // Place your function here
private:
    double a;
    double b;
};

#endif // EQUTATIONSOLVER_H
