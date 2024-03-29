#include <bits/stdc++.h>
#include "Matrix.hpp"
using namespace std;

// ofstream fout("output.txt");
void Matrix::printMatrix(vector<vector<double>> &mat, int rows, int cols)
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