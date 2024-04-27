#include <bits/stdc++.h>
#include "../Matrix.hpp"
using namespace std;
class SolutionOfLE
{
public:
    vector<vector<double>> mat;
    int rows, cols;
    // SolutionOfLE(vector<vector<double>> mat, int rows, int cols);

    bool isDiagonallyDominant(vector<vector<double>> mat, int rows, int cols);
    bool makeDiagonallyDominant(vector<vector<double>> mat, int rows, int cols);
    bool isSymmetric(vector<vector<double>> mat, int rows, int cols);
    int getDiagonallyDominantRowAt(int r);
    void swapRows(int row1, int row2);
    vector<vector<double>> rowReduction(vector<vector<double>> mat, int rows, int cols);
    vector<vector<double>> getTranspose(vector<vector<double>> mat, int rows, int cols);
    vector<double> forwardSubstitution(vector<vector<double>> reducedMat, int rows, int cols);
    vector<double> backSubstitution(vector<vector<double>> reducedMat, int rows, int cols);
    vector<double> gaussianElimination(vector<vector<double>> mat, int rows, int cols);
    vector<double> gauss_jacobi(vector<vector<double>> mat, int rows, int cols);
    vector<double> gauss_seidel(vector<vector<double>> mat, int rows, int cols);
    vector<double> lu_decomposition(vector<vector<double>> mat, int rows, int cols);
    vector<double> cholesky_decomposition(vector<vector<double>> mat, int rows, int cols);
};