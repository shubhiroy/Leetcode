
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string longestPalindrome;
        int maxPalinCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if ((right - left + 1) > maxPalinCount)
                {
                    maxPalinCount = right - left + 1;
                    longestPalindrome = s.substr(left, right - left + 1);
                }
                left--, right++;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if ((right - left + 1) > maxPalinCount)
                {
                    maxPalinCount = right - left + 1;
                    longestPalindrome = s.substr(left, right - left + 1);
                }
                left--, right++;
            }
        }
        return longestPalindrome;
    }
};

// TC - O(N3), SC - O(1)
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         string longestPalindrome;
//         int maxPalinCount = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             int palinCount = 0;
//             for (int j = i; j < s.size(); j++)
//             {
//                 if (s[i] == s[j])
//                 {
//                     string subStr = s.substr(i, j - i + 1);
//                     string reversedStr = subStr;
//                     std::reverse(subStr.begin(), subStr.end());
//                     if (subStr == reversedStr)
//                     {
//                         palinCount = (j - i) + 1;
//                     }
//                 }
//             }
//             if (palinCount > maxPalinCount)
//             {
//                 maxPalinCount = palinCount;
//                 longestPalindrome = s.substr(i, palinCount);
//             }
//         }
//         return longestPalindrome;
//     }
// };