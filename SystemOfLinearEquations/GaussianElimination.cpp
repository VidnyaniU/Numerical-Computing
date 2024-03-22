#include <bits/stdc++.h>
#include "GaussianElimination.hpp"
using namespace std;

ofstream fout("output.txt");
void GaussianElimination::printMatrix(vector<vector<double>> &mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fout << mat[i][j] << " ";
        }
        fout << endl;
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

void GaussianElimination::gaussianElimination(vector<vector<double>> &mat, int nRows, int nCols)
{
    fout << "No. of rows = " << nRows << "\n"
         << "No. of cols = " << nCols << endl;
    fout << endl
         << "Given matrix :: " << endl;
    printMatrix(mat, nRows, nCols);
    // get row reduced matrix
    vector<vector<double>> reducedMat = rowReduction(mat, nRows, nCols);

    // print reduced matrix
    fout << endl
         << "Matrix after row reduction:: " << endl;
    printMatrix(reducedMat, nRows, nCols);

    // back substitution
    double *ans = backSubstition(reducedMat, nRows, nCols);

    // print the solution
    fout << endl
         << "Solution of the given system :: " << endl;
    for (int i = 0; i < nRows; i++)
    {
        fout << "X" << i + 1 << " = " << ans[i] << endl;
    }
    fout.close();
    delete[] ans;
}
