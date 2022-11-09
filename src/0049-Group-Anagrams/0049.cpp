
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string> > group;
        for (auto& s : strs) 
        {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto& m : group) res.push_back(m.second);
        return res;
    }
};
