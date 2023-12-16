/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <algorithm>
#include <iostream>

// TC - O(3N), SC-O(1)
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
        {
            return;
        }

        int i = nums.size() - 2;
        for (; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                break;
            }
        }

        if (i > -1)
        {
            int j = nums.size() - 1;
            while (j != i && nums[j] <= nums[i])
            {
                j--;
            }
            std::swap(nums[i], nums[j]);
            // int temp = nums[i];
            // nums[i] = nums[j];
            // nums[j] = temp;
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};

// STL function
// class Solution
// {
// public:
//     void nextPermutation(vector<int> &nums)
//     {
//         std::next_permutation(nums.begin(), nums.end());
//     }
// };

// Brute force, Creating all permutation of the array
// TC - N!*N, SC -
// @lc code=end
