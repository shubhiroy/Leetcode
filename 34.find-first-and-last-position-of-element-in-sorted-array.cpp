/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

// Using Upper/Lower bound concept, TC- O(logN), SC- O(1)
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start_ind = findIndex(nums, target, true);
        int end_ind = findIndex(nums, target, false);
        return vector<int>{start_ind, end_ind};
    }

    int findIndex(const vector<int> arr, int target, bool isStartIndex)
    {
        int left = 0, right = arr.size() - 1, target_index = -1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (arr[mid] < target)
                left = mid + 1;
            else if (arr[mid] > target)
                right = mid - 1;
            else
            {
                target_index = mid;
                if (isStartIndex)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return target_index;
    }
};

// TC-O(NlogN), SC-O(1)
// Could have simple used linear search with O(N) TC
// #include <iostream>
// class Solution
// {
// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int left = 0, right = nums.size() - 1, targetIndex = -1;
//         while (left <= right)
//         {
//             int mid = (left + right) / 2;
//             std::cout << mid << std::endl;
//             if (nums[mid] == target)
//             {
//                 targetIndex = mid;
//                 break;
//             }
//             else if (nums[mid] > target)
//             {
//                 right = mid - 1;
//             }
//             else
//             {
//                 left = mid + 1;
//             }
//         }

//         if (targetIndex == -1)
//         {
//             return vector<int>{-1, -1};
//         }

//         int i = targetIndex, j = targetIndex;
//         while (i >= 0 && nums[i] == target)
//         {
//             i--;
//         }
//         while (j < nums.size() && nums[j] == target)
//         {
//             j++;
//         }

//         return vectr<int>{i + 1, j - 1};
//     }
// };
// @lc code=end
