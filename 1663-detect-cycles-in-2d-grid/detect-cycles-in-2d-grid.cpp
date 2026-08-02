class Solution {
public:
    int n, m;

    // DFS function
    // row, col -> current cell
    // parentRow, parentCol -> cell from which we came
    bool dfs(int row, int col, int parentRow, int parentCol,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        // Mark the current cell as visited
        vis[row][col] = 1;

        // 4 possible directions (Up, Right, Down, Left)
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Traverse all 4 neighbours
        for (int k = 0; k < 4; k++) {

            int nr = row + dr[k];
            int nc = col + dc[k];

            // Check if neighbour is inside the grid
            // and has the same character
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == grid[row][col]) {

                // If neighbour is not visited,
                // continue DFS from there
                if (!vis[nr][nc]) {

                    // If a cycle is found in deeper recursion,
                    // immediately return true
                    if (dfs(nr, nc, row, col, grid, vis))
                        return true;
                }

                // Neighbour is already visited
                else {

                    // If the neighbour is NOT the parent,
                    // then we have found another path
                    // to an already visited node.
                    // This forms a cycle.
                    if (nr != parentRow || nc != parentCol)
                        return true;
                }
            }
        }

        // No cycle found from this path
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Visited matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse every cell because
        // the graph may have multiple disconnected components
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Start DFS only if the cell is unvisited
                if (!vis[i][j]) {

                    // If any DFS finds a cycle,
                    // return true immediately
                    if (dfs(i, j, -1, -1, grid, vis))
                        return true;
                }
            }
        }

        // No cycle exists anywhere in the grid
        return false;
    }
};