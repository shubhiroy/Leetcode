
class Solution
{
public:
    // void sortColors(vector<int> &nums)
    // {
    //     int low = 0, mid = 0, high = nums.size() - 1;
    //     while (mid <= high)
    //     {
    //         if (nums[mid] == 0)
    //         {
    //             swap(nums, low, mid);
    //             low++;
    //             mid++;
    //         }
    //         else if (nums[mid] == 1)
    //         {
    //             mid++;
    //         }
    //         else
    //         {
    //             swap(nums, mid, high);
    //             high--;
    //         }
    //     }
    // }

    // TC - O(N), SC-O(1)
    void sortColors(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        vector<int> zeros, ones, twos;
        for (int i = 0; i <= high;)
        {
            if (nums[i] == 0)
            {
                swap(nums, low, i);
                low++;
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums, high, i);
                high--;
            }
            else
            {
                i++;
            }
        }
    }

    void swap(vector<int> &nums, int a, int b)
    {
        if (nums[a] == nums[b])
            return;

        nums[a] = nums[a] ^ nums[b];
        nums[b] = nums[a] ^ nums[b];
        nums[a] = nums[a] ^ nums[b];
    }
};