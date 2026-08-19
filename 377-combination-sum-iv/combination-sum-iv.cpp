class Solution {
public:
    int solve(int target, vector<int>& nums, int n,vector<int>& dp) {
        if (target == 0) {
            return 1;
        }

        if (target < 0) {
            return 0;
        }

        if(dp[target]!=-1){
            return dp[target];
        }

        int ways = 0;

        for (int i = 0; i < n; i++) {

            ways += solve(target - nums[i], nums, n,dp);
        }

        return dp[target]= ways;
    }

    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> dp(target+1,-1);
        return solve(target, nums, n,dp);
    }
};