#include <bits/stdc++.h>
using namespace std;

class Jacobi
{
public:
    bool isDiagonallyDominant(vector<vector<double>> &matLHS);
    vector<double> gaussJacobi(vector<vector<double>> &mat, int rows, int cols);
};