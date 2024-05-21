// #include <cstdlib>
#include "Matrix.hpp"
using namespace std;

int main()
{
    string L_3 = "L_3.txt";
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
    // cout << "Row :: " << rows << " Cols :: " << cols << endl;

    Matrix obj_GE(fileName_L, fileName_R);
    Matrix obj_GJ(fileName_L, fileName_R);
    Matrix obj_GS(fileName_L, fileName_R);
    Matrix obj_LU(fileName_L, fileName_R);

    string const HOME = getenv("HOME") ? getenv("HOME") : ".";

    // std::ifstream myfile(HOME + "/path/in/home/folder.txt");
    string L_3_S = "/Documents/GitHub/Numerical-Computing/Matrix/matrices_txt/L_3_Symmetric.txt";
    string R_3_S = "/Documents/GitHub/Numerical-Computing/Matrix/matrices_txt/R_3_Symmetric.txt";

    fileName_L = L_3_S;
    fileName_R = R_3_S;

    Matrix obj_CH(HOME + fileName_L, HOME + fileName_R);
    // cout << "L :: " << HOME + fileName_L << "R :: " << HOME + fileName_R << endl;
    vector<double> ans_GE(rows);
    vector<double> ans_GJ(rows);
    vector<double> ans_GS(rows);
    vector<double> ans_LU(rows);
    vector<double> ans_CH(rows);

    // ans_GE = obj_GE.gaussian_elimination();

    // cout << "Solution of the given system by Gaussian Elimination:: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ans_GE[i] << endl;
    // }
    // cout << endl;

    // ans_GJ = obj_GJ.gauss_jacobi();

    // cout << "Solution of the given system by Gauss-Jacobi :: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ans_GJ[i] << endl;
    // }
    // cout << endl;

    // ans_GS = obj_GS.gauss_seidel();

    // cout << "Solution of the given system by Gauss-Seidel :: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ans_GS[i] << endl;
    // }
    // cout << endl;

    // ans_LU = obj_GS.lu_decomposition();

    // cout << "Solution of the given system by LU Decomposition :: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << ans_LU[i] << endl;
    // }
    // cout << endl;

    rows = 3, cols = 4;
    ans_CH = obj_CH.cholesky_decomposition();
    cout << "Solution of the given system by Cholesky Decomposition :: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ans_CH[i] << endl;
    }
    cout << endl;
    return 0;
}