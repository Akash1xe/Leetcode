class Solution {
public:
    int M = 1e9 + 7;

    int solve(int n, int absent, int consecutive_late,
              vector<vector<vector<int>>>& dp) {

        if (absent >= 2 || consecutive_late >= 3)
            return 0;

        if (n == 0)
            return 1;

        if (dp[n][absent][consecutive_late] != -1)
            return dp[n][absent][consecutive_late];

        int A = solve(n - 1, absent + 1, 0, dp) % M;
        int L = solve(n - 1, absent, consecutive_late + 1, dp) % M;
        int P = solve(n - 1, absent, 0, dp) % M;

        return dp[n][absent][consecutive_late] =
            ((A + L) % M + P) % M;
    }

    int checkRecord(int n) {

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(n, 0, 0, dp);
    }
};