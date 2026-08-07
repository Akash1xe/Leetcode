class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Current cell's gold
        int gold = grid[r][c];

        // Mark current cell as visited
        grid[r][c] = 0;

        int best = 0;

        // 4 directions: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            // Check valid cell having gold
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] != 0) {

                best = max(best, dfs(nr, nc, grid));
            }
        }

        // Backtrack:
        // Restore the original gold
        grid[r][c] = gold;

        return gold + best;
    }


    int getMaximumGold(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        // We can start from ANY cell containing gold
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};

/*
INTUITION:

We can start from any cell containing gold.

From every cell:
    1. Collect its gold.
    2. Mark it as 0 so we don't visit it again in
       the current path.
    3. Try all 4 directions.
    4. Take the maximum gold obtained from those directions.
    5. Restore the cell (BACKTRACKING).

Why do we restore the cell?

Because a cell can be used in another path starting
from a different cell.

Example:

    1  0  2
    3  4  5

Suppose DFS starts from 1 and visits 3 -> 4.
After this path finishes, 3 and 4 must become available
again when we start DFS from another cell.

So:

    grid[r][c] = 0       -> mark visited
    DFS(...)
    grid[r][c] = gold    -> backtrack

Pattern:

    DFS + Mark Visited
         ↓
    Explore 4 directions
         ↓
    Take maximum
         ↓
    Restore cell

This is classic BACKTRACKING.

Time Complexity:
O(R * C * 4^K)

where K is the maximum number of gold cells that can
be visited in one path.

Space Complexity:
O(K) recursion stack.
*/