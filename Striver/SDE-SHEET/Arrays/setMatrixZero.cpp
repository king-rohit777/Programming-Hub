/*
Approaches
-------------
1) using brute force iterate through each elements to get the count of 0s
2) Keep a seperate row and column matrix to get the position of 0 and 1
3) use the 1st row and column of the matrix itself to keep the track of the 0s -> TC = o(m*n) SC -> o(1)
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int m = matrix.size();    // gives the number of vectors in the vectors of vectors (accounts for row in a 2d matrix)
        int n = matrix[0].size(); // gives the size of 1st inserted vector (accouts for column as every inserted vector will have same size)
        int c1 = 0, r1 = 0;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                c1 = 1;
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                r1 = 1;
                break;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                if (matrix[i][j] == 0)
                {

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {

                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {

                    matrix[i][j] = 0;
                }
            }
        }

        if (c1 == 1)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (r1 == 1)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};