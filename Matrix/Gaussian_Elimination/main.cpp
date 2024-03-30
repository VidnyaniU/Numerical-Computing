#include <bits/stdc++.h>
#include "../Matrix.hpp"
#include "GaussianElimination.hpp"
#include "jacobi.hpp"
using namespace std;

int main()
{
    // string L_3 = "matrixL.txt";
    // string R_3 = "matrixR.txt";

    string L_3 = "L_3.txt"; // especially for gauss-jacobi
    string R_3 = "R_3.txt";

    string L_4 = "matrixL_4.txt";
    string R_4 = "matrixR_4.txt";

    string L_49 = "L_49_49.txt";
    string R_49 = "R_49.txt";

    string L_225 = "L_225_225.txt";
    string R_225 = "R_225.txt";

    // string L_2304 = "L_matrxi_2304.txt";
    // string R_2304 = "R_rhsvect_2304.txt";

    string fileName_L = L_3;
    string fileName_R = R_3;

    ifstream fin;
    fin.open(fileName_L);

    int rows, cols;
    fin >> rows >> cols;
    // cout << rows << "::" << cols << endl;
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

    // Gaussian Elimination Object
    GaussianElimination ob1;

    vector<double> ansGE = ob1.gaussianElimination(mat, rows, cols); // solution of the system

    // ofstream fout;
    // fout.open("output.txt");
    // print the solution

    // fout << "Solution of the given system :: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     fout << "X" << i + 1 << " = " << ans[i] << endl;
    // }
    // fout.close();
    // cout << "Output has been sent to the file successfully!" << endl;
    cout << "Solution of the given system by gaussian elimination:: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ansGE[i] << endl;
    }
    cout << endl;

    Jacobi ob2;
    vector<double> ansGJ = ob2.gaussJacobi(mat, rows, cols);
    cout << "Solution of the given system by gauss-jacobi iterative method:: " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ansGJ[i] << endl;
    }
    cout << endl;
    return 0;
}
