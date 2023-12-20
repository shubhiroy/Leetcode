
// "KADANE's ALGO", TC- O(N), SC-O(1)
// left and right are taken here just incase any one want to know the sub array also
// Edge case - if all the elements are negative then we can return empty sub array if the question allows
#include <climits>
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, left = -1, right = -1, maxSum = INT_MIN;
        // vector<int> maxSumArr;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum < 0)
            {
                sum = 0;
                left = i;
                right = i;
            }
            sum += nums[i];
            if (sum > maxSum)
            {
                maxSum = sum;
                right = i;
            }
        }

        return maxSum;
    }
};

// // TC-O(N2), SC-O(1), Error - TLE
// #include <climits>
// #include <iostream>
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         vector<int> maxSumSubArr;
//         int maxSum = INT_MIN;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int sum = 0;
//             vector<int> subArr;
//             for (int j = i; j < nums.size(); j++)
//             {
//                 sum += nums[j];
//                 subArr.push_back(nums[j]);
//                 if (sum > maxSum)
//                 {
//                     maxSum = sum;
//                     maxSumSubArr = subArr;
//                 }
//             }
//         }
//         // std::cout << "Array with Max Sum >>> ";
//         // for (int i = 0; i < maxSumSubArr.size(); i++)
//         // {
//         //     std::cout << maxSumSubArr[i] << " , ";
//         // }
//         // std::cout << std::endl;

//         return maxSum;
//     }
// };