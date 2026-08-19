class Solution {
public:
    // Recursive helper function with memoization
    // i -> current index in s
    // j -> current index in t
    // dp -> memoization table
    int helper(int i, int j, string &s, string &t,
               vector<vector<int>> &dp) {
        // If we have matched all characters of t
        // then we found one valid subsequence
        if (j == t.size()) return 1;

        // If we have exhausted s but not t
        // then no valid subsequence can be formed
        if (i == s.size()) return 0;

        // If this state has been already computed
        if (dp[i][j] != -1) return dp[i][j];

        // If current characters of s and t match
        if (s[i] == t[j]) {
            // Option 1: take this character and move both indices
            int take = helper(i + 1, j + 1, s, t, dp);

            // Option 2: skip this character of s and move only in s
            int notTake = helper(i + 1, j, s, t, dp);

            // Store result in dp table
            return dp[i][j] = take + notTake;
        } else {
            // If characters do not match, we can only skip s[i]
            return dp[i][j] = helper(i + 1, j, s, t, dp);
        }
    }

    // Main function to count distinct subsequences
    int numDistinct(string s, string t) {
        // Initialize dp table with -1 (uncomputed states)
        vector<vector<int>> dp(s.size(),
                               vector<int>(t.size(), -1));

        // Start recursion from index 0 of s and t
        return helper(0, 0, s, t, dp);
    }
};