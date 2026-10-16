class Solution {
public:
    int m;
    int n;

    int solve(int i, int j, vector<vector<int>>& dungeon,
              vector<vector<int>>& dp) {
        if (i >= m || j >= n) {
            return 1e9;
        }

        if (i == m - 1 && j == n - 1) {
            if (dungeon[i][j] > 0) {
                return 1;
            }

            return abs(dungeon[i][j]) + 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, dungeon, dp);
        int down = solve(i + 1, j, dungeon, dp);

        int result = min(right, down) - dungeon[i][j];

        return dp[i][j] = max(1, result);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, dungeon, dp);
    }
};