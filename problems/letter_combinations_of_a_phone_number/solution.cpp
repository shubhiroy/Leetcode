#include <unordered_map>
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, vector<char>> numpad;
        numpad['2'] = {'a', 'b', 'c'};
        numpad['3'] = {'d', 'e', 'f'};
        numpad['4'] = {'g', 'h', 'i'};
        numpad['5'] = {'j', 'k', 'l'};
        numpad['6'] = {'m', 'n', 'o'};
        numpad['7'] = {'p', 'q', 'r', 's'};
        numpad['8'] = {'t', 'u', 'v'};
        numpad['9'] = {'w', 'x', 'y', 'z'};

        const char *charArray = digits.c_str();
        vector<string> res;
        getMappings(charArray, 0, digits.size(), "", numpad, res);

        return res;
    }

    void getMappings(const char *charArr, int pos, int size, string curr, unordered_map<char, vector<char>> numpad, vector<string> &res)
    {
        if (pos == size - 1)
        {
            for (int i = 0; i < numpad[charArr[pos]].size(); i++)
            {
                string temp = curr + numpad[charArr[pos]][i];
                res.push_back(temp);
            }
            return;
        }
        for (int i = 0; i < numpad[charArr[pos]].size(); i++)
        {
            string temp = curr + numpad[charArr[pos]][i];
            getMappings(charArr, pos + 1, size, temp, numpad, res);
        }
    }
};