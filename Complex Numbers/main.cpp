#include <iostream>
#include "MyComplex.hpp"
using namespace std;
int main()
{
    Complex c1, c2, c3;
    c1.real = 2;
    c1.imag = 5;
    c1.printComplex();

    c2.real = 3;
    c2.imag = 5;
    c2.printComplex();

    c3.add(c1, c2);
    c3.sub(c1, c2);
    c3.mul(c1, c2);
    c3.div(c1, c2);
    c3.norm(c1);
    c1.conjugate();

    return 0;
}