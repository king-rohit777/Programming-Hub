/*
Approaches
----------

1) Brute force -> using recursion tree -> TC is exponential and space complexity is also exponential

2) Better approach -> using Dynamic programming -> TC is o(n*m) and space complexity is o(n*m)

3) Optimal approach -> Using the concept of Combinatorics

*/

// Approach 1

int countPaths(int i, int j, int m, int n)
{
    if (i == n - 1 && j == m - 1)
        return 1;

    if (i >= n + 1 || j >= m + 1)
        return 0;

    else
    {

        return countPaths(i + 1, j) + countPaths(i, j + 1);
    }
}

// Approach 2

int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return 1;

    if (i >= n + 1 || j >= m + 1)
        return 0;

    else
    {

        if (dp[i][j] != -1) // fill the dp with all -1 initially
            return dp[i][j];
        else
            return dp[i][j] = countPaths(i + 1, j, dp) + countPaths(i, j + 1, dp);
    }
}

// Approach 3

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int N = n + m - 2;
        int r = m - 1;
        double res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }

        return (int)res;
    }
};