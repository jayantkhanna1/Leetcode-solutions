
class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        unsigned int n = matrix.size();
        for(unsigned int i = 0; i < n/2; ++i)
        {
            for(unsigned int j = i; j < n - 1 - i; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
