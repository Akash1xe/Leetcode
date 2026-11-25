class Solution {
public:
    int solve(int i, int j, string& s1, string& s2,
              vector<vector<int>>& dp) {

        // Base case: one string is exhausted
        if (i < 0 || j < 0)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        }

        // Characters do not match
        return dp[i][j] = max(
            solve(i - 1, j, s1, s2, dp),
            solve(i, j - 1, s1, s2, dp)
        );
    }

    int lcs(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s1, s2, dp);
    }

    int minInsertions(string s) {
        string t = s;

        reverse(t.begin(), t.end());

        // Longest Palindromic Subsequence
        int lps = lcs(s, t);

        // Minimum insertions = length - LPS
        return s.length() - lps;
    }
};