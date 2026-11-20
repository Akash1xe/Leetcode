class Solution {
public:
    int solve(int i, int j, string &text1, string &text2,
              vector<vector<int>> &dp) {

        // Base case: one string is exhausted
        if (i < 0 || j < 0) {
            return 0;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            solve(i - 1, j, text1, text2, dp),
            solve(i, j - 1, text1, text2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, text1, text2, dp);
    }
};