class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //answer vector
        vector<vector<int>> ans;
        int n = nums.size();
        // if the size of the given vector is small then we cannot find 4 sum so return a void vector
        if(n<4) return ans;
        
        //sort the vector to apply the pointers method
        sort(begin(nums), end(nums));
        // selection of the first candidate
        for(int i=0;i<n;i++){
            // this step will help in by-passing the interger overflow
            long long nt1 = (long long) target - (long long)nums[i];
            for(int j=i+1;j<n;j++){
                //same here!
                long long nt2 = nt1 - (long long)nums[j];
                
                int s = j+1, e = n-1;
                while(s<e){
                    //now as usual apply the two-pointers method to find the quad
                    long long cur_sum = nums[s]+nums[e];
                    if(cur_sum < nt2) s++;
                    else if(cur_sum > nt2) e--;
                    else{
                        
                        vector<int> q(4, 0);
                        q[0] = nums[i];
                        q[1] = nums[j];
                        q[2] = nums[s];
                        q[3] = nums[e];
                        
                        ans.push_back(q);
                        
                        // to avoid duplication of 3rd element
                        while(s<e and nums[s]==q[2]) s++;
                        
                        // to avoid duplication of 4th element
                        while(s<e and nums[e]==q[3]) e--;
                    }
                }
                // to avoid the duplication of second element
                while(j+1 < n and nums[j+1]==nums[j]) ++j;
            }
            // to avoid the duplication of first element
            while(i+1 < n and nums[i+1]==nums[i]) ++i;
        }
        
        return ans;
    }
};
