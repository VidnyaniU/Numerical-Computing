#include <bits/stdc++.h>
using namespace std;
class Matrix
{
    vector<vector<double>> mat;
    int rows, cols;

public:
    // initialize matrix
    Matrix();
    Matrix(vector<vector<double>> matrix, int row, int col);
    Matrix(string file_L, string file_R); // reading matrix from file

    // simple matrix operations
    void printMatrix();

    //-----------TO DO ---------

    //add get_rows , get_cols 
    void addition(Matrix, Matrix);
    void subtraction(Matrix, Matrix);
    void multiplication(Matrix, Matrix);
    //--------------------------

    bool isDiagonallyDominant();
    bool makeDiagonallyDominant();
    bool isSymmetric(vector<vector<double>> mat, int rows, int cols);

    int getDiagonallyDominantRowAt(int r);
    void swapRows(int row1, int row2);

    vector<vector<double>> rowReduction(); // to upper triangular
    vector<vector<double>> getTranspose(vector<vector<double>> L);

    vector<double> forwardSubstitution(vector<vector<double>> reducedMat);
    vector<double> backSubstitution(vector<vector<double>> reducedMat);

    // solution of LE
    vector<double> gaussian_elimination();
    vector<double> gauss_jacobi();
    vector<double> gauss_seidel();
    vector<double> lu_decomposition(vector<vector<double>> mat, int rows, int cols);
    vector<double> cholesky_decomposition(vector<vector<double>> mat, int rows, int cols);
};