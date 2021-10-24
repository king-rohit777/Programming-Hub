/*
Approach
---------
1)Brute force or naive approach where we can use 3 loops to generate all possible substrings and then check
we can optimise it a bit to have 2 loops instead using sliding window in 2nd loop

2) Using sets we can store the last visited character and use sliding window there

3) use a map or a frequency array
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        vector<int> mpp(256, -1);

        int left = 0, right = 0;
        int n = s.size();
        int length = 0;

        while (right < n)
        {

            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left);

            mpp[s[right]] = right;

            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};