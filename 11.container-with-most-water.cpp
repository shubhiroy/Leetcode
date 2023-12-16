/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_water = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            int water_vol = std::min(height[i], height[j]) * (j - i);
            if (max_water < water_vol)
            {
                max_water = water_vol;
            }
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_water;
    }
};

// First attempt, Time complexity = O(N2), Space Complexity = O(1)
// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int max_water = 0;
//         for (int i = 0; i < height.size() - 1; i++)
//         {
//             for (int j = 1; j < height.size(); j++)
//             {
//                 int min_height = std::min(height[i], height[j]);
//                 int water_capacity = min_height * std::abs(j - i);
//                 // std::cout << "i=" << i << " height_i=" << height[i] << " height_j=" << height[j] << " j=" << j << " Water capacity " << water_capacity << std::endl;
//                 max_water = water_capacity > max_water ? water_capacity : max_water;
//             }
//         }

//         return max_water;
//     }
// };
// @lc code=end
