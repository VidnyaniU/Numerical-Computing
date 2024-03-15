#include <bits/stdc++.h>
#include "GaussianElimination.hpp"
using namespace std;

void GaussianElimination::printMatrix(vector<vector<double>> &mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

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

void GaussianElimination::backSubstition(vector<vector<double>> &mat, int nRows)
{
    double *ans = new double[nRows];
    int i, j;
    for (i = nRows - 1; i >= 0; i--)
    {
        ans[i] = mat[i][nRows];

        for (j = i + 1; j < nRows; j++)
        {
            if (i != j)
            {
                ans[i] = ans[i] - mat[i][j] * ans[j];
            }
        }
        ans[i] = ans[i] / mat[i][i];
    }

    // print the solution
    cout << "Solution of the given system :: " << endl;
    for (int i = 0; i < nRows; i++)
    {
        cout << "X" << i + 1 << " = " << ans[i] << endl;
    }

    delete[] ans;
}

void GaussianElimination::gaussianElimination(vector<vector<double>> &mat, int nRows, int nCols)
{
    // get row reduced matrix
    vector<vector<double>> reducedMat = rowReduction(mat, nRows, nCols);

    // print reduced matrix

    printMatrix(reducedMat, nRows, nCols);

    // back substitution
    backSubstition(mat, nRows);
}
