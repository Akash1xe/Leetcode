class Solution {
    int solve(int row, int col1, int col2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (col1 < 0 || col1 >= cols ||
            col2 < 0 || col2 >= cols) {
            return -1000000000;
        }

        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }

        int cherries = grid[row][col1];
        if (col1 != col2) {
            cherries += grid[row][col2];
        }

        if (row == rows - 1) {
            return dp[row][col1][col2] = cherries;
        }

        int bestNext = -1000000000;

        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                bestNext = max(bestNext,
                    solve(row + 1, col1 + move1,
                          col2 + move2, grid, dp));
            }
        }

        return dp[row][col1][col2] = cherries + bestNext;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(
            rows,
            vector<vector<int>>(cols, vector<int>(cols, -1))
        );

        return solve(0, 0, cols - 1, grid, dp);
    }
};