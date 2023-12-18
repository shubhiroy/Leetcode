
// Optimal, Just skip the identical values
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // std::set<vector<int>> finalResult;
        vector<vector<int>> finalResult;
        std::sort(candidates.begin(), candidates.end());
        combinationSet(candidates, target, 0, target, vector<int>(), finalResult);
        return vector<vector<int>>(finalResult.begin(), finalResult.end());
    }

    // void combinationSet(const vector<int> candidates, int target, int pos, int rem, vector<int> currSet, std::set<vector<int>> &finalResult)
    void combinationSet(const vector<int> candidates, int target, int pos, int rem, vector<int> currSet, vector<vector<int>> &finalResult)
    {
        if (rem == 0)
        {
            // finalResult.insert(currSet);
            finalResult.push_back(currSet);
            return;
        }

        if (pos == candidates.size() || rem < candidates[pos])
        {
            return;
        }

        int nextInd = pos + 1;
        while (nextInd < candidates.size() && candidates[pos] == candidates[nextInd])
        {
            nextInd++;
        }
        combinationSet(candidates, target, nextInd, rem, currSet, finalResult);
        currSet.push_back(candidates[pos]);
        combinationSet(candidates, target, pos + 1, (rem - candidates[pos]), currSet, finalResult);
        currSet.pop_back();
    }
};

// Brute force, Error - TLE
// class Solution
// {
// public:
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         std::set<vector<int>> finalResult;
//         std::sort(candidates.begin(), candidates.end());
//         combinationSet(candidates, target, 0, target, vector<int>(), finalResult);
//         return vector<vector<int>>(finalResult.begin(), finalResult.end());
//     }

//     void combinationSet(const vector<int> candidates, int target, int pos, int rem, vector<int> currSet, std::set<vector<int>> &finalResult)
//     {
//         if (rem == 0)
//         {
//             finalResult.insert(currSet);
//             return;
//         }

//         if (pos == candidates.size() || rem < candidates[pos])
//         {
//             return;
//         }

//         combinationSet(candidates, target, pos + 1, rem, currSet, finalResult);
//         currSet.push_back(candidates[pos]);
//         combinationSet(candidates, target, pos + 1, (rem - candidates[pos]), currSet, finalResult);
//         currSet.pop_back();
//     }
// };