/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

/*
INTUTION

triplets  basically need to be  a+b+c = 0 , we are fixing a and then finding b and c using normal 2 pointer which is basically just finding  (-a)

a+b+c =0 
b+c = -a 

this reduces to a 2 pointer 2 sum problem where we are finding -a as target 
*/

class Solution //Time complexity of this code is o(n^2) -> o(n) for filling the vector and o(n) for iterating using 2 pointer
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        if (nums.size() < 3) // corner case
            return res;

        for (int i = 0; i < nums.size() - 2; i++)
        {

            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {

                int lo = i + 1, hi = nums.size() - 1, sum = 0 - nums[i];

                while (lo < hi)
                {

                    if (nums[lo] + nums[hi] == sum)
                    {

                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);

                        while (lo < hi && nums[lo] == nums[lo + 1])
                            lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1])
                            hi--;

                        lo++;
                        hi--;
                    }

                    else if (nums[lo] + nums[hi] < sum)
                    {
                        lo++;
                    }
                    else
                    {
                        hi--;
                    }
                }
            }
        }
        return res;
    }
};