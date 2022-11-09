
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-1, j = i;
        while (i > 0 and nums[i] <= nums[i-1]) --i;
        --i;
        if (i >= 0)
        {
            while (j >= i and nums[j] <= nums[i]) --j;
            int tmp = nums[i];
            nums[i] = nums[j]; nums[j] = tmp;
        }
        ++i;
        reverse(nums.begin()+i, nums.end());
    }
};
