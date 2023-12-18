class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> finalResult;
        std::sort(candidates.begin(), candidates.end());
        combinationSet(candidates, target, 0, target, vector<int>(), finalResult);
        return finalResult;
    }

    void combinationSet(const vector<int> candidates, int target, int pos, int rem, vector<int> currSet, vector<vector<int>> &finalResult)
    {
        if (rem == 0)
        {
            finalResult.push_back(currSet);
            return;
        }

        if (pos == candidates.size() || rem < candidates[pos])
        {
            return;
        }

        combinationSet(candidates, target, pos + 1, rem, currSet, finalResult);
        currSet.push_back(candidates[pos]);
        combinationSet(candidates, target, pos, (rem - candidates[pos]), currSet, finalResult);
        currSet.pop_back();
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         set<vector<int>> finalResult;
//         for (int i = 0; i < candidates.size(); i++)
//         {
//             combinationSet(vector<int>(candidates.begin() + i, candidates.end()), vector<int>(), finalResult, 0, target);
//         }
//         return vector<vector<int>>(finalResult.begin(), finalResult.end());
//     }
//     void combinationSet(const vector<int> candidates, vector<int> result, set<vector<int>> &finalResult, int sum, int target)
//     {
//         if (sum > target)
//             return;

//         if (sum == target)
//         {
//             finalResult.insert(result);
//             return;
//         }

//         for (int i = 0; i < candidates.size(); i++)
//         {
//             vector<int> newResult(result);
//             newResult.push_back(candidates[i]);
//             int newSum = sum + candidates[i];
//             combinationSet(vector<int>(candidates.begin() + i, candidates.end()), newResult, finalResult, newSum, target);
//         }
//     }
// };