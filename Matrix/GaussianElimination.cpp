#include "Matrix.hpp"
using namespace std;

vector<double> Matrix::gaussian_elimination()
{
    // get row reduced matrix
    vector<vector<double>> reducedMat(rows, vector<double>(cols));
    reducedMat = rowReduction();
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << reducedMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // // back substitution
    vector<double> ans(rows);
    ans = backSubstitution(reducedMat);

    return ans;
}
