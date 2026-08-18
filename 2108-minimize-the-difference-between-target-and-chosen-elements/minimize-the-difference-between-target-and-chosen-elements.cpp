class Solution {
public:
    int solve(int row, int sum, vector<vector<int>>& mat,
              int target, vector<vector<int>>& dp) {

        // All rows processed
        if (row == mat.size()) {
            return abs(sum - target);
        }

        if (dp[row][sum] != -1) {
            return dp[row][sum];
        }

        int ans = INT_MAX;

        // Pick one element from current row
        for (int col = 0; col < mat[row].size(); col++) {

            int pick = solve(
                row + 1,
                sum + mat[row][col],
                mat,
                target,
                dp
            );

            ans = min(ans, pick);
        }

        return dp[row][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        int n = mat.size();

        // Maximum possible sum
        int maxSum = 0;

        for (int i = 0; i < n; i++) {
            maxSum += *max_element(mat[i].begin(), mat[i].end());
        }

        vector<vector<int>> dp(
            n,
            vector<int>(maxSum + 1, -1)
        );

        return solve(0, 0, mat, target, dp);
    }
};