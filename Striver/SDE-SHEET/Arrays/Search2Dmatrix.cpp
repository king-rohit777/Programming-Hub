/*
Approaches
----------
1) Brute Force
2) Better approach
3) Optimal approach

*/

// Brute Force Approach  TC: o(n*m) SC: o(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();
        int m = matrix[0].size();
        int found = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (matrix[i][j] == target)
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
                break;
        }

        if (found == 1)
            return true;
        else
            return false;
    }
};

// Better approach  TC: o(n*m) SC: o(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m - 1, found = 0;

        while (i < n && j >= 0)
        {

            if (matrix[i][j] == target)
            {
                found = 1;
                break;
            }
            else
            {
                if (matrix[i][j] > target)
                    j--;
                else
                    i++;
            }
        }
        if (found == 1)
            return true;
        else
            return false;
    }
};

// Optimal approach  => TC: o(log(n*m)) SC: o(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n * m) - 1;
        while (low <= high)
        {

            int mid = low + ((high - low) / 2);

            if (matrix[mid / m][mid % m] == target)
                return true;

            if (matrix[mid / m][mid % m] < target)
                low = mid + 1;

            if (matrix[mid / m][mid % m] > target)
                high = mid - 1;
        }
        return false;
    }
};
