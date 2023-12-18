/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <iostream>
#include <climits>
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int closestSum = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (std::abs((long)target - sum) < std::abs((long)target - closestSum))
                {
                    closestSum = sum;
                }
                if (sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return closestSum;
    }
};
// @lc code=end
