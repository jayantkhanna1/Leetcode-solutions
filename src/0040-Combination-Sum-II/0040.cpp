
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        _combinationSum(candidates, target, 0, path, res);
        return res;
    }
private:
    void _combinationSum(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& res)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        if (!path.empty() and target < *(path.end() - 1)) return;
        for (unsigned int i = index; i < candidates.size(); ++i)
        {
            if (i > index and candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            _combinationSum(candidates, target - candidates[i], i + 1, path, res);
            path.pop_back();
        }
    }
};
