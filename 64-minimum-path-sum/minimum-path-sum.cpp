class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j] = minimum path sum to reach (i,j)
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Starting cell
        dp[0][0] = grid[0][0];

        // Fill the table
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Starting cell already initialized
                if (i == 0 && j == 0)
                    continue;

                int up = INT_MAX;
                int left = INT_MAX;

                // Come from UP
                if (i > 0)
                    up = dp[i - 1][j];

                // Come from LEFT
                if (j > 0)
                    left = dp[i][j - 1];

                // Current cell + minimum previous path
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }

        // Answer is bottom-right cell
        return dp[n - 1][m - 1];
    }
};