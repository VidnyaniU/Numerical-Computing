#include <bits/stdc++.h>
using namespace std;

// void printMatrix(vector<double, double> mat, int rows, int cols)
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols - 1; j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// void gaussianElimination(vector<double, double> mat, int nRows, int nCols)
// {
//     // reduce to lower triangular
//     int r = 0, c = 0;
//     while (r < nRows && c < nCols)
//     {
//         // code for pivot goes here
//         int pivot = mat[r][c];
//         for (int i = 0; i < nRows; i++)
//         {
//             if (mat[r][c] != 0)
//             {
//                 mat[r][i] = mat[r][i] / pivot;
//             }
//         }

//         // row transformation
//         for (int i = r + 1; i < nRows; i++)
//         {
//             int temp = mat[i][c];

//             for (int j = 0; j < nCols; j++)
//             {
//                 mat[i][j] = mat[i][j] + ((-temp) * mat[r][j]);
//             }
//         }
//         r++;
//         c++;
//     }

//     for (int i = 0; i < nRows; i++)
//     {
//         for (int j = 0; j < nCols; j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     // back substitution
// }
int main()
{
    string fileName_L = "matrixL.txt";
    string fileName_R = "matrixR.txt";

    ifstream fin;
    fin.open(fileName_L);

    int rows, cols;
    fin >> rows >> cols;

    vector<double, double> mat;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            fin >> mat[i][j];
        }
    }
    // printMatrix(mat, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    fin.close();

    // augmented col
    fin.open(fileName_R);
    for (int i = 0; i < rows; i++)
    {
        fin >> mat[i][cols - 1];
    }

    cout << "After Augmentation:: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}