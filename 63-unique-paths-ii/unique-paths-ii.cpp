class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {

        // Outside the grid
        if (i < 0 || j < 0)
            return 0;

        // If current cell is an obstacle
        if (obstacleGrid[i][j] == 1)
            return 0;

        // Reached starting cell
        if (i == 0 && j == 0)
            return 1;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move up
        int up = solve(i - 1, j, obstacleGrid, dp);

        // Move left
        int left = solve(i, j - 1, obstacleGrid, dp);

        // Store the answer
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // dp[i][j] stores number of paths from (i,j) to (0,0)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start from bottom-right
        return solve(n - 1, m - 1, obstacleGrid, dp);
    }
};