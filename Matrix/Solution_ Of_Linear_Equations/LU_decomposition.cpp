#include "SolutionOfLinearEq.hpp"
using namespace std;

double get_U(int r, int c, vector<vector<double>> mat, vector<vector<double>> L, vector<vector<double>> U)
{
    double sum = 0.0;
    for (int k = 0; k < r; k++)
    {
        sum += L[r][k] * U[k][c];
    }
    U[r][c] = mat[r][c] - sum;
    return U[r][c];
}

double get_L(int r, int c, vector<vector<double>> mat, vector<vector<double>> L, vector<vector<double>> U)
{
    double sum = 0.0;
    for (int k = 0; k < c; k++)
    {
        sum += L[r][k] * U[k][c];
    }
    L[r][c] = (mat[r][c] - sum) / U[c][c];
    return L[r][c];
}

double get_Lij(int i, int j, vector<vector<double>> mat, vector<vector<double>> L)
{
    double sum = 0.0;

    for (int k = 0; k < j; k++)
    {
        sum += L[i][k] * L[j][k];
    }
    L[i][j] = (mat[i][j] - sum) / L[j][j];
    return L[i][j];
}

double get_Ljj(int j, vector<vector<double>> &mat, vector<vector<double>> &L)
{
    double sum = 0.0;
    for (int k = 0; k < j; k++)
    {
        sum += pow(L[j][k], 2);
    }
    L[j][j] = sqrt(mat[j][j] - sum);
    return L[j][j];
}

bool SolutionOfLE::isSymmetric(vector<vector<double>> mat, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            if (i > j)
            {
                if (mat[i][j] != mat[j][i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<double>> SolutionOfLE::getTranspose(vector<vector<double>> L, int rows, int cols)
{
    vector<vector<double>> L_transpose(rows, vector<double>(cols - 1));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            L_transpose[i][j] = L[j][i];
        }
    }
    return L_transpose;
}

// Function to perform forward substitution
vector<double> SolutionOfLE::forwardSubstitution(vector<vector<double>> mat, int rows, int cols)
{
    vector<double> ans(rows);
    ans[0] = mat[0][cols - 1] / mat[0][0];
    for (int r = 1; r < rows; r++)
    {
        double sum = 0;
        for (int c = 0; c < r; c++)
        {
            sum += mat[r][c] * ans[c];
        }
        ans[r] = (mat[r][cols - 1] - sum) / mat[r][r];
    }
    return ans;
}

vector<double> SolutionOfLE::lu_decomposition(vector<vector<double>> mat, int rows, int cols)
{
    vector<vector<double>> L(rows, vector<double>(cols)); // lower triangular
    vector<vector<double>> U(rows, vector<double>(cols)); // upper triangular

    for (int r = 0; r < rows; r++)
    {
        // for Lower Triangular Matrix

        for (int c = 0; c <= r; c++)
        {
            if (r == c)
            {
                L[r][c] = 1; // Diagonal elements are 1
            }
            else
            {

                L[r][c] = get_L(r, c, mat, L, U);
            }
        }
        // for Upper Triangular Matrix row-wise

        for (int c = 0; c < rows; c++)
        {
            U[r][c] = get_U(r, c, mat, L, U);
        }
    }
    // attach B to L
    for (int i = 0; i < rows; i++)
    {
        L[i][cols - 1] = mat[i][cols - 1];
    }
    // LZ=B
    vector<double> Z(rows);
    Z = forwardSubstitution(L, rows, cols);
    // attach Z to U
    for (int i = 0; i < rows; i++)
    {
        U[i][cols - 1] = Z[i];
    }
    // UX=Z
    vector<double> ans(rows);
    ans = backSubstitution(U, rows, cols);

    return ans;
}

// Function to perform Cholesky decomposition
vector<double> SolutionOfLE::cholesky_decomposition(vector<vector<double>> mat, int rows, int cols)
{
    if (!isSymmetric(mat, rows, cols))
    {
        cerr << "Matrix is not Symmetric!" << endl;
    }
    vector<vector<double>> L(rows, vector<double>(cols)); // Lower triangular matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                L[j][j] = get_Ljj(j, mat, L);
            }
            else
            {
                L[i][j] = get_Lij(i, j, mat, L);
            }
        }
    }
    vector<vector<double>> L_transpose(rows, vector<double>(cols)); // Transpose of L
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            L_transpose[i][j] = L[j][i];
        }
    }
    // attach B to L
    for (int i = 0; i < rows; i++)
    {
        L[i][cols - 1] = mat[i][cols - 1];
    }

    vector<double> Y = forwardSubstitution(L, rows, cols);
    // attach Y to L_transpose
    for (int i = 0; i < rows; i++)
    {
        L_transpose[i][cols - 1] = Y[i];
    }
    // Printing the lower triangular matrix L
    // cout << "Lower Triangular Matrix L:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << L[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // Printing the upper triangular matrix L_transpose
    // cout << "L_transpose :" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << L_transpose[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<double> X = backSubstitution(L_transpose, rows, cols);

    // Printing the solution vector X
    // cout << "Solution Vector X:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     cout << "X" << i + 1 << " = " << X[i] << endl;
    // }
    return X;
}
