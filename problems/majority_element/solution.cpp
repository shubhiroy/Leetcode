
// TC-O(N), SC-O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorityKey = nums[0], c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (c == 0)
                majorityKey = nums[i];
            if (majorityKey == nums[i])
                c++;
            else
                c--;
        }
        return majorityKey;
    }
};

// // TC-O(N), SC-O(N)

// #include <iterator>
// #include <map>
// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {
//         std::map<int, int> elementCount;
//         std::map<int, int>::iterator itr;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             itr = elementCount.find(nums[i]);
//             if (itr == elementCount.end())
//             {
//                 elementCount.insert(std::pair<int, int>(nums[i], 1));
//             }
//             else
//             {
//                 itr->second = itr->second + 1;
//             }
//         }

//         std::pair<int, int> maxCountVar(elementCount.begin()->first, elementCount.begin()->second);
//         for (itr = elementCount.begin(); itr != elementCount.end(); itr++)
//         {
//             if (itr->second > maxCountVar.second)
//             {
//                 maxCountVar.first = itr->first;
//                 maxCountVar.second = itr->second;
//             }
//         }

//         return maxCountVar.first;
//     }
// };