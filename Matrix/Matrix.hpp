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

    vector<vector<double>> &get_mat_data();
    int get_rows() const;
    int get_cols() const;
    // simple matrix operations
    void printMatrix();

    vector <vector<double>> addition(Matrix &mat1, Matrix &mat2);
    vector <vector<double>> subtraction(Matrix &mat1, Matrix &mat2);
    vector <vector<double>> multiplication(Matrix &mat1, Matrix &mat2);

    bool isDiagonallyDominant();
    bool makeDiagonallyDominant();
    bool isSymmetric();

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
    vector<double> lu_decomposition();
    vector<double> cholesky_decomposition();
};