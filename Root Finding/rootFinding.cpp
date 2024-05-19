#include "rootFinding.hpp"
using namespace std;

rootFinding ::rootFinding(double tolerence)
{
    a = b = 0.0;
    x0 = 1.0;
    tol = tolerence;
}
double rootFinding::f(double x)
{
    return (x * x) - (4 * x) + 2;
}

double rootFinding::f_dash(double x)
{
    return (2 * x) - 4;
}

// for fixed point
double rootFinding ::f_x(double x)
{
    return (x * x + 2) / 4;
}