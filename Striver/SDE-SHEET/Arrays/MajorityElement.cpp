/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int count = 0, candidate = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (count == 0)
            {
                candidate = nums[i];
            }

            if (nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};