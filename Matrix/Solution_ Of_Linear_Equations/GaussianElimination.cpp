#include "SolutionOfLinearEq.hpp"
using namespace std;
// SolutionOfLE ::SolutionOfLE(vector<vector<double>> mat, int rows, int cols)

// {
//     mat = mat;
//     rows = rows;
//     cols = cols;
// }
vector<vector<double>> SolutionOfLE::rowReduction(vector<vector<double>> mat, int rows, int cols)
{
    int i, j;
    int r = 0;
    cout << rows << "::" << cols << endl;
    while (r < rows)
    {
        double pivot = mat[r][r];
        if (pivot != 0) // Ensure pivot is not zero
        {
            for (i = 0; i < cols; i++)
            {
                mat[r][i] = mat[r][i] / pivot;
            }

            for (i = r + 1; i < rows; i++)
            {
                double temp = mat[i][r];
                for (j = r; j < cols; j++)
                {
                    mat[i][j] = mat[i][j] - (temp * mat[r][j]);
                }
            }
        }
        r++;
    }
    // cout << "Matrix after row reduction:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         std::cout << mat[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return mat;
}

vector<double> SolutionOfLE::backSubstitution(vector<vector<double>> reducedMat, int rows, int cols)
{
    vector<double> ans(rows);
    ans[rows - 1] = reducedMat[rows - 1][cols - 1];
    for (int r = rows - 2; r >= 0; --r)
    {
        double lhs = 0;
        for (int c = r + 1; c < cols - 1; ++c)
        {
            lhs += reducedMat[r][c] * ans[c];
        }
        ans[r] = reducedMat[r][cols - 1] - lhs;
    }

    return ans;
}

vector<double> SolutionOfLE::gaussianElimination(vector<vector<double>> mat, int rows, int cols)
{
    // get row reduced matrix
    // rowReduction(mat, rows, cols);
    vector<vector<double>> reducedMat = rowReduction(mat, rows, cols);

    // // back substitution
    vector<double> ans = backSubstitution(reducedMat, rows, cols);

    return ans;
}
