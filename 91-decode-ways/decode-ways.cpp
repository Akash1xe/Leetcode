class Solution {
public:
    int numDecodings(string &s) {
        int n = s.length();

        // dp[i] = number of ways to decode the first i characters
        vector<int> dp(n + 1, 0);

        // Empty string has 1 valid way
        dp[0] = 1;

        // First character cannot be '0'
        dp[1] = (s[0] == '0') ? 0 : 1;

        for (int i = 2; i <= n; i++) {

            // Take current character as a single digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Take current + previous character as a two-digit number
            if (s[i - 2] == '1' ||
                (s[i - 2] == '2' && s[i - 1] < '7')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};