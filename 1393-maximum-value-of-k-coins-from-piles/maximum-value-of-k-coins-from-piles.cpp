// MIK Solution — Bottom-Up DP / Tabulation

class Solution {
public:

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();

        // dp[i][j] = maximum value we can get
        // using the first i piles by taking exactly j coins.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Process piles one by one.
        for (int i = 1; i <= n; i++) {

            // We can take at most k coins.
            for (int j = 0; j <= k; j++) {

                // Option 1: Don't take any coin
                // from the current pile.
                //
                // dp[i-1][j] means:
                // use first i-1 piles and take j coins.
                dp[i][j] = dp[i - 1][j];

                int sum = 0;

                // Option 2: Take 1, 2, 3, ...
                // coins from the current pile.
                for (int x = 1;
                     x <= min((int)piles[i - 1].size(), j);
                     x++) {

                    // Add value of the x-th coin.
                    sum += piles[i - 1][x - 1];

                    // Take x coins from current pile.
                    // Remaining j-x coins come from previous piles.
                    dp[i][j] = max(
                        dp[i][j],
                        sum + dp[i - 1][j - x]
                    );
                }
            }
        }

        // Using all n piles and taking k coins.
        return dp[n][k];
    }
};