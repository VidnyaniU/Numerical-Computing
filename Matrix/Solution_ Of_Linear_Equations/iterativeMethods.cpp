#include "SolutionOfLinearEq.hpp";
using namespace std;

bool SolutionOfLE::isDiagonallyDominant()
{
    // int matLen = matLHS.size();
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

        if (diagonal < rowSum)
        {
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
    for (int c = 0; c < rows; c++)
    {
        double temp = mat[row1][c];
        mat[row1][c] = mat[row2][c];
        mat[row2][c] = mat[row1][c];
    }
}
bool SolutionOfLE::makeDiagonallyDominant()
{
    int r, c;

    for (r = 0; r < rows; r++)
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

        if (diagonal < rowSum)
        {
            // find suitable row to swap with
            int index = getDiagonallyDominantRowAt(r); // at r th col
            if (index == -1)
                return false;
            else
                swapRows(r, index);
        }
    }

    return true;
}

vector<double> SolutionOfLE::gauss_jacobi()
{
    vector<double> prev_ans(rows, 0); // initial solution
    vector<double> curr_ans(rows, 0);
    // cout << "isDiagonallyDominant::" << isDiagonallyDominant(mat) << endl;
    if (!isDiagonallyDominant())
    {
        makeDiagonallyDominant();
    }
    while (1)
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
        // break condition
        int flag = 1;
        int TOL = 0.0001;
        for (int i = 0; i < cols - 1; i++)
        {
            if ((fabs(prev_ans[i]) - fabs(curr_ans[i])) < TOL)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
        prev_ans = curr_ans; // if break doesn't happen we store current answer in the previous one and go for the inext iteration
    }
    return curr_ans;
}
vector<double> SolutionOfLE::gauss_seidel()
{
    vector<double> prev_ans(rows, 0);

    vector<double> curr_ans(rows, 0);
    // cout << "isDiagonallyDominant::" << isDiagonallyDominant(mat) << endl;
    if (!isDiagonallyDominant())
    {
        makeDiagonallyDominant();
    }
    while (1)
    {
        for (int r = 0; r < rows; r++)
        {
            double sum = 0.0;
            for (int c = 0; c < rows; c++)
            {
                if (c != r)
                {
                    sum += mat[r][c] * curr_ans[c];
                }
            }
            curr_ans[r] = (mat[r][cols - 1] - sum) / mat[r][r];
        }
        // break condition
        int flag = 1;
        int TOL = 0.0001;
        for (int i = 0; i < cols - 1; i++)
        {
            if ((fabs(prev_ans[i]) - fabs(curr_ans[i])) < TOL)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
        prev_ans = curr_ans; // if break doesn't happen we store current answer in the previous one and go for the inext iteration
    }
    return curr_ans;
}
