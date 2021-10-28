/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution,
    and you may not use the same element twice.

        You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <iostream>
using namespace std;

// BRUTE FORCE APPRAOCH
// TC -> o(n^2)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> value(2);
        bool found = false;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            for (int j = i + 1; j < nums.size(); j++)
            {

                if (nums[i] + nums[j] == target)
                {

                    value[0] = i;
                    value[1] = j;
                    found = true;
                    break;
                }

            } // exit from j loop
            if (found)
                break;
        } // exit from i loop
        return value;
    }
};

// OPTIMISED SOLUTION
// Two pointer approach -> Two pointers is really an easy and effective technique that is typically used for searching pairs in a sorted array.
// TC -> o(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v, temp;

        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }

        sort(temp.begin(), temp.end());

        int first = 0, last = nums.size() - 1;

        while (last < nums.size())
        {
            if (temp[first] + temp[last] < target)
            {

                first++;
            }
            else if (temp[first] + temp[last] > target)
            {

                last--;
            }
            else
            {
                temp[0] = temp[first];
                temp[1] = temp[last];
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == temp[0] || nums[i] == temp[1])
                v.push_back(i);
            if (v.size() == 2)
                break;
        }
        return v;
    }
};
