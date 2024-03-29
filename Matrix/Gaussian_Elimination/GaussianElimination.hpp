#include <bits/stdc++.h>
using namespace std;
class GaussianElimination
{
public:
    void printMatrix(string fileName);
    vector<vector<double>> rowReduction(vector<vector<double>> &mat, int nRows, int nCols);
    double *backSubstition(vector<vector<double>> &mat, int nRows, int nCols);
    double *gaussianElimination(vector<vector<double>> &mat, int nRows, int nCols);
};
