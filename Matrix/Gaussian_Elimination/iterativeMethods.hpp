#include <bits/stdc++.h>
using namespace std;

class iterativeMethod
{
public:
    bool isDiagonallyDominant(vector<vector<double>> &matLHS);
    vector<double> gauss_jacobi(vector<vector<double>> &mat, int rows, int cols);
    vector<double> gauss_seidel(vector<vector<double>> &mat, int rows, int cols);
};