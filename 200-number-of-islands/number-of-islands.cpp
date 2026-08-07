class Solution {
public:

    // DFS to visit the complete island
    void dfs(vector<vector<char>>& grid, int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        // If we go outside the grid, stop
        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        // If this cell is water or already visited, stop
        if (grid[row][col] == '0')
            return;

        // Mark this land cell as visited
        // We don't need a separate visited array.
        // Changing '1' to '0' acts as our visited marking.
        grid[row][col] = '0';

        // Direction arrays:
        //       Up
        //       (-1, 0)
        //
        // Left  (0, -1)  Current  (0, +1)  Right
        //
        //       Down
        //       (+1, 0)
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Explore all 4 neighbouring cells
        for (int k = 0; k < 4; k++) {

            int nr = row + dr[k];
            int nc = col + dc[k];

            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        // Traverse every cell of the grid
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // If we find an unvisited land cell,
                // we have found a new island.
                if (grid[i][j] == '1') {

                    islands++;

                    // Visit the complete connected component
                    // and mark all its cells as '0'.
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};


/*
===========================================================
INTUITION
===========================================================

Every island is a connected component of land cells ('1').

We scan the entire grid.

Whenever we find a '1', it means:

    "This is a land cell that has not been visited yet."

Therefore, we have discovered a NEW island.

So:

    islands++;

Then we run DFS from that cell.

DFS visits every connected '1' belonging to that island.

Instead of creating a separate visited[][] array,
we modify the input grid itself.

We change:

    '1' -> '0'

This means:

    '1' = unvisited land
    '0' = water OR already visited land

Therefore, if DFS reaches the same cell again,
it sees '0' and immediately returns.

This prevents visiting the same cell repeatedly
and prevents counting the same island more than once.


===========================================================
WHY DO WE USE dr[] AND dc[]?
===========================================================

A cell has 4 possible neighbours:

        (row-1, col)
              ↑

(row, col-1) ← (row,col) → (row, col+1)

              ↓
        (row+1, col)

We store these four directions as:

    dr = { 1, -1,  0,  0 }
    dc = { 0,  0,  1, -1 }

For every direction:

    nr = row + dr[k]
    nc = col + dc[k]

This allows us to explore all 4 neighbours
using one simple loop instead of writing
four separate DFS calls.


===========================================================
ALGORITHM
===========================================================

1. Traverse every cell in the grid.

2. If grid[i][j] == '1':
       - We found a new island.
       - Increment islands.
       - Start DFS from this cell.

3. In DFS:
       - Stop if the cell is outside the grid.
       - Stop if the cell is '0'.
       - Change '1' to '0' to mark it visited.
       - Explore all 4 directions.

4. Continue scanning the grid.

5. Return the total number of islands.


===========================================================
TIME COMPLEXITY
===========================================================

O(m * n)

Each cell is visited at most once.

Once a cell is changed from '1' to '0',
we never process it again.


===========================================================
SPACE COMPLEXITY
===========================================================

O(m * n) in the worst case.

We do not use a separate visited array,
but the recursive DFS call stack can contain
O(m * n) calls if the entire grid is one large island.


===========================================================
KEY PATTERN TO REMEMBER
===========================================================

Grid DFS without a visited array:

    if (invalid || grid[row][col] == '0')
        return;

    grid[row][col] = '0';

    for (int k = 0; k < 4; k++) {
        int nr = row + dr[k];
        int nc = col + dc[k];

        dfs(grid, nr, nc);
    }

The important trick is:

    grid[row][col] = '0';

The grid itself is being used to keep track
of visited cells.
===========================================================
*/