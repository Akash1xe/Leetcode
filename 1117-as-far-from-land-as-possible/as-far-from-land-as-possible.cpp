class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        // Queue for Multi-Source BFS
        queue<pair<int, int>> q;

        // Directions: Up, Down, Left, Right
        vector<pair<int, int>> dir = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        // ----------------------------------------------------
        // Step 1: Push all land cells into the queue
        // ----------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // ----------------------------------------------------
        // Edge Cases
        // ----------------------------------------------------

        // No land exists
        if (q.empty())
            return -1;

        // Entire grid is land
        if (q.size() == n * n)
            return -1;

        // Distance of current BFS level
        int distance = -1;

        // ----------------------------------------------------
        // Multi-Source BFS
        // ----------------------------------------------------
        while (!q.empty()) {

            int size = q.size();

            // Every BFS level increases distance by 1
            distance++;

            while (size--) {

                auto [x, y] = q.front();
                q.pop();

                // Visit all 4 neighbours
                for (auto [dx, dy] : dir) {

                    int nx = x + dx;
                    int ny = y + dy;

                    // Check boundaries
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    // Skip already visited cells (land or visited water)
                    if (grid[nx][ny] == 1)
                        continue;

                    // Mark water as visited
                    grid[nx][ny] = 1;

                    // Add newly visited water to queue
                    q.push({nx, ny});
                }
            }
        }

        return distance;
    }
};