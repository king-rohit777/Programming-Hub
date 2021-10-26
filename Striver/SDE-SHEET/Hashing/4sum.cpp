class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> res;

        if (nums.empty())
            return res;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {

            int target3 = target - nums[i];

            for (int j = i + 1; j < n; j++)
            {

                int target2 = target3 - nums[j];

                int low = j + 1;
                int high = n - 1;

                while (low < high)
                {

                    int twoSum = nums[low] + nums[high];

                    if (twoSum < target2)
                        low++;

                    else if (twoSum > target2)
                        high--;

                    else
                    {
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        res.push_back(temp);

                        while (low < high && nums[low] == temp[2])
                            ++low;

                        while (low < high && nums[high] == temp[3])
                            --high;
                    }
                }

                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};