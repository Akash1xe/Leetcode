
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, 0);

        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Build the DP table
        for (int i = 2; i < n; i++) {

            int oneStep = cost[i] + dp[i - 1];
            int twoStep = cost[i] + dp[i - 2];

            dp[i] = min(oneStep, twoStep);
        }

        // We can start from step 0 or step 1
        return min(dp[n - 1], dp[n - 2]);
    }
};
