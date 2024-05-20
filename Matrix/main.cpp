#include "Matrix.hpp"
using namespace std;

int main()
{
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
    // cout << "Row :: " << rows << " Cols :: " << cols << endl;

    Matrix obj(fileName_L, fileName_R);

    vector<double> ans(rows);

    ans = obj.gaussian_elimination();

    cout << "Solution of the given system by Gaussian Elimination:: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ans[i] << endl;
    }
    cout << endl;

    ans = obj.gauss_jacobi();

    cout << "Solution of the given system by Gauss-Jacobi :: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ans[i] << endl;
    }
    cout << endl;

    ans = obj.gauss_seidel();

    cout << "Solution of the given system by Gauss-Seidel :: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ans[i] << endl;
    }
    cout << endl;

    return 0;
}