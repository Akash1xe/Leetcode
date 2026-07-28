class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Stores the answer (distance to nearest 0)
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Keeps track of visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Queue stores: {{row, col}, distance}
        queue<pair<pair<int, int>, int>> q;

        // Push all 0's into the queue because they are
        // the starting points (sources) with distance 0.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        // 4 possible directions
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // Standard BFS
        while (!q.empty()) {

            // Current cell
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            // Store the shortest distance
            ans[row][col] = dist;

            // Visit all 4 neighbours
            for (int k = 0; k < 4; k++) {

                int newRow = row + dr[k];
                int newCol = col + dc[k];

                // If neighbour is inside the grid and not visited
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol]) {

                    // Mark visited
                    vis[newRow][newCol] = 1;

                    // Push neighbour with distance +1
                    q.push({{newRow, newCol}, dist + 1});
                }
            }
        }

        return ans;
    }
};