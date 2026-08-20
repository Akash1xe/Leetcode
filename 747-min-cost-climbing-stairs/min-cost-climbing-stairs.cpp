class Solution {
public:

    int solve(int n, vector<int>& cost, vector<int>& dp) {

        // Base cases
        if (n == 0)
            return cost[0];

        if (n == 1)
            return cost[1];

        // Already calculated
        if (dp[n] != -1)
            return dp[n];

        // Come to n from n-1
        int oneStep = cost[n] + solve(n - 1, cost, dp);

        // Come to n from n-2
        int twoStep = cost[n] + solve(n - 2, cost, dp);

        return dp[n] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, -1);

        // We can start from step 0 or step 1.
        // The top is after the last index.
        return min(solve(n - 1, cost, dp),
                   solve(n - 2, cost, dp));
    }
};