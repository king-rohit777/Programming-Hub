/*
Sort an array of 0s 1s and 2s without using sort algorithm

approach 1
-----------
using sort function  -> TC o(nlogn) , SC o(1)

approach 2   {Counting Sort}
-----------
find the frequency of each and insert them accordingly -> TC o(2n)  SC o(n)

Approach 3
-----------
Dutch National flag algorithm modification

3 pointers -> low mid and high

*/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
        }
    }
};

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {

            switch (nums[mid])
            {

            case 0:
                swap(nums[mid], nums[low]);
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(nums[mid], nums[high]);
                high--;
                break;
            }
        }
    }
};
