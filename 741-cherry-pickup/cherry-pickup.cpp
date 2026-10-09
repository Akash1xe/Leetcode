class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, -1e9)));

        for (int r1 = n - 1; r1 >= 0; r1--) {
            for (int r2 = n - 1; r2 >= 0; r2--) {
                for (int c1 = m - 1; c1 >= 0; c1--) {
                    int c2 = r1 + c1 - r2;

                    if (c2 < 0 || c2 >= m)
                        continue;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        continue;

                    // Base case
                    if (r1 == n - 1 && c1 == m - 1) {
                        dp[r1][r2][c1] = grid[r1][c1];
                        continue;
                    }

                    int cherries = grid[r1][c1];

                    if (r1 != r2 || c1 != c2)
                        cherries += grid[r2][c2];

                    int next = max({
                        dp[r1 + 1][r2 + 1][c1], 
                        dp[r1 + 1][r2][c1],     
                        dp[r1][r2 + 1][c1 + 1],
                        dp[r1][r2][c1 + 1]      
                    });

                    dp[r1][r2][c1] = cherries + next;
                }
            }
        }

        return max(0, dp[0][0][0]);
    }
};