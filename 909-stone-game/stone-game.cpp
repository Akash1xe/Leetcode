class Solution {
public:
    int solve(vector<int>& piles, int left, int right,
              vector<vector<int>>& dp) {

        // Only one pile remains
        if (left == right) {
            return piles[left];
        }

        // Already calculated
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        // Take the left pile
        int takeLeft =
            piles[left] - solve(piles, left + 1, right, dp);

        // Take the right pile
        int takeRight =
            piles[right] - solve(piles, left, right - 1, dp);

        // Store and return the best difference
        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        // dp[left][right] = maximum score difference
        // current player can achieve from left...right
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(piles, 0, n - 1, dp) > 0;
    }
};