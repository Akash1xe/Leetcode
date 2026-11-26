class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Single character is always a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Length of substring
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    int longestPalindrome(string word1, string word2) {

        string s = word1 + word2;

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + m, vector<int>(n + m, 0));

        // Single character
        for (int i = 0; i < n + m; i++) {
            dp[i][i] = 1;
        }

        // LPS tabulation
        for (int len = 2; len <= n + m; len++) {

            for (int i = 0; i + len <= n + m; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        int ans = 0;

        // Ensure palindrome uses both words
        for (int i = 0; i < n; i++) {
            for (int j = n; j < n + m; j++) {

                if (s[i] == s[j]) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};