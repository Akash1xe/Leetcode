class Solution {
public:
    int solve(vector<int>& rods, int i, int diff,
              vector<vector<int>>& dp, int offset) {

        int n = rods.size();

        if (i == n) {
            if (diff == 0)
                return 0;

            return -1e9;
        }

        if (dp[i][diff + offset] != -1)
            return dp[i][diff + offset];

        int nothing = solve(rods, i + 1, diff, dp, offset);

        int in_rod_1 = rods[i] +
                       solve(rods, i + 1, diff + rods[i], dp, offset);

        int not_in_rod1 = rods[i] +
                          solve(rods, i + 1, diff - rods[i], dp, offset);

        return dp[i][diff + offset] =
               max({nothing, in_rod_1, not_in_rod1});
    }

    int tallestBillboard(vector<int>& rods) {

        int n = rods.size();

        int total_sum = accumulate(rods.begin(), rods.end(), 0);

        vector<vector<int>> dp(
            n,
            vector<int>(2 * total_sum + 1, -1)
        );

        return solve(rods, 0, 0, dp, total_sum) / 2;
    }
};