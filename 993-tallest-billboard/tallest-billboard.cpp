class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        int n = rods.size();

        int sum = 0;

        for (int x : rods) {
            sum += x;
        }

        int offset = sum;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * sum + 1, -1e9)
        );

        // Base case
        dp[n][offset] = 0;

        // Bottom-up
        for (int i = n - 1; i >= 0; i--) {

            for (int diff = -sum; diff <= sum; diff++) {

                int idx = diff + offset;

                // Don't take the rod
                int nothing = dp[i + 1][idx];

                // Put rod in first support
                int in_rod_1 = -1e9;

                if (diff + rods[i] <= sum) {
                    in_rod_1 =
                        rods[i] +
                        dp[i + 1][idx + rods[i]];
                }

                // Put rod in second support
                int not_in_rod_1 = -1e9;

                if (diff - rods[i] >= -sum) {
                    not_in_rod_1 =
                        rods[i] +
                        dp[i + 1][idx - rods[i]];
                }

                dp[i][idx] =
                    max({nothing, in_rod_1, not_in_rod_1});
            }
        }

        return dp[0][offset] / 2;
    }
};