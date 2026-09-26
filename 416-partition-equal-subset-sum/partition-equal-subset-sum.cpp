class Solution {
public:

    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {

        // If target becomes 0, subset is found
        if (target == 0) {
            return true;
        }

        // Only first element is left
        if (ind == 0) {
            return nums[0] == target;
        }

        // Already calculated
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        // Case 1: Do not take current element
        bool notTake = solve(ind - 1, target, nums, dp);

        // Case 2: Take current element
        bool take = false;

        if (nums[ind] <= target) {
            take = solve(ind - 1, target - nums[ind], nums, dp);
        }

        // Store and return answer
        return dp[ind][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // Odd total cannot be split equally
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        // dp[ind][target]
        // -1 = not calculated
        //  0 = false
        //  1 = true
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, nums, dp);
    }
};