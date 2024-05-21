#include <bits/stdc++.h>
#include "/home/vidnyani/Documents/GitHub/Numerical-Computing/Matrix/Matrix.hpp"

using namespace std;
void leastSq(vector<double> x_i, vector<double> f_i)
{
    double n = x_i.size();

    double sum_x_i = accumulate(x_i.begin(), x_i.end(), 0);
    double sum_f_i = accumulate(f_i.begin(), f_i.end(), 0);

    double sum_x_i_sq = 0.0;
    double sum_f_i_x_i = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum_x_i_sq += x_i[i] * x_i[i];
        sum_f_i_x_i += x_i[i] * f_i[i];
    }

    vector<vector<double>> mat = {{sum_x_i_sq, sum_x_i, sum_f_i_x_i}, {sum_x_i, n, sum_f_i}};
    int rows = mat.size();
    int cols = mat[0].size();

    Matrix obj(mat, rows, cols);
    vector<double> a_b(rows);
    a_b = obj.gaussian_elimination();
    double a = a_b[0], b = a_b[1];

    // cout << "a :: " << a << "b :: " << b << endl;

    vector<double> y_i;
    for (int i = 0; i < n; i++)
    {
        double y = a * x_i[i] + b;
        y_i.push_back(y);
    }
    double Sum_Sq_Error = 0.0;
    for (int i = 0; i < n; i++)
    {

        Sum_Sq_Error += (f_i[i] - y_i[i]) * (f_i[i] - y_i[i]);
    }
    cout << "SSE :: " << Sum_Sq_Error << endl;
    double RMSE = sqrt(Sum_Sq_Error / n);
    cout << "RMSE :: " << RMSE << endl;

}
int main()
{
    vector<double> x_i = {-4, -1, 0, 2, 3};
    vector<double> f_i = {-3, -1, 0, 1, 2};
    leastSq(x_i, f_i);

    return 0;
}

/*
command:
/Documents/GitHub/Numerical-Computing$ g++ Matrix/Matrix.cpp Matrix/GaussianElimination.cpp Curve\ Fitting/leastSquareInterpolation.cpp -o ls

*/