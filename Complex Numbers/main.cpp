#include <iostream>
#include "MyComplex.hpp"
using namespace std;
int main()
{
    Complex c1, c2, c3;
    c1.real = 2;
    c1.imag = 5;
    cout << "c1: ";

    c1.printComplex();

    c2.real = 3;
    c2.imag = 5;
    cout << "c2: ";
    c2.printComplex();

    cout << "Addition: ";
    c3.add(c1, c2);
    c3.printComplex();

    cout << "Subtraction: ";
    c3.sub(c1, c2);
    c3.printComplex();

    cout << "Multiplication: ";
    c3.mul(c1, c2);
    c3.printComplex();

    cout << "Division: ";
    c3.div(c1, c2);
    c3.printComplex();

    cout << "Norm: ";
    c3.norm(c1);
    c3.printComplex();

    cout << "Conjugate of c1: ";
    c1.conjugate();
    c1.printComplex();

    cout << "Conjugate of c2: ";
    c2.conjugate();
    c2.printComplex();

    return 0;
}
