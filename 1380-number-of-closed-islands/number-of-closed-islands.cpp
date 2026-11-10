class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        function<void(int, int, bool&)> dfs = [&](int r, int c, bool& closed) {

            // Out of bounds means the island touches the boundary
            if (r < 0 || c < 0 || r >= m || c >= n) {
                closed = false;
                return;
            }

            // Water or already visited
            if (grid[r][c] == 1) {
                return;
            }

            // Mark the land as visited
            grid[r][c] = 1;

            // Explore all four directions
            dfs(r + 1, c, closed);
            dfs(r - 1, c, closed);
            dfs(r, c + 1, closed);
            dfs(r, c - 1, closed);
        };

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    bool closed = true;

                    dfs(i, j, closed);

                    if (closed) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};