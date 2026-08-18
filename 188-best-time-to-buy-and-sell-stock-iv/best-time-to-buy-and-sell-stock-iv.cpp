class Solution {
public:

    int solve(vector<int>& prices, int ind, int buy, int cap,
              vector<vector<vector<int>>>& dp) {

        int n = prices.size();

        // No days left or no transactions left
        if (ind == n || cap == 0)
            return 0;

        // Already calculated
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit;

        if (buy == 0) {
            // Buy or skip
            profit = max(
                solve(prices, ind + 1, 0, cap, dp),
                -prices[ind] + solve(prices, ind + 1, 1, cap, dp)
            );
        }
        else {
            // Sell or skip
            profit = max(
                solve(prices, ind + 1, 1, cap, dp),
                prices[ind] + solve(prices, ind + 1, 0, cap - 1, dp)
            );
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solve(prices, 0, 0, k, dp);
    }
};