class Solution {
public:
   // Function to count number of ways to assign '+' or '-' to reach target
    int findTargetSumWays(vector<int>& nums, int target) {
        // Calculate the total sum of the array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is not achievable (because of sum or parity), return 0
        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) 
            return 0;

        // Our problem reduces to subset sum with sum = (totalSum - target) / 2
        int subsetSum = (totalSum - target) / 2;

        // Initialize memo table with -1
        vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));

        // Call recursive function with memoization
        return countSubsets(nums, nums.size() - 1, subsetSum, dp);
    }

private:
    // Recursive function with memoization
    int countSubsets(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        // Base case: when we are at index 0
        if (ind == 0) {
            // Two scenarios:
            if (target == 0 && nums[0] == 0) return 2; // {pick or not pick 0}
            if (target == 0 || target == nums[0]) return 1; // Either pick or skip
            return 0; // Otherwise no valid way
        }

        // Return if already computed
        if (dp[ind][target] != -1) return dp[ind][target];

        // Exclude current element
        int notPick = countSubsets(nums, ind - 1, target, dp);

        // Include current element if it is <= target
        int pick = 0;
        if (nums[ind] <= target)
            pick = countSubsets(nums, ind - 1, target - nums[ind], dp);

        // Store and return result
        return dp[ind][target] = pick + notPick;
    }
};