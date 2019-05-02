#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "lu.h"
#include "tridiagonal.h"
#include "equtationsolver.h"
#include "eigenvalues.h"
bool CheckFile(const std::fstream& file, const std::string& name)
{
    if(!file.is_open())
    {
        std::cout << "Failed to open file: " << name << std::endl;
        return false;
    }
    else
        return true;
}

bool OpenFiles(std::fstream& in, std::fstream& out, const std::string& in_file, const std::string& out_file)
{
    in = std::fstream(in_file);
    out = std::fstream(out_file, std::fstream::out);
    return CheckFile(in, in_file) && CheckFile(out, out_file);
}

void MakeLU()
{
    std::fstream in;
    std::fstream out;
    if(!OpenFiles(in, out, "../LinearAlgebra/Input/lu/1.txt", "../LinearAlgebra/Output/lu.txt"))
        return;

    Matrix m;
    in >> m;
    LU lu(m);
    Matrix L =  lu.GetL();
    Matrix U = lu.GetU();
    Vector P = lu.GetP();
    out << "Initial matrix A\n" << m;
    out << "Matrix L\n" << L << std::endl;
    out << "Matrix U\n" << U << std::endl;
    out << "Vector P = { " << P << "}" << std::endl;
    out << "d = " << lu.Determinator() << "\n";
    Matrix mult = L * U;
    mult.Permutation(P);
    out << "Matrix L * U * P\n" << mult << std::endl;
    out << "Reversed matrix \n" << lu.Reverse() << std::endl;
    out << "A * A^-1 \n" << lu.Reverse() * lu.GetL() * lu.GetU() << std::endl;
    Vector b;
    in >> b;
    auto solve = lu.SolveEqutation(b);
    out << "x = { " << solve << "}" << std::endl;
    std::cout <<"OK\n";
}

void MakeTridiagonal()
{
    std::fstream in;
    std::fstream out;
    if(!OpenFiles(in, out, "../LinearAlgebra/Input/tridiagonal/1.txt", "../LinearAlgebra/Output/td.txt"))
        return;

    Matrix m;
    in >> m;
    out << "Matrix M\n" << m << std::endl;
    Tridiagonal td(m);
    out << "b = 6 3 8 5" << std::endl;
    Vector x = td.SolveEqutation(std::vector<double>{6, 3, 8, 5});
    out << "x = " << x << std::endl;
    std::cout << "OK\n";
}

void MakeSimpleIteration()
{
    std::fstream in;
    std::fstream out;

    if(!OpenFiles(in, out, "../LinearAlgebra/Input/solverequtation/1.txt", "../LinearAlgebra/Output/sim_iter.txt"))
        return;

    Matrix A;
    Vector b;
    long double epsilon;

    in >> A >> b >> epsilon;
    out << "matrix A\n" << A << "b = " << b << "\n" << "epsilon " << epsilon << "\n";
    Vector res = SimpleIteration::SolveEqutation(A, b, epsilon);
    out << "res " << res;
    std::cout << "OK" << std::endl;
    return;
}

void MakeZeydel()
{
    std::fstream in;
    std::fstream out;

    if(!OpenFiles(in, out, "../LinearAlgebra/Input/solverequtation/1.txt", "../LinearAlgebra/Output/zeydel.txt"))
        return;

    Matrix A;
    Vector b;
    long double epsilon;

    in >> A >> b >> epsilon;
    out << "matrix A\n" << A << "b = " << b << "\n" << "epsilon " << epsilon << "\n";
    Vector res = Zeydel::SolveEqutation(A, b, epsilon);
    out <<"res " << res;
    std::cout << "OK" << std::endl;
    return;
}

void MakeRotationMethod()
{
    std::fstream in;
    std::fstream out;

    if(!OpenFiles(in, out, "../LinearAlgebra/Input/eigenvalues/2.txt", "../LinearAlgebra/Output/rotation.txt"))
        return;

    Matrix A;
    double epsilon;

    in >> A >> epsilon;
    out << "matrix A\n" << A  << "epsilon " << epsilon << "\n";
    auto res = RotationMethod::FindEigenvalues(A, epsilon);
    out <<"res " << Vector(res);
    std::cout << "OK" << std::endl;
    return;
}
void MakeQR()
{
    std::fstream in;
    std::fstream out;

    if(!OpenFiles(in, out, "../LinearAlgebra/Input/eigenvalues/qr/1.txt", "../LinearAlgebra/Output/qr.txt"))
        return;

    Matrix A;
    double epsilon;

    in >> A >> epsilon;
    out << "matrix A\n" << A  << "epsilon " << epsilon << "\n";
    auto res = QR::FindEigenvalues(A, 0.1);
//    out <<"res " << Vector(res);
    std::cout << "OK" << std::endl;
}
int main()
{
    int method = 5;

    switch(method)
    {
        case 0:
        {
            MakeLU();
            break;
        }

        case 1:
        {
            MakeTridiagonal();
            break;
        }

        case 2:
        {
            MakeSimpleIteration();
            break;
        }
        case 3:
        {
            MakeZeydel();
            break;
        }
        case 4:
        {
            MakeRotationMethod();
            break;
        }
        case 5:
        {
            MakeQR();
            break;
        }
        case 10:
        {
            Matrix Q, R;
            std::cin >> Q >> R;
            std::cout << Q * R << std::endl;
            break;
        }

        default:
        {
            MakeLU();
            MakeTridiagonal();
            MakeSimpleIteration();
            MakeZeydel();
        }
    }

    return 0;
}
