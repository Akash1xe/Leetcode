class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // dp[ind][buy][cap]
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(k + 1, 0))
        );

        // Base cases:
        // ind == n  -> profit = 0
        // cap == 0  -> profit = 0
        // Already handled by initialization with 0

        for (int ind = n - 1; ind >= 0; ind--) {

            for (int buy = 0; buy <= 1; buy++) {

                for (int cap = 1; cap <= k; cap++) {

                    if (buy == 0) {

                        // Skip OR Buy
                        dp[ind][buy][cap] = max(
                            dp[ind + 1][0][cap],
                            -prices[ind] + dp[ind + 1][1][cap]
                        );

                    }
                    else {

                        // Skip OR Sell
                        dp[ind][buy][cap] = max(
                            dp[ind + 1][1][cap],
                            prices[ind] + dp[ind + 1][0][cap - 1]
                        );
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};