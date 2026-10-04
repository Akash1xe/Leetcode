class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill from top to bottom
        for (int i = 1; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int u = dp[i - 1][j];

                int ld = 1e8;
                if (j - 1 >= 0)
                    ld = dp[i - 1][j - 1];

                int rd = 1e8;
                if (j + 1 < m)
                    rd = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min(u, min(ld, rd));
            }
        }

        // Answer can be anywhere in last row
        int mini = 1e8;

        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};