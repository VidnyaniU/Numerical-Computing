#include <bits/stdc++.h>
using namespace std;
class rootFinding
{

public:
    double a, b, x0;
    double tol; // tolerence
    rootFinding(double tol);
    double f(double x);      // function
    double f_dash(double x); // derivative
    double f_x(double x);    // for fixed point iteration

    vector<double> get_interval();
    double Bisection(double a, double b);
    double Bisection();
    double Newton_Raphson();
    double Fixed_Point();
};
