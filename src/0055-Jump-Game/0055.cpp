
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int m = 0;
        for (uint i = 0; i < nums.size(); ++i)
        {
            if (i > m) return false;
            if (m < i + nums[i]) m = i + nums[i];
        }
        return true;
    }
};
