class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_sum = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1; 
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) {
                    return sum;
                }
                else if(sum < target) {
                    if(target - sum < min_sum) {
                        min_sum = target - sum;
                        ans = sum;
                    }
                    l++;
                }
                else if(sum > target) {
                    if(sum - target < min_sum) {
                        min_sum = sum - target;
                        ans = sum;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};
