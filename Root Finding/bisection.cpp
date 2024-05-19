#include "rootFinding.hpp"
#include <math.h>
using namespace std;

vector<double> rootFinding::get_interval()
{
    vector<double> interval(2);
    double x = 0, y = 1;
    while (x > -10 && y < 10)
    {
        if (f(x) * f(y) < 0)
        {
            interval[0] = x;
            interval[1] = y;
            return interval;
        }
        else
        {
            x--;
            y++;
        }
    }
    exit(1);
}

double rootFinding::Bisection(double a, double b)
{
    int iter = 0;
    double m, prev_m = 0.0;
    // double m = 0.0;

    if (f(a) * f(b) >= 0) // if a and b have same signs
    {
        cout << "Incorrect a and b." << endl;
        return 0;
    }

    do
    {
        // cout << "prev_m::" << prev_m << " m :: " << m << endl;

        prev_m = m;
        // cout << "prev_m::" << prev_m << endl;
        iter++;
        m = (a + b) / 2;
        if (f(m) == 0)
        {
            // cout << "Iteration " << iter << " : " << m << endl;
            break;
        }
        if (f(m) * f(a) < 0) // if f(a) * f(m) < 0, the root lies in [a, m], so update b = m
        {
            // cout << "Iteration " << iter << " : " << m << endl;
            b = m;
        }
        else // if f(b) * f(c) < 0, the root lies in [c, b], so update a = c
        {
            // cout << "Iteration " << iter << " : " << m << endl;
            a = m;
        }

    } while (fabs(m - prev_m) > tol);

    return m;
}

double rootFinding ::Bisection()
{
    vector<double> interval(2);
    interval = get_interval();
    a = interval[0];
    b = interval[1];
    return Bisection(a, b);
}