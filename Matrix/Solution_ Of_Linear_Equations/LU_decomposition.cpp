#include "SolutionOfLinearEq.hpp"
using namespace std;
int get_L(int r, int c, vector<vector<double>> mat, vector<vector<double>> L, vector<vector<double>> U)
{
    double ans = 0.0;
    double sum = 0.0;
    int cols = mat[0].size();
    for (int k = 0; k < cols - 1; k++)
    {
        sum += L[r][k] * U[k][c];
    }
    ans = mat[r][c] - sum;
    return ans;
}

int get_U(int r, int c, vector<vector<double>> mat, vector<vector<double>> L, vector<vector<double>> U)
{
    double ans = 0.0;
    double sum = 0.0;
    int rows = mat.size();
    for (int k = 0; k < rows; k++)
    {
        sum += L[r][k] * U[k][c];
    }
    ans = (mat[r][c] - sum) / L[r][r];
    return ans;
}
vector<double> SolutionOfLE::forwardSubstitution(vector<vector<double>> mat, int rows, int cols)
{
    vector<double> ans(rows);

    for (int r = 0; r < rows; ++r)
    {
        double lhs = 0;
        for (int c = 0; c < r; ++c)
        {
            lhs += mat[r][c] * ans[c];
        }
        ans[r] = (mat[r][cols - 1] - lhs) / mat[r][r];
    }

    cout << "Forward Substitution::" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "X" << i + 1 << " = " << ans[i] << endl;
    }
    cout << endl;
    return ans;
}

vector<double> SolutionOfLE::lu_decomposition(vector<vector<double>> mat, int rows, int cols)
{
    vector<vector<double>> L(rows, vector<double>(cols)); // lower triangular
    vector<vector<double>> U(rows, vector<double>(cols)); // upper triangular

    // crout's method
    for (int r = 0; r < rows; r++)
    {
        U[r][r] = 1;
    }

    for (int r = 0; r < rows; r++)
    {
        // for Lower Triangular Matrix column-wise
        for (int c = 0; c < rows; c++)
        {
            if (c >= r)
            {
                L[c][r] = get_L(c, r, mat, L, U);
                cout << "For c:: " << c << " & r:: " << r << "L :: " << L[c][r] << endl;
            }
        }
        // for Upper Triangular Matrix row-wise

        for (int c = 0; c < rows; c++)
        {
            if (c > r)
            {
                U[r][c] = get_U(r, c, mat, L, U);
                cout << "For r:: " << r << "& c::" << c << "U ::" << U[r][c] << endl;
            }
        }
    }
    // LZ=B
    vector<double> z(rows);
    z = forwardSubstitution(L, rows, cols);
    // UX=Z
    vector<double> ans(rows);
    ans = backSubstitution(U, rows, cols);

    return ans;
}
