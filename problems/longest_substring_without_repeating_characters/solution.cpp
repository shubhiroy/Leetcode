#include <set>
#include <iostream>
#include <iterator>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::set<char> charSet;
        int left = 0, maxLength = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (charSet.find(s[i]) == charSet.end())
            {
                charSet.insert(s[i]);
                if (charSet.size() > maxLength)
                {
                    // std::cout << "Char = " << i << " MS = " << maxLength << std::endl;
                    maxLength = charSet.size();
                }
            }
            else
            {
                while (charSet.count(s[i]))
                {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[i]);
            }
        }
        return maxLength;
    }
};

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int maxSubStringLen = 0;
//         unordered_set<int> charSet;
//         for (int i = 0; i < s.size(); i++)
//         {
//             int subStringLen = 0;
//             for (int j = i; j < s.size(); j++)
//             {
//                 std::cout << int(s[i]) << std::endl;
//                 if (charSet.find(int(s[j])) == charSet.end())
//                 {
//                     charSet.insert(int(s[j]));
//                     subStringLen += 1;
//                     // std::cout << "Char = " << s[j] << " sub len = " << subStringLen << std::endl;
//                 }
//                 else
//                 {
//                     if (subStringLen > maxSubStringLen)
//                     {
//                         maxSubStringLen = subStringLen;
//                     }
//                     charSet.clear();
//                     break;
//                 }
//             }
//         }
//         return maxSubStringLen;
//     }
// };