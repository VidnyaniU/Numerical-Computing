#include <bits/stdc++.h>
#include "jacobi.hpp"
using namespace std;

bool Jacobi ::isDiagonallyDominant(vector<vector<double>> &matLHS)
{
    int matLen = matLHS.size();
    cout << matLen << endl;
    for (int i = 0; i < matLen; i++)
    {
        double diagonal = abs(matLHS[i][i]);
        double rowSum = 0.0;

        for (int j = 0; j < matLen; j++)
        {
            if (j != i)
            {
                rowSum += abs(matLHS[i][j]);
            }
        }

        if (diagonal <= rowSum)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // string L_3 = "matrixL.txt";
    // string R_3 = "matrixR.txt";

    string L_4 = "matrixL_4.txt";
    string R_4 = "matrixR_4.txt";

    // string L_49 = "L_49_49.txt";
    // string R_49 = "R_49.txt";

    // string L_225 = "L_225_225.txt";
    // string R_225 = "R_225.txt";

    // string L_2304 = "L_matrxi_2304.txt";
    // string R_2304 = "R_rhsvect_2304.txt";

    string fileName_L = L_4;
    string fileName_R = R_4;

    ifstream fin;
    fin.open(fileName_L);

    int rows, cols;
    fin >> rows >> cols;
    // cout << rows << "::" << cols << endl;
    vector<vector<double>> matLHS(rows, vector<double>(cols - 1));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            fin >> matLHS[i][j];
        }
    }

    fin.close();

    // RHS part
    //  augmented col
    fin.open(fileName_R);
    vector<double> matRHS(cols - 1);
    for (int i = 0; i < rows; i++)
    {
        fin >> matRHS[i];
        // cout << matRHS[i] << " ";
    }
    fin.close();

    // Gaussian Elimination Object
    Jacobi ob1;

    cout << "Is the matrix diagonally dominant?" << ob1.isDiagonallyDominant(matLHS) << endl;

    return 0;
}
