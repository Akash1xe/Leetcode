class Solution {
public:

    // DFS to remove the entire island
    void dfs(vector<vector<char>>& grid, int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        // Water or already visited
        if (grid[row][col] == '0')
            return;

        // Mark current land as visited
        grid[row][col] = '0';

        // Visit all 4 directions
        dfs(grid, row + 1, col); // Down
        dfs(grid, row - 1, col); // Up
        dfs(grid, row, col + 1); // Right
        dfs(grid, row, col - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        // Traverse every cell
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Found a new island
                if (grid[i][j] == '1') {

                    islands++;

                    // Remove the whole island
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};

/*
Intuition:
-----------
Every island is a connected component of land ('1').

Whenever we encounter a '1' while scanning the grid,
we have found a completely new island.

Increase the answer by one and perform DFS.

DFS visits every connected land cell and converts it
into water ('0'), ensuring the same island is never
counted again.

Time Complexity:
O(m × n)

Each cell is visited at most once.

Space Complexity:
O(m × n) in the worst case because of the recursion stack
(if the entire grid is one large island).
*/