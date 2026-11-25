class Solution {
public:
    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {

        // If word1 is exhausted, insert remaining characters of word2
        if (i < 0)
            return j + 1;

        // If word2 is exhausted, delete remaining characters of word1
        if (j < 0)
            return i + 1;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }

        // Characters do not match: Insert, Delete, or Replace
        int insert = solve(i, j - 1, word1, word2, dp);

        int deleteChar = solve(i - 1, j, word1, word2, dp);

        int replace = solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = 1 + min({insert, deleteChar, replace});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, word1, word2, dp);
    }
};