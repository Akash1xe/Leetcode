class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int steps, int pos, int arrLen, vector<vector<int>>& dp) {

        // No steps left
        if (steps == 0) {
            return pos == 0;
        }

        if (dp[steps][pos] != -1)
            return dp[steps][pos];

        long long ans = 0;

        // Stay
        ans += solve(steps - 1, pos, arrLen, dp);

        // Move left
        if (pos > 0) {
            ans += solve(steps - 1, pos - 1, arrLen, dp);
        }

        // Move right
        if (pos + 1 < arrLen) {
            ans += solve(steps - 1, pos + 1, arrLen, dp);
        }

        return dp[steps][pos] = ans % MOD;
    }

    int numWays(int steps, int arrLen) {

        arrLen = min(arrLen, steps + 1);

        // DP declared INSIDE main function
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen, -1));

        return solve(steps, 0, arrLen, dp);
    }
};