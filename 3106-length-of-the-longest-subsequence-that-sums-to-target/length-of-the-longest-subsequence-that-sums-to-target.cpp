class Solution {
public:

    int f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {

        if(ind == 0) {
            if(target == 0) return 0;
            if(nums[0] == target) return 1;
            return -1e9;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        // Not take
        int notTake = f(ind - 1, target, nums, dp);

        // Take
        int take = -1e9;

        if(nums[ind] <= target) {
            take = 1 + f(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int ans = f(n - 1, target, nums, dp);

        return ans < 0 ? -1 : ans;
    }
};