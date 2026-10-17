class Solution {
public:
    int solve(int ind, int target, vector<int>& nums,
              vector<vector<int>>& dp) {

        if (target == 0) {
            return 0;
        }

        if (ind < 0) {
            return -1e9;
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int notPick = solve(ind - 1, target, nums, dp);

        int pick = -1e9;

        if (nums[ind] <= target) {
            pick = 1 + solve(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = max(pick, notPick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int ans = solve(n - 1, target, nums, dp);

        return ans < 0 ? -1 : ans;
    }
};