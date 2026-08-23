// MIK Solution — Recursion + Memoization
class Solution {
public:

    int n;

    // solve(i, k) = maximum value we can get
    // using piles from index i onwards
    // when we still need to take k coins.
    int solve(int i, vector<vector<int>>& piles, int k,
              vector<vector<int>>& dp) {

        // No more piles left.
        if (i >= n)
            return 0;

        // If this state is already calculated,
        // return the stored answer.
        if (dp[i][k] != -1)
            return dp[i][k];

        // Option 1: Do not take any coin from the current pile.
        // Move directly to the next pile.
        int not_taken = solve(i + 1, piles, k, dp);

        int taken = 0;
        int sum = 0;

        // Option 2: Take coins from the current pile.
        // We can take at most k coins from this pile.
        for (int j = 0; j < min((int)piles[i].size(), k); j++) {

            // Add the value of the next coin.
            sum += piles[i][j];

            // Take (j + 1) coins from the current pile
            // and solve the remaining problem.
            taken = max(
                taken,
                sum + solve(i + 1, piles, k - (j + 1), dp)
            );
        }

        // Store and return the best of:
        // 1. Not taking from current pile
        // 2. Taking 1, 2, 3, ... coins from current pile
        return dp[i][k] = max(taken, not_taken);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        // Number of piles.
        n = piles.size();

        // dp[i][k] represents the answer for:
        // current pile = i
        // remaining coins = k
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Start from the first pile with k coins available.
        return solve(0, piles, k, dp);
    }
};