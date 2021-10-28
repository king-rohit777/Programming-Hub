/*
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i], B <= 109



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having bitwise XOR equals to B.

*/

int Solution::solve(vector<int> &A, int B)
{

    map<int, int> freq;
    int c = 0, xorr = 0;

    for (auto it : A)
    {

        xorr = xorr ^ it;

        if (xorr == B)
        {
            c++;
        }

        if (freq.find(xorr ^ B) != freq.end())
        {
            c += freq[xorr ^ B];
        }

        freq[xorr] += 1;
    }
    return c;
}
