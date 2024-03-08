#include <bits/stdc++.h>
using namespace std;
class GaussianElimination
{
public:
    void printMatrix(vector<vector<double>> &mat, int nRows, int nCols);
    vector<vector<double>> rowReduction(vector<vector<double>> &mat, int nRows, int nCols);
    void backSubstition(vector<vector<double>> &mat, int nRows);
    void gaussianElimination(vector<vector<double>> &mat, int nRows, int nCols);
};
