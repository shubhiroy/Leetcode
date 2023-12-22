#include <unordered_map>
#include <string>
class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::unordered_map<char, int> elementMap;
        for (int i = 0; i < s.size(); i++)
        {
            elementMap[s[i]]++;
        }
        sort(
            s.begin(), s.end(), [&](char a, char b)
            {
        if (elementMap[a] != elementMap[b]) {
            return elementMap[a] > elementMap[b];
        } else {
            return a < b;
        } });
        return s;
    }
};