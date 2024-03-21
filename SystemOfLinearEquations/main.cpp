#include <bits/stdc++.h>
#include "GaussianElimination.hpp"
using namespace std;

int main()
{
    string fileName_L = "matrixL.txt";
    string fileName_R = "matrixR.txt";

    ifstream fin;
    fin.open(fileName_L);

    int rows, cols;
    fin >> rows >> cols;

    cout << "No. of rows = " << rows << "\n"
         << "No. of cols = " << cols << endl;
    vector<vector<double>> mat(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            fin >> mat[i][j];
        }
    }

    fin.close();

    // augmented col
    fin.open(fileName_R);
    for (int i = 0; i < rows; i++)
    {
        fin >> mat[i][cols - 1];
    }
    fin.close();
    GaussianElimination ob1;
   

    ob1.gaussianElimination(mat, rows, cols);

    return 0;
}