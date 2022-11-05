class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l = 0;
        int r = height.size() - 1;
        int contain = 0;
        while (l < r)
        {
            contain = max(contain, (r - l)* min(height[l], height[r]));
            if (height[l] > height[r]) --r;
            else ++l;
        }
        return contain;
    }
};
