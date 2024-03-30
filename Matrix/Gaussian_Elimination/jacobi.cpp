#include <bits/stdc++.h>
#include "jacobi.hpp"
using namespace std;

bool Jacobi ::isDiagonallyDominant(vector<vector<double>> &mat)
{
    int matLen = mat.size();
    for (int i = 0; i < matLen; i++)
    {
        double diagonal = abs(mat[i][i]);
        double rowSum = 0.0;

        for (int j = 0; j < matLen - 1; j++)
        {
            if (j != i)
            {
                rowSum += abs(mat[i][j]);
            }
        }

        if (diagonal <= rowSum)
        {
            return false;
        }
    }
    return true;
}
vector<double> Jacobi::gaussJacobi(vector<vector<double>> &mat, int rows, int cols)
{
    int iterations = 11;
    vector<double> x(rows, 0); // initial solution
    vector<double> xUpdated(rows, 0);
    // cout << "isDiagonallyDominant::" << isDiagonallyDominant(mat) << endl;
    if (isDiagonallyDominant(mat))
    {
        for (int iter = 0; iter < iterations; iter++)
        {
            for (int r = 0; r < rows; r++)
            {
                double sum = 0.0;
                for (int c = 0; c < rows; c++)
                {
                    if (c != r)
                    {
                        sum += mat[r][c] * x[c];
                    }
                }
                xUpdated[r] = (mat[r][cols - 1] - sum) / mat[r][r];
            }
            x = xUpdated;
        }
    }
    return xUpdated;
}
