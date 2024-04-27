#include "SolutionOfLinearEq.hpp"
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

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Gaussian Elimination Object
    SolutionOfLE ob1;

    vector<double> ansGE(rows);
    ansGE = ob1.gaussianElimination(mat, rows, cols); // solution of the system

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
    //==================================================================================
    cout << "Solution of the given system by Gaussian Elimination:: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ansGE[i] << endl;
    }
    cout << endl;

    // vector<double> ansGJ(rows);
    // ansGJ = ob1.gauss_jacobi(mat, rows, cols);
    // cout << "Solution of the given system by Gauss-Jacobi iterative method:: " << endl;

    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ansGJ[i] << endl;
    // }
    // cout << endl;

    // vector<double> ansGS(rows);
    // ansGS = ob1.gauss_seidel(mat, rows, cols);
    // cout << "Solution of the given system by Gauss-Seidel iterative method:: " << endl;

    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ansGS[i] << endl;
    // }
    // cout << endl;
    //============================================================================================
    // LU not working check get_L and get_U
    // vector<double> ansLU(rows);
    // ansLU = ob1.lu_decomposition(mat, rows, cols);
    // cout << "Solution of the given system by LU decomposition:: " << endl;

    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ansLU[i] << endl;
    // }
    // cout << endl;

    vector<double> ansCD(rows);
    ansCD = ob1.cholesky_decomposition(mat, rows, cols);
    cout << "Solution of the given system by Cholesky decomposition:: " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ansCD[i] << endl;
    }
    cout << endl;
    return 0;
}
