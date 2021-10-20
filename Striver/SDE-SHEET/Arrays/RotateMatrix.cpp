/*
Approaches
----------
1) Take another 2D array and fill it accordingly :- TC : o(n^2) ; SC : o(n^2)
2) Transpose the array first and then reverse each row of the array to achieve 90 degree rotation :- TC : o(n^2)+o(n^2) => o(2(n^2)) ~o(n^2) ; SC : o(1)
*/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};