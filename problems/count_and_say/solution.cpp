
// TC - O(N2), SC-O(4N)
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        vector<int> nums = {1};
        for (int i = 2; i <= n; i++)
        {
            pair<int, int> numCount;
            int j = 0;
            vector<int> tempNums;
            while (j < nums.size())
            {
                if (numCount.first == nums[j])
                {
                    numCount.second++;
                }
                else
                {
                    if (j != 0)
                    {
                        tempNums.push_back(numCount.second);
                        tempNums.push_back(numCount.first);
                        numCount = make_pair(nums[j], 1);
                    }
                    else
                    {
                        numCount = make_pair(nums[j], 1);
                    }
                }
                j++;
            }
            tempNums.push_back(numCount.second);
            tempNums.push_back(numCount.first);
            nums = tempNums;
        }
        string result = "";
        for (const auto &value : nums)
        {
            result += std::to_string(value);
        }
        return result;
    }
};