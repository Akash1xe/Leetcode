class Solution {
public:
    bool solve(string& s1, string& s2, string& target,
               int n, int m, vector<vector<int>>& dp) {

        int k = n + m;

        // All characters of target are used
        if (k == target.size()) {
            return true;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        bool take1 = false;
        bool take2 = false;

        // Take from s1
        if (n < s1.size() && s1[n] == target[k]) {
            take1 = solve(s1, s2, target, n + 1, m, dp);
        }

        // Take from s2
        if (m < s2.size() && s2[m] == target[k]) {
            take2 = solve(s1, s2, target, n, m + 1, dp);
        }

        return dp[n][m] = take1 || take2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }
};