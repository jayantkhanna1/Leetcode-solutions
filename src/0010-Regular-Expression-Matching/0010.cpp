class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.length(), n = p.length(); 
        deque<deque<bool>> mem(m + 1, deque<bool> (n + 1, false));
        mem[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                    mem[i][j] = (j > 1 && mem[i][j - 2]) || 
                    ((i > 0 && j > 1 && s[i - 1] == p[j - 2]) || 
                    (j > 1 && p[j - 2] == '.')) && i > 0 && mem[i - 1][j];
                else mem[i][j] = (i > 0 && mem[i - 1][j - 1]) && 
                    ((i > 0 && s[i - 1] == p[j - 1]) || p[j - 1] == '.');
            }
        }
        return mem[m][n];
    }
};
