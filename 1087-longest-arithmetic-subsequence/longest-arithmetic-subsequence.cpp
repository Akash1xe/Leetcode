class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        int ans = 2;

        // curr goes backwards because
        // dp[prev][curr] depends on dp[curr][next]
        for (int curr = n - 2; curr >= 0; curr--) {

            for (int prev = curr - 1;
                 prev >= 0;
                 prev--) {

                int diff = nums[curr] - nums[prev];

                for (int next = curr + 1;
                     next < n;
                     next++) {

                    if (nums[next] - nums[curr] == diff) {

                        dp[prev][curr] = max(
                            dp[prev][curr],
                            1 + dp[curr][next]
                        );
                    }
                }

                ans = max(
                    ans,
                    2 + dp[prev][curr]
                );
            }
        }

        return ans;
    }
};