class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {

        // Base case
        if (i == nums.size())
            return 0;

        // Check memoization
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Option 1: Skip the current element
        int notTake = solve(i + 1, prev, nums, dp);

        // Option 2: Take the current element
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};