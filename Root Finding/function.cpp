#include <iostream>
#include "function.hpp"
using namespace std;
double Function::func(int degree, int *coefficients, double x)
{
    double res = coefficients[degree];
    // int count = degree;
    for (int i = degree - 1; i >= 0; i--)
    {
        res = res * x + coefficients[i];
    }
    return res;
}
void Function::printFunction(int degree, int *coefficients)
{

    for (int i = degree; i >= 0; i--) // suppose degree is 3
    {

        if (coefficients[i] >= 0)
        {
            cout << "+";
        }
        cout << coefficients[i] << "x^" << i;
    }
}
