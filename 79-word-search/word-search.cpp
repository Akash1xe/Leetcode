class Solution {
public:

    bool dfs(int row, int col,
             vector<vector<char>>& board,
             string& word,
             int idx) {

        // Entire word matched
        if (idx == word.size())
            return true;

        // Out of bounds
        if (row < 0 || col < 0 ||
            row >= board.size() || col >= board[0].size())
            return false;

        // Current cell must match current character
        if (board[row][col] != word[idx])
            return false;

        // Mark this cell as visited
        char ch = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            dfs(row + 1, col, board, word, idx + 1) ||
            dfs(row - 1, col, board, word, idx + 1) ||
            dfs(row, col + 1, board, word, idx + 1) ||
            dfs(row, col - 1, board, word, idx + 1);

        // Backtrack: restore original character
        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        // Try every cell as starting point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};