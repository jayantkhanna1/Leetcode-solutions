class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        string x_str = to_string(x);
        return equal(x_str.begin(), x_str.begin() + x_str.size()/2, x_str.rbegin());
    }
};
