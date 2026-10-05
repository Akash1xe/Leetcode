class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        if (r < 0 || c < 0)
            return INT_MAX;

        if (dp[r][c] != INT_MAX)
            return dp[r][c];

        // Minimum value from the cells
        // that can be a starting point
        int mn = INT_MAX;

        // Directly above
        if (r > 0) {
            mn = min(mn, grid[r - 1][c]);
            mn = min(mn, solve(r - 1, c, grid, dp));
        }

        // Directly left
        if (c > 0) {
            mn = min(mn, grid[r][c - 1]);
            mn = min(mn, solve(r, c - 1, grid, dp));
        }

        return dp[r][c] = mn;
    }

    int maxScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int ans = INT_MIN;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                int mn = solve(r, c, grid, dp);

                if (mn != INT_MAX) {
                    ans = max(ans, grid[r][c] - mn);
                }
            }
        }

        return ans;
    }
};