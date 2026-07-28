class Solution {
public:
    int n, m;

    // DFS to count all connected land cells
    int dfs(vector<vector<int>>& grid, int r, int c) {

        // Base Case
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return 0;

        // Mark current cell as visited
        grid[r][c] = 0;

        int count = 1;

        // 4 directions
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            count += dfs(grid, r + dr[i], c + dc[i]);
        }

        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int totalLand = 0;

        // First pass: Count all land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    totalLand++;
            }
        }

        int borderLand = 0;

        // Second pass: Run DFS only from border land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 &&
                    (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {

                    borderLand += dfs(grid, i, j);
                }
            }
        }

        // Enclaves = Total land - Border connected land
        return totalLand - borderLand;
    }
};