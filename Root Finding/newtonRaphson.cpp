#include "rootFinding.hpp"
using namespace std;

double rootFinding::Newton_Raphson()
{
    double prev;
    int iter = 0;
    do
    {
        prev = x0;
        x0 = x0 - (f(x0) / f_dash(x0));
        iter++;
    } while (fabs(x0 - prev) > tol);
    // cout << "Iterations ::" << iter << endl;
    return x0;
}
