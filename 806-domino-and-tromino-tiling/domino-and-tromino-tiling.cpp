class Solution {
public:

// code with mik 
    int numTilings(int n) {

        const int M = 1000000007;

        vector<int> dp(n + 1, -1);

        // Base cases
        if (n == 1 || n == 2)
            return n;

        if (n == 3)
            return 5;

        // dp[n] = 2 * dp[n-1] + dp[n-3]
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] + dp[i - 3]) % M;
        }

        return dp[n];
    }
};