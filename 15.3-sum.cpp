/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while (k > j && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return result;
    }
};

// Using HashTable, TC - O(N2*log M), SC - 2O(no. of triplets) + O(N)
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         std::set<vector<int>> triplets;
//         for (int i = 0; i < nums.size() - 2; i++)
//         {
//             std::set<int> hashset;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 int target = -(nums[i] + nums[j]);
//                 if (hashset.find(target) != hashset.end())
//                 {
//                     std::vector<int> temp = {nums[i], nums[j], target};
//                     std::sort(temp.begin(), temp.end());
//                     triplets.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
//         return std::vector<vector<int>>(triplets.begin(), triplets.end());
//     }
// };

// Brute Force, Time Complexity - O(N3*log(no. of uniques)), Space Complexity - 2O(No. of triplets)
// Here log(no. of uniques) in time complexity is added while adding data to set. We are not cosidering sorting tc as it will constant (only 3 elements are sorted)
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         set<vector<int>> result;
//         for (int i = 0; i < nums.size() - 2; i++)
//         {
//             for (int j = i + 1; j < nums.size() - 1; j++)
//             {
//                 for (int k = j + 1; k < nums.size(); k++)
//                 {
//                     if (nums[i] + nums[j] + nums[k] == 0)
//                     {
//                         vector<int> t{nums[i], nums[j], nums[k]};
//                         std::sort(t.begin(), t.end());
//                         result.insert(t);
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>>(result.begin(), result.end());
//     }
// };
// @lc code=end
