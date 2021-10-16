/*
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1

Variations
------------
1) Given an integer numRows, return the first numRows of Pascal's triangle.
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

2) Given the row number find the column values at that row
Input: Row = 3
Output: [[1,2,1]]

3) 2) Given the row number and column number find the value at that point
Input: Row = 3 , Column = 3
Output: [[2]]

Trick -> (r-1)C(c-1)  eg for 5 and 3  the value is -> 4C2  i.e  (4*3)/(2*1) = 6
nCr = n! / r! * (n - r)! -> fiding factoral takes o(n) TC
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {

            r[i].resize(i + 1);    // making the row number = column size
            r[i][0] = r[i][i] = 1; // making the 1st and last element of each row 1

            for (int j = 1; j < i; j++)
            {

                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        return r;
    }
};
