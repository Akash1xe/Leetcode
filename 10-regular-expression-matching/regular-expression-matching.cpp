class Solution {
public:
    int solve(int i, int j, string& s, string& p,
              vector<vector<int>>& dp) {

        // Both are exhausted
        if (i == 0 && j == 0)
            return true;

        // Pattern is exhausted
        if (j == 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        // If current pattern character is '*'
        if (p[j - 1] == '*') {

            // Case 1: '*' matches zero occurrences
            bool zero = solve(i, j - 2, s, p, dp);

            // Case 2: '*' matches one or more occurrences
            bool one = false;

            if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
                one = solve(i - 1, j, s, p, dp);
            }

            return dp[i][j] = zero || one;
        }

        // Normal character or '.'
        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(n, m, s, p, dp);
    }
};