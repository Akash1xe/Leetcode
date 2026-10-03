class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

       
        for (int j = 0; j < m; j++) {
            dp[0][j] = grid[0][j];
        }

        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < m; j++) {

                int choosen = grid[i][j];

                for (int k = 0; k < m; k++) {

                    int pick =
                        dp[i][j]
                        + moveCost[choosen][k]
                        + grid[i + 1][k];

                    dp[i + 1][k] =
                        min(dp[i + 1][k], pick);
                }
            }
        }

        int ans = 1e9;

        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};