class Solution {
public:
    int func(vector<int>& nums, int i, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];

        int ans = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                ans = max(ans, 1 + func(nums, j, dp));
            }
        }
        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, func(nums, i, dp));
        }
        return ans;
    }
};