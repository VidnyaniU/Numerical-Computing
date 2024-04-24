#include "SolutionOfLinearEq.hpp"
using namespace std;

bool SolutionOfLE::isDiagonallyDominant(vector<vector<double>> mat, int rows, int cols)
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
            return false;
        }
    }
    return true;
}
int SolutionOfLE::getDiagonallyDominantRowAt(int r)
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
void SolutionOfLE::swapRows(int row1, int row2)
{
    for (int c = 0; c < cols; c++)
    { // Changed 'rows' to 'cols'
        double temp = mat[row1][c];
        mat[row1][c] = mat[row2][c];
        mat[row2][c] = temp; // Swap correct values
    }
}

bool SolutionOfLE::makeDiagonallyDominant(vector<vector<double>> mat, int rows, int cols)
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

vector<double> SolutionOfLE::gauss_jacobi(vector<vector<double>> mat, int rows, int cols)
{
    vector<double> prev_ans(rows, 0); // initial solution
    vector<double> curr_ans(rows, 0);

    if (!isDiagonallyDominant(mat, rows, cols))
    {
        makeDiagonallyDominant(mat, rows, cols);
    }

    int max_iterations = 1000; // Maximum number of iterations
    double tolerance = 0.0001; // Tolerance for convergence

    for (int iter = 0; iter < max_iterations; ++iter)
    {
        for (int r = 0; r < rows; r++)
        {
            double sum = 0.0;
            for (int c = 0; c < rows; c++)
            {
                if (c != r)
                {
                    sum += mat[r][c] * prev_ans[c];
                }
            }
            curr_ans[r] = (mat[r][cols - 1] - sum) / mat[r][r];
        }

        // Check for convergence
        double max_diff = 0.0;
        for (int i = 0; i < rows; i++)
        {
            max_diff = max(max_diff, fabs(curr_ans[i] - prev_ans[i]));
        }
        if (max_diff < tolerance)
        {
            cout << "Number of iterations using GJ :: " << iter << endl;
            return curr_ans; // Converged
        }

        prev_ans = curr_ans; // Update previous solution
    }
    return prev_ans; // rectify later
}

vector<double> SolutionOfLE::gauss_seidel(vector<vector<double>> mat, int rows, int cols)
{
    vector<double> prev_ans(rows, 0);
    vector<double> curr_ans(rows, 0);

    if (!isDiagonallyDominant(mat, rows, cols))
    {
        makeDiagonallyDominant(mat, rows, cols);
    }

    int maxIterations = 1000; // Maximum number of iterations to avoid infinite loop
    double TOL = 0.0001;      // Tolerance for convergence
    int iter;
    for (iter = 0; iter < maxIterations; iter++)
    {
        for (int r = 0; r < rows; r++)
        {
            double sum = 0.0;
            for (int c = 0; c < cols; c++)
            { // Changed 'rows' to 'cols'
                if (c != r)
                {
                    sum += mat[r][c] * curr_ans[c]; // Changed to use curr_ans
                }
            }
            curr_ans[r] = (mat[r][cols - 1] - sum) / mat[r][r];
        }

        bool converged = true;
        for (int i = 0; i < cols - 1; i++)
        { // Changed 'rows' to 'cols'
            if (fabs(prev_ans[i] - curr_ans[i]) >= TOL)
            {
                converged = false;
                break;
            }
        }

        if (converged)
            break;

        prev_ans = curr_ans;
    }
    cout << "Number of iterations using GS :: " << iter << endl;

    return curr_ans;
}
