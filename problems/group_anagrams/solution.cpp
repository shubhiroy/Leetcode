class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anaMap;
        for (int i = 0; i < strs.size(); i++)
        {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            anaMap[sortedString].push_back(strs[i]);
        }
        vector<vector<string>> anaList;
        for (auto pair : anaMap)
        {
            anaList.push_back(pair.second);
        }
        return anaList;
    }
};