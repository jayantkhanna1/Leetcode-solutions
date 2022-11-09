
class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.size() <= 1) return vector<vector<int>>{nums};
        vector<vector<int>> result;
        vector<int> tmp(nums.begin()+1, nums.end());
        vector<vector<int>> perms = permuteUnique(tmp);
        for (auto perm : perms)
        {
            for (int i = 0; i <= perm.size(); ++i)
            {
                auto p = perm;
                p.insert(p.begin() + i, nums[0]);
                result.push_back(p);
                if (i < perm.size() and perm[i] == nums[0]) break;
            }
        }
        return result;
    }
};
