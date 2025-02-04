class Solution
{
    public:
    vector<vector < char>> nb;
        bool check(vector<vector < char>> &board, int i, int j, char cmp)
        {
            for (int x = 0; x < board.size(); x++)	//row and column
                if (board[i][x] == cmp or board[x][j] == cmp)
                    return false;
            i = i - (i % 3);
            j = j - (j % 3);
            for (int row = i; row < i + 3; row++)	//3x3 small matrix
            {
                for (int col = j; col < j + 3; col++)
                {
                    if (board[row][col] == cmp)
                        return false;
                }
            }
            return true;
        }
    void sudoku(vector<vector < char>> &board)
    {
        int row = -1;
        int col = -1;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1 and col != -1)
                break;
        }

        if (row == -1 and col == -1)
        {nb=board;return;}

        for (int x = 1; x <= 9; x++)
        {
            if (check(board, row, col, char(48 + x)))
            {
                board[row][col] = char(48 + x);
                sudoku(board);
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector < char>> &board)
    {
        sudoku(board);
        
        board=nb;
    }
};
