class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int n, int A, int L, vector<vector<vector<int>>>& dp) {

        if (n == 0)
            return 1;

        if (dp[n][A][L] != -1)
            return dp[n][A][L];

        long long ans = 0;

        // P
        ans += solve(n - 1, A, 0, dp);

        // A
        if (A == 0)
            ans += solve(n - 1, 1, 0, dp);

        // L
        if (L < 2)
            ans += solve(n - 1, A, L + 1, dp);

        return dp[n][A][L] = ans % MOD;
    }

    int checkRecord(int n) {

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(n, 0, 0, dp);
    }
};