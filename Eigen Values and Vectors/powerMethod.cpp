#include <bits/stdc++.h>
using namespace std;
// matrix * vector
vector<double> matrix_vector_multiplication(vector<vector<double>> A, vector<double> X)
{
    int n = X.size();
    vector<double> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i] += A[i][j] * X[j];
        }
        // cout << ans[i] << " ";
    }

    return ans;
}
// norm
double norm(vector<double> y)
{
    int ans = 0;
    for (int i = 0; i < y.size(); i++)
    {
        ans += y[i] * y[i];
    }

    return sqrt(ans);
}

// power method
double power_method(vector<vector<double>> A, vector<double> X)
{
    int i = 0, n = X.size();
    double old_eigen_val = 0.0, tolerence = 0.0001;
    while (true)
    {
        // y_i+1 = A*x_i
        vector<double> y = matrix_vector_multiplication(A, X);

        // normalised eigen vector
        double norm_y = norm(y);

        for (int i = 0; i < n; i++)
        {
            X[i] = y[i] / norm_y;
        }
        // compute the approximate eigen value
        vector<double> Ay = matrix_vector_multiplication(A, X);
        double eigen_val = 0.0;
        for (int i = 0; i < n; i++)
        {
            eigen_val += X[i] * Ay[i];
        }

        // tolerence

        if (abs(eigen_val - old_eigen_val) <= tolerence)
        {
            return eigen_val;
        }
        old_eigen_val = eigen_val;
        i++;
    }
}
int main()
{
    vector<vector<double>> A = {{5, 0, 1}, {0, -2, 0}, {1, 0, 5}};
    vector<double> X = {1, 0, 0}; // initialize the x vector
    // matrix_vector_multiplication(A, X);
    // transpose(A);
    cout << "Largest eigen value of the given matrix :: " << power_method(A, X) << endl;

    return 0;
}