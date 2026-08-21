class Solution {
public:

    int solve(int n, vector<int>& dp) {

        if (n == 1 || n == 2)
            return n;

        if (n == 3)
            return 5;

        if (dp[n] != -1)
            return dp[n];

        const int M = 1000000007;

        return dp[n] =
            (2LL * solve(n - 1, dp) + solve(n - 3, dp)) % M;
    }

    int numTilings(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};