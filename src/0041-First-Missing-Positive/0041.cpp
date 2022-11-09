
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 and nums[i] <= nums.size()
                and nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
