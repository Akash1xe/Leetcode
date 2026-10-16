class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                    continue;
                }

                int right = 1e9;
                int down = 1e9;

                if (j + 1 < n) {
                    right = dp[i][j + 1];
                }

                if (i + 1 < m) {
                    down = dp[i + 1][j];
                }

                int result = min(right, down) - dungeon[i][j];

                dp[i][j] = max(1, result);
            }
        }

        return dp[0][0];
    }
};