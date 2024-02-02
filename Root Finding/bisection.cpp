#include <iostream>
#include "function.hpp"
#include <math.h>
using namespace std;

Function f1;

double tolerence = 0.01;
double c;
void bisection(double a, double b)
{
    if (f1.func(f1.degree, f1.coefficients, a) * f1.func(f1.degree, f1.coefficients, b) >= 0) // if a and b have same signs
    {
        cout << "Incorrect a and b" << endl;
        return;
    }
    while (abs(c)>= tolerence)
    {
        c = (a + b) / 2;
        if (f1.func(f1.degree, f1.coefficients, c) == 0)
        {
            cout << "Root : " << c << endl;
            return;
        }
        else if (f1.func(f1.degree, f1.coefficients, a) * f1.func(f1.degree, f1.coefficients, c) < 0) // if f(a) * f(c) < 0, the root lies in [a, c], so update b = c
        {
            cout << "Root : " << c << endl;
            b = c;
        }
        else // if f(b) * f(c) < 0, the root lies in [c, b], so update a = c
        {
            cout << "Root : " << c << endl;
            a = c;
        }
    }
}

int main()
{
    double a, b;
    a = 0;
    b = 1;
    Function f1;
    int degree;
    cout << "Enter degree: ";
    cin >> degree;
    cout << endl;

    int *coefficients = new int[degree + 1];
    // int len = *(&coefficients + 1) - coefficients;
    // cout << "Length = " << len;
    for (int i = 0; i < degree + 1; i++)
    {
        cout << "Enter coefficient of x ^ " << i << ":";
        cin >> coefficients[i];
        cout << endl;
    }
    cout << "The function is : ";
    f1.printFunction(degree, coefficients);
    cout << endl;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    bisection(a, b);
    cout << "Accurate root is " << c << endl;
    return 0;
}
