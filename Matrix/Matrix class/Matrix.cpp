#include "Matrix.hpp"
using namespace std;

void Matrix::printMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

Matrix::Matrix(vector<vector<double>> matrix, int row, int col)
{
    mat = matrix;
    rows = row;
    cols = col;
}

Matrix ::Matrix(string file_L, string file_R)
{
    ifstream fin;
    fin.open(file_L);

    int rows, cols;
    fin >> rows >> cols;

    this->rows = rows;
    this->cols = cols;

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
    fin.open(file_R);
    for (int i = 0; i < rows; i++)
    {
        fin >> mat[i][cols - 1];
    }
    fin.close();

    this->mat = mat;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

bool Matrix::isDiagonallyDominant()
{
    for (int r = 0; r < rows; r++)
    {
        double diagonal = fabs(mat[r][r]);
        double rowSum = 0.0;

        for (int c = 0; c < rows; c++)
        {
            if (c != r)
            {
                rowSum += fabs(mat[r][c]);
            }
        }

        if (diagonal <= rowSum)
        {
            return false;
        }
    }
    return true;
}

int Matrix::getDiagonallyDominantRowAt(int r)
{
    for (int i = r + 1; i < rows; i++)
    {
        int rowSum = 0;
        for (int c = 0; c < rows; c++)
        {
            if (r != c)
            {
                rowSum += fabs(mat[i][c]);
            }
            if (fabs(mat[i][i] >= rowSum))
            {
                return i;
            }
        }
    }
    return -1;
}

void Matrix::swapRows(int row1, int row2)
{
    for (int c = 0; c < cols; c++)
    {
        double temp = mat[row1][c];
        mat[row1][c] = mat[row2][c];
        mat[row2][c] = temp; // Swap correct values
    }
}

bool Matrix::makeDiagonallyDominant()
{
    for (int r = 0; r < rows; r++)
    {
        double diagonal = fabs(mat[r][r]);
        double rowSum = 0.0;

        for (int c = 0; c < rows; c++)
        {
            if (c != r)
            {
                rowSum += fabs(mat[r][c]);
            }
        }

        if (diagonal <= rowSum)
        { // Changed from '<' to '<='
            int index = getDiagonallyDominantRowAt(r);
            if (index == -1)
                return false;
            else
                swapRows(r, index);
        }
    }
    return true;
}

bool Matrix::isSymmetric()
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

vector<vector<double>> Matrix::rowReduction()
{
    int i, j;
    int r = 0;

    // cout << rows << "::" << cols << endl;
    while (r < rows)
    {
        double pivot = mat[r][r];
        if (pivot != 0) // Ensure pivot is not zero
        {
            for (i = 0; i < cols; i++)
            {
                mat[r][i] = mat[r][i] / pivot;
            }

            for (i = r + 1; i < rows; i++)
            {
                double temp = mat[i][r];
                for (j = r; j < cols; j++)
                {
                    mat[i][j] = mat[i][j] - (temp * mat[r][j]);
                }
            }
        }
        r++;
    }
    // cout << "Matrix after row reduction:" << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         std::cout << mat[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return mat;
}

vector<vector<double>> Matrix::getTranspose(vector<vector<double>> L)
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

vector<double> Matrix::forwardSubstitution(vector<vector<double>> reducedMat)
{
    vector<double> ans(rows);
    ans[0] = reducedMat[0][cols - 1] / reducedMat[0][0];
    for (int r = 1; r < rows; r++)
    {
        double sum = 0;
        for (int c = 0; c < r; c++)
        {
            sum += reducedMat[r][c] * ans[c];
        }
        ans[r] = (reducedMat[r][cols - 1] - sum) / reducedMat[r][r];
    }
    return ans;
}

vector<double> Matrix::backSubstitution(vector<vector<double>> reducedMat)
{
    vector<double> ans(rows);
    ans[rows - 1] = reducedMat[rows - 1][cols - 1] / reducedMat[rows - 1][rows - 1];

    for (int r = rows - 2; r >= 0; r--)
    {
        double lhs = 0;
        for (int c = r + 1; c < rows; c++)
        {
            lhs += reducedMat[r][c] * ans[c];
        }
        ans[r] = (reducedMat[r][cols - 1] - lhs) / reducedMat[r][r];
    }

    return ans;
}