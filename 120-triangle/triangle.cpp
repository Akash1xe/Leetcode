class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Traverse from bottom to top
        for (int i = n - 1; i >= 0; i--) {

            for (int j = 0; j <= i; j++) {

                // Base case: last row
                if (i == n - 1) {
                    dp[i][j] = triangle[i][j];
                }
                else {

                    int down = dp[i + 1][j];
                    int diag = dp[i + 1][j + 1];

                    dp[i][j] = triangle[i][j] + min(down, diag);
                }
            }
        }

        return dp[0][0];
    }
};