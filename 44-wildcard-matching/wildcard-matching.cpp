class Solution {
public:
    bool solve(int i, int j, string& s, string& p,
               vector<vector<int>>& dp) {

        // Both strings are exhausted
        if (i < 0 && j < 0)
            return true;

        // Pattern is exhausted, but string is not
        if (j < 0)
            return false;

        // String is exhausted, check whether remaining pattern has only '*'
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match or '?' matches any single character
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        // '*' can match empty or one/more characters
        if (p[j] == '*') {
            return dp[i][j] =
                solve(i, j - 1, s, p, dp) ||
                solve(i - 1, j, s, p, dp);
        }

        // Characters do not match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s, p, dp);
    }
};