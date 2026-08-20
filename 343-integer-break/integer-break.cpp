class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n + 1, 0);

        // Base case
        dp[1] = 1;

        for (int num = 2; num <= n; num++) {

            for (int i = 1; i <= num - 1; i++) {

                int product = i * max(num - i, dp[num - i]);

                dp[num] = max(dp[num], product);
            }
        }

        return dp[n];
    }
};