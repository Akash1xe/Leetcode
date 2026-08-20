class Solution {
public:

    bool solve(int i, int j, string &s, vector<vector<int>> &dp) {

        // Single character
        if (i >= j)
            return true;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // First and last characters must match
        if (s[i] == s[j]) {
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int start = 0;
        int maxLen = 1;

        // Try every possible substring
        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (solve(i, j, s, dp)) {

                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};