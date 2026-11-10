
class Solution {
public:
    int solve(int i, vector<int>& costs, vector<int>& dp) {

        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = 1; j <= 3; j++) {

            if (i - j >= 0) {
                int jumpCost = costs[i - 1] + j * j;

                ans = min(ans, solve(i - j, costs, dp) + jumpCost);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, -1);

        return solve(n, costs, dp);
    }
};
