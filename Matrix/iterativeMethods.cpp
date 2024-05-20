#include "Matrix.hpp"
using namespace std;

vector<double> Matrix::gauss_jacobi()
{
    vector<double> prev_ans(rows, 0); // initial solution
    vector<double> curr_ans(rows, 0);

    if (!isDiagonallyDominant())
    {
        makeDiagonallyDominant();
    }

    int max_iterations = 1000;  // Maximum number of iterations
    double tolerance = 0.00001; // Tolerance for convergence

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
            // cout << "Number of iterations using GJ :: " << iter << endl;
            return curr_ans; // Converged
        }

        prev_ans = curr_ans; // Update previous solution
    }
    return prev_ans; // rectify later
}

vector<double> Matrix::gauss_seidel()
{
    vector<double> prev_ans(rows, 0);
    vector<double> curr_ans(rows, 0);

    if (!isDiagonallyDominant())
    {
        makeDiagonallyDominant();
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