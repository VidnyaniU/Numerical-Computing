#include <iostream>
#include "function.hpp"
using namespace std;
int main()
{
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

    double x;
    cout << "Enter the value of x: ";
    cin >> x;
    cout << endl;
    double res = f1.func(degree, coefficients, x);
    f1.printFunction(degree, coefficients);
    cout << endl;
    cout << "For x = " << x << " :: Result = " << res << endl;
    return 0;
}
