class Solution {
public:

    int solve(vector<vector<int>>& dungeon,
              int i,
              int j,
              vector<vector<int>>& dp) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        // Outside the grid
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Destination
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] =
                max(1, 1 - dungeon[i][j]);
        }

        // Minimum health required from right
        int right =
            solve(dungeon, i, j + 1, dp);

        // Minimum health required from down
        int down =
            solve(dungeon, i + 1, j, dp);

        // Choose the better path
        int nextHealth = min(right, down);

        // Health required before current cell
        int requiredHealth =
            nextHealth - dungeon[i][j];

        // Health must always be at least 1
        return dp[i][j] =
            max(1, requiredHealth);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        return solve(dungeon, 0, 0, dp);
    }
};