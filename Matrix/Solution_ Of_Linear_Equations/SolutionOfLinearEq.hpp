#include <bits/stdc++.h>
#include "../Matrix.hpp"
using namespace std;
class SolutionOfLE
{
public:
    vector<vector<double>> mat;
    int rows, cols;
    bool isDiagonallyDominant();
    bool makeDiagonallyDominant();
    int getDiagonallyDominantRowAt(int r);
    void swapRows(int row1, int row2);
    vector<vector<double>> rowReduction();
    vector<double> backSubstition(vector<vector<double>> reducedMat);
    vector<double> gaussianElimination();
    vector<double> gauss_jacobi();
    vector<double> gauss_seidel();
};