class Solution {
public:

    const int mod = 1e9 + 7;

    int solve(int n, int k, int target, vector<vector<int>>& dp) {

        // All dice are used
        if (n == 0) {
            return target == 0;
        }

        // Target is impossible
        if (target <= 0) {
            return 0;
        }

        // Already calculated
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        long long ans = 0;

        // Try every possible face
        for (int face = 1; face <= k; face++) {

            ans = (ans + solve(n - 1, k, target - face, dp)) % mod;
        }

        return dp[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(n, k, target, dp);
    }
};