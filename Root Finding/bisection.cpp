#include <iostream>
#include <math.h>
using namespace std;

// Function f1;
double func(double x)
{
    return 2 * x * x - 1;
    // return 4 * x * x * x - 3 * x;
}
double tolerence;
double c;
double bisection(double a, double b, double tolerence)
{
    if (func(a) * func(b) >= 0) // if a and b have same signs
    {
        cout << "Incorrect a and b." << endl;
        return 0;
    }
    c = a;
    while (b - a >= tolerence)
    {
        c = (a + b) / 2;
        if (func(c) == 0)
        {
            // cout << "Root : " << c << endl;
            break;
        }
        else if (func(c) * func(a) < 0) // if f(a) * f(c) < 0, the root lies in [a, c], so update b = c
        {
            // cout << "Root : " << c << endl;
            b = c;
        }
        else // if f(b) * f(c) < 0, the root lies in [c, b], so update a = c
        {
            // cout << "Root : " << c << endl;
            a = c;
        }
    }

    return c;
}

int main()
{
    double a, b;
    cout << "Enter the values of a and b ";
    cin >> a >> b;
    cout << endl
         << "Enter tolerence: ";
    cin >> tolerence;

    cout << "a = " << a << " :: f(a) = " << func(a) << endl;
    cout << "b = " << b << " :: f(b) = " << func(b) << endl;

    cout << bisection(a, b, tolerence);
    return 0;
}
