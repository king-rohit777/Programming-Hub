/*
Approaches
-----------
https://youtu.be/32Ll35mhWg0
1) Brute force by taking 2 loops -> o(n^2)
2) sort the array (duplicate elements will be aligned together) -> o(nlogn) -> considering merge sort for sorting algo -> also disturbs the array
3)Create a frequency array , initialize it with 0 and increase the count where the dublicate elements occur  -> o(n) and space complexity -> o(n)
4)Create a frequency hash map and do same as  above -> with take extra space + extra time of log n as every time it searches for an element in the hash map
5)Linked list cycle method

*/
// o(n^2) approach -> brute force
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                    break;
                }
            }
        }
        return 0;
    }
};

// Linked list cycle approach -> create a cycle of the repeated elements => tortoise mentod for 1st method
// o(n)-> time complexity and o(1) space complexuty
// Tortoise algorithm
// Two cycles  -> in first cycle we move the fast pointer by 2 units and slow pointer by 1 unit and after they collide , we set the fast pointer to the start and slow pointer is as it is . Then again both are moved by one one each  and the point at which they collide is the duplicate element

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = nums[slow];
        int fast = nums[fast];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];

        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};