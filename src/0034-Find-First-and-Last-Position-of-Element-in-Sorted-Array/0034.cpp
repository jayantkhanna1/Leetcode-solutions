
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();
        vector<int> result(2, -1);
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target) result[0] = mid;
                r = mid;
            }
            else l = mid + 1;
        }
        l = 0; r = nums.size();
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (nums[mid] > target) r = mid;
            else
            {
                if (nums[mid] == target) result[1] = mid;
                l = mid + 1;
            }
        }
        return result;
    }
};
