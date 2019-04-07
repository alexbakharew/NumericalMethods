#include <iostream>
#include <fstream>
#include "matrix.cpp"
#include "lu.h"
#include "tridiagonal.h"
#include "simpleiteration.h"
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
    out = std::fstream(out_file);
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
    Tridiagonal td(m);
    Vector x = td.SolveEqutation(std::vector<double>{6, 3, 8, 5});
    out << "x = " << x << std::endl;
    std::cout << "OK\n";
}

void MakeSimpleIteration()
{
    std::fstream in;
    std::fstream out;

    if(!OpenFiles(in, out, "../LinearAlgebra/Input/simpleiteration/1.txt", "../LinearAlgebra/Output/sim_iter.txt"))
        return;

    Matrix A;
    Vector b;
    long double epsilon;

    in >> A >> b >> epsilon;

    Vector res = SimpleIteration::SolveEqutation(A, b, epsilon);
    out << res;
    std::cout << "OK" << std::endl;
    return;
}

void MakeZeydel()
{

}

int main()
{
    int method = -1;

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

        case 10:
        {
            Matrix m;
            std::cin >> m;
            LU lu(m);
            std::cout << lu.Reverse() << std::endl;
            std::cout << m * lu.Reverse() << std::endl;
            break;
        }

        default:
        {
            MakeLU();
            MakeTridiagonal();
            MakeSimpleIteration();
        }
    }

    return 0;
}
