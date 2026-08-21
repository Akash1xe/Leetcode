class Solution {
public:
    int n, target;
    vector<int> dp;

    bool solve(vector<int>& nums, int mask, int currSum, int k) {

        // Only one bucket left
        if (k == 1)
            return true;

        // Already calculated
        if (dp[mask] != -1)
            return dp[mask];

        // Current bucket is complete
        if (currSum == target) {
            return dp[mask] = solve(nums, mask, 0, k - 1);
        }

        // Try every number
        for (int i = 0; i < n; i++) {

            // Already used
            if (mask & (1 << i))
                continue;

            // Bucket cannot exceed target
            if (currSum + nums[i] > target)
                continue;

            // Pick nums[i]
            if (solve(nums,
                      mask | (1 << i),
                      currSum + nums[i],
                      k))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        // Cannot divide equally
        if (sum % k != 0)
            return false;

        target = sum / k;

        // Largest number cannot be bigger than target
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        dp.assign(1 << n, -1);

        return solve(nums, 0, 0, k);
    }
};