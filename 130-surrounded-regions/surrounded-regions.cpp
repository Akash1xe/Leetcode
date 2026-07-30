class Solution {
private:
    // DFS to mark boundary-connected 'O's as visited
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& board,
             int delrow[], int delcol[]) {

        // mark current cell visited
        vis[row][col] = 1;

        // cache dimensions
        int n = board.size(), m = board[0].size();

        // try all 4 directions
        for (int k = 0; k < 4; k++) {

            // compute next cell
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            // check bounds and unvisited 'O'
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {

                // continue DFS
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        // handle empty board
        if (board.empty() || board[0].empty()) return;

        int n = board.size();
        int m = board[0].size();

        // direction arrays
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first and last row
        for (int j = 0; j < m; j++) {

            // top row
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board, delrow, delcol);

            // bottom row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board, delrow, delcol);
        }

        // traverse first and last column
        for (int i = 0; i < n; i++) {

            // left column
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, delrow, delcol);

            // right column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, delrow, delcol);
        }

        // flip all unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // enclosed region
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};