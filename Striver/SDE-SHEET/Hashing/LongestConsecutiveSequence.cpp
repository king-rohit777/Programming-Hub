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

// Approach 2
//-----------

// Using Hashset

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        set<int> hashSet;

        for (int num : nums)
        {
            hashSet.insert(num);
        }

        int longestStreak = 0;

        for (int num : nums)
        {

            if (!hashSet.count(num - 1))
            {
                int currentnum = num;
                int currentStreak = 1;

                while (hashSet.count(currentnum + 1))
                {
                    currentnum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};