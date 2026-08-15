class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {

        // 1. Find the largest number
        int maxi = *max_element(nums.begin(), nums.end());

        // 2. points[i] = total money if we take number i
        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        // 3. DP array
        vector<int> dp(maxi + 1, 0);

        // Base cases
        dp[0] = points[0];

        if (maxi >= 1) {
            dp[1] = max(points[0], points[1]);
        }

        // 4. Build DP from left to right
        for (int i = 2; i <= maxi; i++) {

            // Don't take i
            int notTake = dp[i - 1];

            // Take i
            int take = points[i] + dp[i - 2];

            dp[i] = max(take, notTake);
        }

        return dp[maxi];
    }
};