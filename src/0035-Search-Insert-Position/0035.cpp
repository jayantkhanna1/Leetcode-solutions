
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (target > nums[mid]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
