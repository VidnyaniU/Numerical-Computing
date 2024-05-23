#include <bits/stdc++.h>
using namespace std;
double lagrangesInterpolation(vector<double> x_i, vector<double> f_x_i, double a)
{
    double f_x = 0.0;
    for (int i = 0; i < x_i.size(); i++)
    {
        double L_i = 0;
        double L_i_numr = 1;
        double L_i_denr = 1;
        for (int j = 0; j < x_i.size(); j++)
        {
            if (i != j)
            {
                L_i_numr *= (a - x_i[j]);
                L_i_denr *= (x_i[i] - x_i[j]);
            }
        }
        L_i = L_i_numr / L_i_denr;
        f_x += f_x_i[i] * L_i;
    }
    return f_x;
}
int main()
{
    vector<double> x_i = {-2, -1, 0, 1};
    vector<double> f_x_i = {16, 1, 0, 1};
    double a = 4;

    cout << lagrangesInterpolation(x_i, f_x_i, a) << endl;

    return 0;
}