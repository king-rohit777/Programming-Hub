/*
Approaches
----------
1) Brute force

*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int streak = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    streak += 1;
                }
                else
                {
                    longestStreak = max(longestStreak, streak);
                    streak = 1;
                }
            }
        }
        return max(longestStreak, streak);
    }
};