class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        // If total sum is odd, equal partition is impossible
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        // dp[ind][sum] = can we make 'sum'
        // using elements from index 0 to ind
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Sum 0 can always be formed by taking nothing
        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = true;
        }

        // Using only nums[0], we can form nums[0]
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // Build table
        for (int ind = 1; ind < n; ind++) {

            for (int sum = 1; sum <= target; sum++) {

                // Do not take nums[ind]
                bool notTake = dp[ind - 1][sum];

                // Take nums[ind]
                bool take = false;

                if (nums[ind] <= sum) {
                    take = dp[ind - 1][sum - nums[ind]];
                }

                dp[ind][sum] = (take || notTake);
            }
        }

        return dp[n - 1][target];
    }
};