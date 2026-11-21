class Solution {
public:
    int lcs(int i, int j, string &str1, string &str2,
            vector<vector<int>> &dp) {

        // Base case
        if (i == 0 || j == 0)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (str1[i-1] == str2[j-1]) {
            return dp[i][j] = 1 + lcs(i-1, j-1, str1, str2, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            lcs(i-1, j, str1, str2, dp),
            lcs(i, j-1, str1, str2, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        // Calculate LCS using memoization
        lcs(n, m, str1, str2, dp);

        string ans = "";

        int i = n;
        int j = m;

        // Backtracking to construct SCS
        while (i > 0 && j > 0) {

            if (str1[i-1] == str2[j-1]) {

                ans += str1[i-1];

                i--;
                j--;
            }
            else if (lcs(i-1, j, str1, str2, dp) >
                     lcs(i, j-1, str1, str2, dp)) {

                ans += str1[i-1];
                i--;
            }
            else {

                ans += str2[j-1];
                j--;
            }
        }

        // Remaining characters of str1
        while (i > 0) {
            ans += str1[i-1];
            i--;
        }

        // Remaining characters of str2
        while (j > 0) {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};