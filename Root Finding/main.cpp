#include "rootFinding.hpp"
using namespace std;
int main()
{
    rootFinding f1(0.001); // object of the function
    // double a = 0.0, b = 1.0;

    // cout << a << b << endl;
    double root = f1.Bisection();
    cout << "Root using Bisection method :: " << root << endl;

    root = f1.Newton_Raphson();
    cout << "Root using Newton-Raphson method :: " << root << endl;
    return 0;
}