class Solution {
public:

    // Returns the area of the island starting from (i, j)
    int dfs(vector<vector<int>>& grid, int i, int j) {

        int m = grid.size();
        int n = grid[0].size();

        // Base Case:
        // If outside the grid or current cell is water/already visited,
        // it contributes 0 area.
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        // Mark current land cell as visited.
        grid[i][j] = 0;

        // Area =
        // Current cell (1)
        // + area from all 4 directions
        return 1
             + dfs(grid, i + 1, j)
             + dfs(grid, i - 1, j)
             + dfs(grid, i, j + 1)
             + dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        // Traverse every cell in the grid.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Found a new island.
                if (grid[i][j] == 1) {

                    // Compute its area and keep the maximum.
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};

/*
Intuition:

1. Traverse every cell in the grid.
2. Whenever we find an unvisited land cell (1),
   start a DFS from it.
3. DFS marks every connected land cell as visited by
   changing it to 0.
4. Each visited land contributes 1 to the island's area.
5. The DFS returns:
      1 + area from all four neighbors.
6. Compare the returned area with the current maximum.
7. Since every cell is visited only once,
   the overall time complexity is O(m × n).
*/