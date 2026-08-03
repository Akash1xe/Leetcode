class Solution {
public:
    int n, m;

    // 4-direction movement
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // DFS to mark the first island
    // Also push every island cell into the queue
    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             queue<pair<int, int>>& q)
    {
        // Mark current cell as visited
        visited[row][col] = 1;

        // Add it to BFS queue
        q.push({row, col});

        // Visit all 4 neighbours
        for (int k = 0; k < 4; k++)
        {
            int nx = row + dx[k];
            int ny = col + dy[k];

            // Check boundary
            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                !visited[nx][ny] &&
                grid[nx][ny] == 1)
            {
                dfs(nx, ny, grid, visited, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // Visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Queue for Multi-source BFS
        queue<pair<int, int>> q;

        // Used to stop after finding the first island
        bool found = false;

        // Find the first island
        for (int i = 0; i < n && !found; i++)
        {
            for (int j = 0; j < m && !found; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Mark the whole first island
                    // and store all its cells in queue
                    dfs(i, j, grid, visited, q);

                    // Stop searching for more islands
                    found = true;
                }
            }
        }

        // Number of water cells crossed
        int distance = 0;

        // Multi-source BFS
        while (!q.empty())
        {
            int sz = q.size();

            // Process one BFS level
            while (sz--)
            {
                auto [row, col] = q.front();
                q.pop();

                // Explore all 4 neighbours
                for (int k = 0; k < 4; k++)
                {
                    int nx = row + dx[k];
                    int ny = col + dy[k];

                    // Ignore out of boundary cells
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    // Skip already visited cells
                    if (visited[nx][ny])
                        continue;

                    // Reached the second island
                    if (grid[nx][ny] == 1)
                        return distance;

                    // Mark water cell visited
                    visited[nx][ny] = 1;

                    // Continue BFS from this water cell
                    q.push({nx, ny});
                }
            }

            // Completed one BFS layer
            // Increase bridge length
            distance++;
        }

        return -1;
    }
};