class Solution {
public:

    int solve(int ind, vector<string>& strs, int m, int n,
              vector<vector<vector<int>>>& dp) {

        // Base case:
        // No strings left
        if (ind < 0) {
            return 0;
        }

        // Already calculated
        if (dp[ind][m][n] != -1) {
            return dp[ind][m][n];
        }

        // Count zeros and ones in current string
        int zeros = 0;
        int ones = 0;

        for (char ch : strs[ind]) {
            if (ch == '0')
                zeros++;
            else
                ones++;
        }

        // Pick current string
        int pick = 0;

        if (zeros <= m && ones <= n) {
            pick = 1 + solve(
                ind - 1,
                strs,
                m - zeros,
                n - ones,
                dp
            );
        }

        // Don't pick current string
        int notPick = solve(
            ind - 1,
            strs,
            m,
            n,
            dp
        );

        return dp[ind][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int size = strs.size();

        // dp[ind][m][n]
        vector<vector<vector<int>>> dp(
            size,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(size - 1, strs, m, n, dp);
    }
};