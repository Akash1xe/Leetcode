class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        // Base case: reached (0,0)
        if (i == 0 && j == 0)
            return grid[0][0];

        // Outside the grid
        if (i < 0 || j < 0)
            return INT_MAX;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move UP
        int up = solve(i - 1, j, grid, dp);

        // Move LEFT
        int left = solve(i, j - 1, grid, dp);

        // Store and return minimum path sum
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j] stores minimum path sum
        // from (i,j) to (0,0)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start from bottom-right
        return solve(n - 1, m - 1, grid, dp);
    }
};