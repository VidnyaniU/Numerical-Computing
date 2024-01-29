#include <iostream>
#include "function.hpp"
using namespace std;

Function f1;

double tolerence = 0.01;
double c;
void bisection(double a, double b)
{
    if (f1.func(f1.degree, f1.coefficients, a) * f1.func(f1.degree, f1.coefficients, b) >= 0)
    {
        cout << "Incorrect a and b" << endl;
        return;
    }
    c = a;
}