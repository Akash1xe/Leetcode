class Solution {
public:

    int Lac(int i, int j, string &s1, string &s2,
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
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + Lac(i-1, j-1, s1, s2, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            Lac(i-1, j, s1, s2, dp),
            Lac(i, j-1, s1, s2, dp)
        );
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return Lac(n-1, n-1, s, t, dp);
    }
};