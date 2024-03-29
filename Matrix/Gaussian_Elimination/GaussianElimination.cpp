#include <bits/stdc++.h>
#include "GaussianElimination.hpp"
// #include "Matrix.hpp"
using namespace std;

vector<vector<double>> GaussianElimination::rowReduction(vector<vector<double>> &mat, int nRows, int nCols)
{
    int i, j;
    // reduce to lower triangular
    int r = 0;
    while (r < nRows)
    {
        // code for pivot goes here
        double pivot = mat[r][r];
        for (i = 0; i < nCols; i++)
        {
            if (mat[r][r] != 0)
            {
                mat[r][i] = mat[r][i] / pivot;
            }
        }

        // row transformation
        for (i = r + 1; i < nRows; i++)
        {
            double temp = mat[i][r];

            for (j = r; j < nCols; j++)
            {
                mat[i][j] = mat[i][j] - (temp * mat[r][j]);
            }
        }
        r++;
    }
    return mat;
}

double *GaussianElimination::backSubstition(vector<vector<double>> &mat, int nRows, int nCols)
{
    double *ans = new double[nCols - 2];
    ans[nCols - 2] = mat[nRows - 1][nCols - 1];

    for (int r = nRows - 2; r >= 0; --r)
    {
        double lhs = 0;
        for (int c = r + 1; c < nCols - 1; ++c)
        {
            lhs += mat[r][c] * ans[c];
        }
        // cout << "\n lhs :: " << lhs << endl;

        // update ans
        ans[r] = mat[r][nCols - 1] - lhs;
    }

    // double *ans = new double[nRows];
    // int i, j;
    // for (i = nRows - 1; i >= 0; i--)
    // {
    //     ans[i] = mat[i][nRows];
    //     for (j = i + 1; j < nRows; j++)
    //     {
    //         if (i != j)
    //         {
    //             ans[i] = ans[i] - mat[i][j] * ans[j];
    //         }
    //     }
    //     ans[i] = ans[i] / mat[i][i];
    // }

    return ans;
}

double *GaussianElimination::gaussianElimination(vector<vector<double>> &mat, int nRows, int nCols)
{

    // get row reduced matrix
    vector<vector<double>> reducedMat = rowReduction(mat, nRows, nCols);

    // back substitution
    double *ans = backSubstition(reducedMat, nRows, nCols);

    // delete[] ans;
    return ans;
}
