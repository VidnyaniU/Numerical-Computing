#include "SolutionOfLinearEq.hpp"
using namespace std;

vector<vector<double>> SolutionOfLE::rowReduction()
{
    int i, j;
    // reduce to lower triangular
    int r = 0;
    while (r < rows)
    {
        // code for pivot goes here
        double pivot = mat[r][r];
        for (i = 0; i < cols; i++)
        {
            if (mat[r][r] != 0)
            {
                mat[r][i] = mat[r][i] / pivot;
            }
        }

        // row transformation
        for (i = r + 1; i < rows; i++)
        {
            double temp = mat[i][r];

            for (j = r; j < cols; j++)
            {
                mat[i][j] = mat[i][j] - (temp * mat[r][j]);
            }
        }
        r++;
    }
    return mat;
}

vector<double> SolutionOfLE::backSubstition(vector<vector<double>> reducedMat)
{
    vector<double> ans(cols - 2);
    ans[cols - 2] = mat[rows - 1][cols - 1];

    for (int r = rows - 2; r >= 0; --r)
    {
        double lhs = 0;
        for (int c = r + 1; c < cols - 1; ++c)
        {
            lhs += mat[r][c] * ans[c];
        }
        // cout << "\n lhs :: " << lhs << endl;

        // update ans
        ans[r] = mat[r][cols - 1] - lhs;
    }

    return ans;
}

vector<double> SolutionOfLE::gaussianElimination()
{

    // get row reduced matrix
    vector<vector<double>> reducedMat = rowReduction();

    // back substitution
    vector<double> ans = backSubstition(reducedMat);

    return ans;
}
