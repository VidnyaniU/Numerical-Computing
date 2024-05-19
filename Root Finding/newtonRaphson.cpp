#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// double func(double x)
// {
//     return (2 * (x * x) - 1);
// }

// double fDerivative(double x)
// {
//     return (4 * x);
// }

// double Newton_Raphson(double xn, double epsilon)
// {
//     double xn1 = 0;
//     int counter = 0;
//     xn1 = xn - func(xn) / fDerivative(xn);
//     while (xn1 >= epsilon)
//     {
//         xn = xn1;
//         xn1 = xn - func(xn) / fDerivative(xn);
//         counter++;
//     }
//     cout << "counter::" << counter << endl;
//     return xn;
// }
// int main()
// {
//     double root = newtonRaphson(1.0, 0.7071);
//     cout << "Root is :: " << root << endl;
//     return 0;
// }