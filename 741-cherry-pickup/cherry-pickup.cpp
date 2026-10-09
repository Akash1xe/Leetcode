class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int Func(int r1, int r2, int c1, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || r2 >= n || c1 >= m || c2 < 0 || c2 >= m)
            return -1e9;

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if (r1 == n - 1 && c1 == m - 1)
            return grid[r1][c1];

        if (dp[r1][r2][c1] != -1)
            return dp[r1][r2][c1];

        int cherries = grid[r1][c1];

        if (r1 != r2)
            cherries += grid[r2][c2];

        int next =
            max({Func(r1 + 1, r2 + 1, c1, grid), Func(r1 + 1, r2, c1, grid),
                 Func(r1, r2 + 1, c1 + 1, grid), Func(r1, r2, c1 + 1, grid)});

        return dp[r1][r2][c1] = cherries + next;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(n, vector<int>(m, -1)));

        return max(0, Func(0, 0, 0, grid));
    }
};